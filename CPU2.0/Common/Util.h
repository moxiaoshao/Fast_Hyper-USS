#ifndef UTIL_H
#define UTIL_H

#include <emmintrin.h>
#include <x86intrin.h>

#include <algorithm>
#include <chrono>
#include <cstring>
#include <functional>
#include <sstream>
#include <vector>

#include "hash.h"
#include "murmurhash.h"

#pragma pack(1)

#define AVERAGE

// #define SKEW

// #define FAIRNESS

// number of keys
#define TUPLES_NUM 4

// number of values
// Notice: ifdef AVERAGE: TUPLES_VALUES_ELEMENT_NUM needs + 1
#define TUPLES_VALUES_ELEMENT_NUM 5

// number of subset test
#define SUBSETS_NUM 1000

// size of test subset
#define SUBSETS_SIZE_ALPHA 0.2






struct TUPLES_ID {
  uint32_t key[TUPLES_NUM];

  TUPLES_ID() { memset(key, 0, sizeof(uint32_t) * TUPLES_NUM); }

  bool operator==(const TUPLES_ID &a) const {
    return memcmp(key, a.key, sizeof(key)) == 0;
  }

  bool operator<(const TUPLES_ID &a) const {
    return memcmp(key, a.key, sizeof(key)) < 0;
  }
};

struct TUPLES_VALUE {
  double values[TUPLES_VALUES_ELEMENT_NUM];

  TUPLES_VALUE() {
    memset(values, 0, sizeof(double) * TUPLES_VALUES_ELEMENT_NUM);
  }

  void operator+=(const TUPLES_VALUE &a) {
    for (int i = 0; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
        values[i] += a.values[i];
    }
  }

  bool operator==(const TUPLES_VALUE &a) const {
    return memcmp(values, a.values, sizeof(values)) == 0;
  }

  bool empty() const {
    for (int i = 0; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
      if (values[i] != 0) {
        return false;
      }
    }
    return true;
  }

  double sum_squares() const{
    double sum_value = 0;
    for (int i = 0; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
      sum_value += values[i]*values[i];
    }
    
    return sum_value;
}


  void divide(double divisor) {
    for (int i = 0; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
        values[i] /= divisor;
    }
  }

  TUPLES_VALUE normalize(const TUPLES_VALUE &a) const {
    TUPLES_VALUE ret;
    for (int i = 0; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
      ret.values[i] = (a.values[i] == 0) ? 0 : values[i] / a.values[i];
    }
    return ret;
  }
};

struct TUPLES {
  TUPLES_ID id;
  TUPLES_VALUE value;
};

struct TUPLES_PREC : TUPLES {
  double precmod = 0;
  bool ismod = false;
};



struct TUPLES_VALUE_SIMD : TUPLES_VALUE {

  void operator=(const TUPLES_VALUE &a) {
    int num_iterations = TUPLES_VALUES_ELEMENT_NUM / 4;
    for (int i = 0; i < num_iterations; ++i) {
        __m256d vec = _mm256_loadu_pd(&a.values[i*4]);
        _mm256_storeu_pd(&values[i*4], vec);
    }
    for (int i = num_iterations * 4; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
        values[i] = a.values[i];
    }
  }

  void operator+=(const TUPLES_VALUE &a) {
    // Calculate the number of iterations needed for SIMD operations
    int num_iterations = TUPLES_VALUES_ELEMENT_NUM / 4; // Each __m256 can process 4 doubles

    // Perform SIMD addition
    for (int i = 0; i < num_iterations; ++i) {
        // Load 4 doubles from values[i] and a.values[i] into SSE registers
        __m256d vec_values = _mm256_loadu_pd(&values[i*4]);
        __m256d vec_a_values = _mm256_loadu_pd(&a.values[i*4]);

        // Perform SIMD addition
        __m256d result = _mm256_add_pd(vec_values, vec_a_values);

        // Store the result back to values[i]
        _mm256_storeu_pd(&values[i*4], result);
    }

    // Perform scalar addition for any remaining elements if TUPLES_VALUES_ELEMENT_NUM is not a multiple of 4
    for (int i = num_iterations * 4; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
        values[i] += a.values[i];
    }
  }

  void divide(double divisor) {
    int num_iterations = TUPLES_VALUES_ELEMENT_NUM / 4;
    __m256d div = _mm256_set1_pd(divisor);

    for (int i = 0; i < num_iterations; ++i) {
        __m256d vecValues = _mm256_loadu_pd(&values[i*4]);
        __m256d result = _mm256_div_pd(vecValues, div);
        _mm256_storeu_pd(&values[i*4], result);
    }

    for (int i = num_iterations * 4; i < TUPLES_VALUES_ELEMENT_NUM; ++i) {
        values[i] /= divisor;
    }
  }
};

struct TUPLES_SIMD {
  TUPLES_ID id;
  TUPLES_VALUE_SIMD value;
  double precmod = 0;
  bool ismod = false;
};


namespace std {
template <>
struct hash<TUPLES_ID> {
  size_t operator()(const TUPLES_ID &item) const noexcept {
    return Hash::BOBHash32((uint8_t *)&item, sizeof(TUPLES_ID), 0);
  }
};
}  // namespace std

typedef std::chrono::high_resolution_clock::time_point TP;

inline TP now() { return std::chrono::high_resolution_clock::now(); }

inline double durationms(TP finish, TP start) {
  return std::chrono::duration_cast<
             std::chrono::duration<double, std::ratio<1, 1000000>>>(finish -
                                                                    start)
      .count();
}

template <typename T>
T Median(std::vector<T> vec, uint32_t len) {
  std::sort(vec.begin(), vec.end());
  return (len & 1) ? vec[len >> 1]
                   : (vec[len >> 1] + vec[(len >> 1) - 1]) / 2.0;
}

template <typename T>
T Mean(std::vector<T> vec) {
  return (double)accumulate(vec.begin(), vec.end(), 0) / (double)vec.size();
}

#endif

