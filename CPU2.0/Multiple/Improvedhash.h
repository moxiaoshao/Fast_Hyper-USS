#ifndef IMPROVEDHASH_H
#define IMPROVEDHASH_H

#include <cstring>
#include <random>
#include <unordered_map>

#include "Util.h"

typedef std::unordered_map<TUPLES_ID, TUPLES_VALUE> HashMap;

class OurHyper_murmurhash {	
 public:
  OurHyper_murmurhash(uint32_t _MEMORY, uint32_t _HASH_NUM = 2,
           std::string _name = "OurHyper_murmurhash") {
    this->name = _name;

    HASH_NUM = _HASH_NUM;

    LENGTH = _MEMORY / (_HASH_NUM) / sizeof(TUPLES_PREC);

    counter = new TUPLES_PREC *[HASH_NUM];

    for (uint32_t i = 0; i < HASH_NUM; ++i) {
      counter[i] = new TUPLES_PREC[LENGTH];
      memset(counter[i], 0, sizeof(TUPLES_PREC) * LENGTH);
    }
  }

  ~OurHyper_murmurhash() {
    for (uint32_t i = 0; i < HASH_NUM; ++i) {
      delete[] counter[i];
    }
    delete[] counter;
  }

  void Insert(const TUPLES &item) {
    double minimum = std::numeric_limits<double>::infinity();
    uint32_t minPos, minHash;

#ifdef FAIRNESS
    S += item.value;
#endif

    uint32_t position = murmurhash(item.id, 0) % LENGTH;
    for (uint32_t i = 0; i < HASH_NUM; ++i) {
      if (counter[i][position].id == item.id) {
        counter[i][position].value += item.value;
	counter[i][position].ismod = false;
        return;
      }

      if (counter[i][position].precmod < minimum) {
        minPos = position;
        minHash = i;
        minimum = counter[i][position].precmod;
      }
    }

    if (not counter[minHash][minPos].ismod) {
#ifdef FAIRNESS
      counter[minHash][minPos].precmod = sqrt(counter[minHash][minPos].value.normalize(S).sum_squares());  
#else
      counter[minHash][minPos].precmod = sqrt(counter[minHash][minPos].value.sum_squares());
#endif
      counter[minHash][minPos].ismod = true;
    }

#ifdef FAIRNESS
    double sqrt1 = sqrt(item.value.normalize(S).sum_squares());
    double sqrt2 = counter[minHash][minPos].precmod;
#else
    double sqrt1 = sqrt(item.value.sum_squares());
    double sqrt2 = counter[minHash][minPos].precmod;
#endif

    if (sqrt1 + sqrt2 != 0) {
      double prob = sqrt1 / (sqrt1 + sqrt2);
      static std::mt19937 e2(rd());
      std::uniform_real_distribution<> dist(0, 1);

      if (dist(e2) < prob) {
        counter[minHash][minPos].id = item.id;
        counter[minHash][minPos].value = item.value;
        counter[minHash][minPos].value.divide(prob);
	counter[minHash][minPos].precmod = sqrt1 + sqrt2;
      } else {
        counter[minHash][minPos].value.divide(1 - prob);
	counter[minHash][minPos].precmod = sqrt1 + sqrt2;
      }
    }
  }

  HashMap AllQuery() {
    HashMap ret;

    uint32_t empty = 0;

    for (uint32_t i = 0; i < HASH_NUM; ++i) {
      for (uint32_t j = 0; j < LENGTH; ++j) {
        if (counter[i][j].id == TUPLES_ID() && counter[i][j].value.empty()) {
          ++empty;
        } else {
          ret[counter[i][j].id] += counter[i][j].value;
        }
      }
    }

    return ret;
  }

 private:
  std::string name;
  uint32_t LENGTH;
  uint32_t HASH_NUM;

  TUPLES_PREC **counter;

#ifdef FAIRNESS
  TUPLES_VALUE S = TUPLES_VALUE();
#endif
};

#endif
