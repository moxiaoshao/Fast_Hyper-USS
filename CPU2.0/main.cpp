#include "BenchMark.h"
#include "BenchMark_HeavyChange.h"
#include "BenchMark_Synthetic.h"
#include "BenchMark_test_dnum.h"
#include "BenchMark_SNMP.h"


int main(int argc, char *argv[]) {
  // SNMP
  uint32_t memory_set[4] = {1000 * 1000 * 10, 1000 * 1000 * 50, 1000 * 1000 * 100, 1000 * 1000 * 200};
  for (uint32_t i = 1; i < argc; ++i) {
    std::cout << "SNMP dataset: " << argv[i] << std::endl;
    BenchMark_SNMP dataset(argv[i], "SNMP");
    // dataset.HHHyperBench(1000 * 1000 * 500, 0.000001);
    // dataset.HHSingleBench(1000 * 1000 * 500, 0.000001);
    // dataset.HHUSSBench(1000 * 1000 * 500, 0.000001);
    for (uint32_t j = 0; j < 4; ++j) {
      std::cout << "Memory: " << memory_set[j] << std::endl;
      dataset.HHHyperBench(memory_set[j], 0.000001, 2);
      dataset.HHSingleBench(memory_set[j], 0.000001);
      dataset.HHUSSBench(memory_set[j], 0.000001);
    }
    std::ofstream ofs;
    ofs.open("SNMP_RangeQuery.txt", std::ios::app);
    ofs << "SNMP " << argv[i] << std::endl;
    ofs.close();
  }

  return 0;
}


// int main(int argc, char *argv[]) {
//   // example
// //  for (uint32_t i = 1; i < argc; ++i) {
// //    std::cout << "example dataset: " << argv[i] << std::endl;
// //    BenchMark_Synthetic dataset(argv[i], "example");
// //    dataset.HHHyperBench_precalculate(1000 * 1000);
// //    dataset.HHHyperBench(1000 * 1000);
// //    dataset.HHSingleBench(1000 * 1000);
// //    dataset.HHUSSBench(1000 * 1000);
// //  }

// int repeat = 1;


// // experiments:

// // exp1_1
// /*
 
//      std::cout << "exp1.1.1 dataset: " << "../../data/Synthetic/Hyper_zipf_1.500_4K32V.txt" << std::endl;
//      BenchMark_Synthetic dataset("../../data/Synthetic/Hyper_zipf_1.500_4K32V.txt", "exp1.1.1.avg");
//      for (int j = 10; j <= 100; j += 10) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j,4);
//          dataset.HHHyperBench_murmurhash(1000 * j,4);
//          dataset.HHHyperBench_precalculate(1000 * j);
//          dataset.HHHyperBench(1000 * j);
//          dataset.HHSingleBench(1000 * j);
//          dataset.HHUSSBench(1000 * j);
//        }
//      }
//      for (int j = 200; j <= 1000; j += 100) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j,4);
//          dataset.HHHyperBench_murmurhash(1000 * j,4);
//          dataset.HHHyperBench_precalculate(1000 * j);
//          dataset.HHHyperBench(1000 * j);
//          dataset.HHSingleBench(1000 * j);
//          dataset.HHUSSBench(1000 * j);
//        }
//      }



//      std::cout << "exp1.1.2 dataset: " << "../../data/Synthetic/Hyper_zipf_1.500_4K4V.txt" << std::endl;
//      BenchMark_Synthetic dataset("../../data/Synthetic/Hyper_zipf_1.500_4K4V.txt", "exp1.1.2.avg");
//      for (int j = 10; j <= 100; j += 10) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j,4);
//          dataset.HHHyperBench_murmurhash(1000 * j,4);
//          dataset.HHHyperBench_precalculate(1000 * j);
//          dataset.HHHyperBench(1000 * j);
//          dataset.HHSingleBench(1000 * j);
//          dataset.HHUSSBench(1000 * j);
//        }
//      }
//      for (int j = 200; j <= 1000; j += 100) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j,4);
//          dataset.HHHyperBench_murmurhash(1000 * j,4);
//          dataset.HHHyperBench_precalculate(1000 * j);
//          dataset.HHHyperBench(1000 * j);
//          dataset.HHSingleBench(1000 * j);
//          dataset.HHUSSBench(1000 * j);
//        }
//      }
   

