#include <iostream>
#include "cpuinfo.h"
#include <string.h>
#include "cpu_capbility.h"


CPUCapability compute_cpu_capability() {
  auto envar = std::getenv("ATEN_CPU_CAPABILITY");
  if (envar) {

    if (strcmp(envar, "avx512") == 0) {
      std::cout << "ENV  avx512 "  << std::endl;
      return CPUCapability::AVX512;
    }
    if (strcmp(envar, "avx2") == 0) {
      std::cout << "ENV  avx2 "  << std::endl;
      return CPUCapability::AVX2;
    }

    if (strcmp(envar, "default") == 0) {
      return CPUCapability::DEFAULT;
    }
  }

  if (cpuinfo_initialize()) {
    if (cpuinfo_has_x86_avx512vl() && cpuinfo_has_x86_avx512bw() &&  \
        cpuinfo_has_x86_avx512dq() && cpuinfo_has_x86_fma3()) {
      std::cout << "CPUCapability  avx512 "  << std::endl;
      return CPUCapability::AVX512;
    }
    if (cpuinfo_has_x86_avx2() && cpuinfo_has_x86_fma3()) {
      std::cout << "CPUCapability  avx2 "  << std::endl;
      return CPUCapability::AVX2;
    }
  }

  std::cout << "CPUCapability  DEFAULT "  << std::endl;
  return CPUCapability::DEFAULT;

}