// //exp1_2
// //dataset:Criteo
//      std::cout << "exp1.2.1 dataset: " << "../../data/Criteo/50m_4K14V" << std::endl;
//      BenchMark dataset("../../data/Criteo/50m_4K14V", "exp1.2.1.avg_5");
//      for (int j = 10; j <= 100; j += 10) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_murmurhash(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_precalculate(1000 * j, 0.000001);
//          dataset.HHHyperBench(1000 * j, 0.000001);
//          dataset.HHSingleBench(1000 * j, 0.000001);
//          dataset.HHUSSBench(1000 * j, 0.000001);
//        }
//      }
//      for (int j = 200; j <= 1000; j += 100) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_murmurhash(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_precalculate(1000 * j, 0.000001);
//          dataset.HHHyperBench(1000 * j, 0.000001);
//          dataset.HHSingleBench(1000 * j, 0.000001);
//          dataset.HHUSSBench(1000 * j, 0.000001);
//        }
//      }
// */
// //exp1_2
// //dataset:Criteo
//      std::cout << "exp1.2.2 dataset: " << "../../data/Criteo/50m_4K4V" << std::endl;
//      BenchMark dataset("../../data/Criteo/50m_4K4V", "exp1.2.2.avg_5");
//      for (int j = 10; j <= 100; j += 10) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_murmurhash(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_precalculate(1000 * j, 0.000001);
//          dataset.HHHyperBench(1000 * j, 0.000001);
//          dataset.HHSingleBench(1000 * j, 0.000001);
//          dataset.HHUSSBench(1000 * j, 0.000001);
//        }
//      }
//      for (int j = 200; j <= 1000; j += 100) {
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_murmurhash(1000 * j, 0.000001,4);
//          dataset.HHHyperBench_precalculate(1000 * j, 0.000001);
//          dataset.HHHyperBench(1000 * j, 0.000001);
//          dataset.HHSingleBench(1000 * j, 0.000001);
//          dataset.HHUSSBench(1000 * j, 0.000001);
//        }
//      }


// /*
// // exp3_1

// int keys = 20;
//      std::cout << "exp3.1 dataset: " << "../../data/Synthetic/Hyper_zipf_1.500_" << std::to_string(keys) << "K32V.txt"  << std::endl;
//      BenchMark_Synthetic dataset("../../data/Synthetic/Hyper_zipf_1.500_" + std::to_string(keys) + "K32V.txt", "exp3.1_" + std::to_string(keys) + "K");
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(50000,4);
//          dataset.HHHyperBench_murmurhash(50000,4);
//          dataset.HHHyperBench_precalculate(50000);
//          dataset.HHHyperBench(50000);
//          dataset.HHSingleBench(50000);
//          dataset.HHUSSBench(50000);
// 	 dataset.HHHyperBench_simd(100000,4);
//          dataset.HHHyperBench_murmurhash(100000,4);
//          dataset.HHHyperBench_precalculate(100000);
//          dataset.HHHyperBench(100000);
//          dataset.HHSingleBench(100000);
//          dataset.HHUSSBench(100000);
// 	 dataset.HHHyperBench_simd(200000,4);
//          dataset.HHHyperBench_murmurhash(200000,4);
//          dataset.HHHyperBench_precalculate(200000);
//          dataset.HHHyperBench(200000);
//          dataset.HHSingleBench(200000);
//          dataset.HHUSSBench(200000);
//        }




// // exp3_2

// int values = 64;
//      std::cout << "exp3.2 dataset: " << "../../data/Synthetic/Hyper_zipf_1.500_4K" << std::to_string(values) << "V.txt"  << std::endl;
//      BenchMark_Synthetic dataset("../../data/Synthetic/Hyper_zipf_1.500_4K" + std::to_string(values) + "V.txt", "exp3.2_" + std::to_string(values) + "V");
//        for (uint32_t n = 0; n < repeat; ++n) {
//          dataset.HHHyperBench_simd(50000,4);
//          dataset.HHHyperBench_murmurhash(50000,4);
//          dataset.HHHyperBench_precalculate(50000);
//          dataset.HHHyperBench(50000);
//          dataset.HHSingleBench(50000);
//          dataset.HHUSSBench(50000);
//          dataset.HHHyperBench_simd(100000,4);
//          dataset.HHHyperBench_murmurhash(100000,4);
//          dataset.HHHyperBench_precalculate(100000);
//          dataset.HHHyperBench(100000);
//          dataset.HHSingleBench(100000);
//          dataset.HHUSSBench(100000);
//          dataset.HHHyperBench_simd(200000,4);
//          dataset.HHHyperBench_murmurhash(200000,4);
//          dataset.HHHyperBench_precalculate(200000);
//          dataset.HHHyperBench(200000);
//          dataset.HHSingleBench(200000);
//          dataset.HHUSSBench(200000);
//        }



// // exp3_3
// std::cout << "exp3.3 dataset: " << "../../data/Synthetic/Hyper_zipf_1.500_4K32V.txt" << std::endl;
//      BenchMark_test_dnum dataset("../../data/Synthetic/Hyper_zipf_1.500_4K32V.txt", "exp3.3");
//      std::ofstream ofs;
//      ofs.open("exp3.3.txt", std::ios::app);
//      for (uint32_t n = 0; n < repeat; ++n) {
//        for (uint32_t h = 1; h <= 16; h *= 2) {
// 	 dataset.HHHyperBench_simd(10000,h);
//          dataset.HHHyperBench_murmurhash(10000,h);
// 	 dataset.HHHyperBench_precalculate(10000,h);
//          dataset.HHHyperBench(10000,h);
//          dataset.HHHyperBench_simd(30000,h);
//          dataset.HHHyperBench_murmurhash(30000,h);
// 	 dataset.HHHyperBench_precalculate(30000,h);
//          dataset.HHHyperBench(30000,h);
//          dataset.HHHyperBench_simd(100000,h);
//          dataset.HHHyperBench_murmurhash(100000,h);
// 	 dataset.HHHyperBench_precalculate(100000,h);
//          dataset.HHHyperBench(100000,h);
//          dataset.HHHyperBench_simd(300000,h);
//          dataset.HHHyperBench_murmurhash(300000,h);
// 	 dataset.HHHyperBench_precalculate(300000,h);
//          dataset.HHHyperBench(300000,h);
//          dataset.HHHyperBench_simd(1000000,h);
//          dataset.HHHyperBench_murmurhash(1000000,h);
// 	 dataset.HHHyperBench_precalculate(1000000,h);
//          dataset.HHHyperBench(1000000,h);
//        }
//      }

// */


//   // exp3b
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp1a dataset: " << argv[i] << std::endl;
// //     BenchMark_Synthetic dataset(argv[i], "exp1a");
// //     for (int j = 10; j <= 100; j += 10) {
// //       dataset.HHHyperBench_murmurhash(1000 * j,2);
// //       dataset.HHHyperBench_murmurhash(1000 * j,3);
// //       dataset.HHHyperBench_murmurhash(1000 * j,4);
// //       dataset.HHHyperBench_murmurhash(1000 * j,5);
// //       dataset.HHSingleBench(1000 * j);
// //       dataset.HHUSSBench(1000 * j);
// //     }
// //   }

// // exp1b
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp1b dataset: " << argv[i] << std::endl;
// //     BenchMark_Synthetic dataset(argv[i], "exp1b");
// //     for (int j = 300; j <= 700; j += 100) {
// //       dataset.HHHyperBench(1000 * j);
// //       dataset.HHSingleBench(1000 * j);
// //       dataset.HHUSSBench(1000 * j);
// //     }
// //   }

// // exp1c
// //   int i = 25;
// //   std::string path =
// //       "../data/Synthetic/Hyper_zipf_1.500_5K" + std::to_string(i) +
// //       "V.txt";
// //   std::cout << "exp1c dataset: " << path << std::endl;
// //   BenchMark_Synthetic dataset(path, "exp1c");
// //   dataset.HHHyperBench(1000 * 500);
// //   dataset.HHSingleBench(1000 * 500);
// //   dataset.HHUSSBench(1000 * 500);


// // exp1d
// //   int i = 25;
// //   std::string path =
// //       "../data/Synthetic/Hyper_zipf_1.500_" + std::to_string(i) +
// //       "K5V.txt";
// //   std::cout << "exp1d dataset: " << path << std::endl;
// //   BenchMark_Synthetic dataset(path, "exp1d");
// //   dataset.HHHyperBench(1000 * 500);
// //   dataset.HHSingleBench(1000 * 500);
// //   dataset.HHUSSBench(1000 * 500);

// // exp1e
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp1e dataset: " << argv[i] << std::endl;
// //    BenchMark_Synthetic dataset(argv[i], "exp1e");
// //     for (int j = 1; j <= 5; j += 1) {
// //       dataset.HHHyperBench(1000 * 500, j);
// //     }
// //   }

// // exp1f
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp1f dataset: " << argv[i] << std::endl;
// //     BenchMark_Synthetic dataset(argv[i], "exp1f");
// //     for (int j = 800; j <= 1200; j += 100) {
// //       dataset.HHHyperBench(1000 * j);
// //       dataset.HHSingleBench(1000 * j);
// //       dataset.HHUSSBench(1000 * j);
// //     }
// //   }

// // exp1g
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp1g dataset: " << argv[i] << std::endl;
// //     BenchMark_Synthetic dataset(argv[i], "exp1g");
// //     for (int j = 800; j <= 1200; j += 100) {
// //       dataset.HHHyperBench(1000 * j);
// //       dataset.HHSingleBench(1000 * j);
// //       dataset.HHUSSBench(1000 * j);
// //     }
// //   }

// // exp2a
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp2a dataset: " << argv[i] << std::endl;
// //     BenchMark dataset(argv[i], "exp2a");
// //     for (int j = 300; j <= 700; j += 100) {
// //       dataset.HHHyperBench(1000 * j, 0.000001);
// //       dataset.HHSingleBench(1000 * j, 0.000001);
// //       dataset.HHUSSBench(1000 * j, 0.000001);
// //     }
// //   }

// // exp2b
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp2b dataset: " << argv[i] << std::endl;
// //     BenchMark dataset(argv[i], "exp2b");
// //     for (int j = 300; j <= 700; j += 100) {
// //       dataset.HHHyperBench(1000 * j, 0.000001);
// //       dataset.HHSingleBench(1000 * j, 0.000001);
// //       dataset.HHUSSBench(1000 * j, 0.000001);
// //     }
// //   }

// // exp2c skew_factor = 1e5
// // for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "exp2c dataset: " << argv[i] << std::endl;
// //     BenchMark dataset(argv[i], "exp2c_1e5", 1e5);
// //     for (int k = 0; k < 1000; ++k) {
// //       dataset.HHHyperBench(1000 * 500, 0.000001);
// //     }
// //   }

// // revision: NBA
// // for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "revision dataset: " << argv[i] << std::endl;
// //     BenchMark dataset(argv[i], "revision_NBA");
// //     for (uint32_t j = 300; j <= 700; j += 100) {
// //       dataset.HHHyperBench(100000 * j, 0.000001);
// //       dataset.HHSingleBench(100000 * j, 0.000001);
// //       dataset.HHUSSBench(100000 * j, 0.000001);
// //     }
// //   }

// // revision: CAIDA
// // for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "revision dataset: " << argv[i] << std::endl;
// //     BenchMark dataset(argv[i], "revision_CAIDA_FAIR");
// //     for (uint32_t k = 0; k < 100; ++k) {
// //       dataset.HHHyperBench(100000 * 500, 0.000001);
// //     }
// //   }

// // revision: valuedistribution
// // for (uint32_t i = 1; i < argc; ++i) {
// //   std::cout << "revision dataset: " << argv[i] << std::endl;
// //   BenchMark dataset(argv[i], "revision_isclick");
// //   for (uint32_t j = 300; j <= 700; j += 100) {
// //     dataset.HHHyperBench(10000 * j, 0);
// //     dataset.HHSingleBench(10000 * j, 0);
// //     dataset.HHUSSBench(10000 * j, 0);
// //   }
// // }

// // revision: heavychange
// //   for (uint32_t i = 1; i < argc; ++i) {
// //     std::cout << "revision dataset: " << argv[i] << std::endl;
// //     BenchMark_HeavyChange dataset(argv[i], "revision_heavychange");
// //     for (uint32_t j = 300; j <= 700; j += 100) {
// //       dataset.HHHyperBench(1000 * j);
// //       dataset.HHSingleBench(1000 * j);
// //       dataset.HHUSSBench(1000 * j);
// //     }
// //   }


//    return 0;
//  }
