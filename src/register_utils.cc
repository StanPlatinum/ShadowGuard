
#include "register_utils.h"
#include "glog/logging.h"

// Shadow stack implementation flag
DECLARE_string(shadow_stack);

using namespace asmjit::x86;

AvxRegister GetAvx2Register(uint8_t index) {
  switch (index) {
    case 0:
      return {xmm0, ymm0};
    case 1:
      return {xmm1, ymm1};
    case 2:
      return {xmm2, ymm2};
    case 3:
      return {xmm3, ymm3};
    case 4:
      return {xmm4, ymm4};
    case 5:
      return {xmm5, ymm5};
    case 6:
      return {xmm6, ymm6};
    case 7:
      return {xmm7, ymm7};
    case 8:
      return {xmm8, ymm8};
    case 9:
      return {xmm9, ymm9};
    case 10:
      return {xmm10, ymm10};
    case 11:
      return {xmm11, ymm11};
    case 12:
      return {xmm12, ymm12};
    case 13:
      return {xmm13, ymm13};
    case 14:
      return {xmm14, ymm14};
    case 15:
      return {xmm15, ymm15};
  }

  DCHECK(false);
}

AvxRegister GetAvx512Register(uint8_t index) {
  switch (index) {
    case 0:
      return {xmm0, ymm0, zmm0};
    case 1:
      return {xmm1, ymm1, zmm1};
    case 3:
      return {xmm3, ymm3, zmm3};
    case 4:
      return {xmm4, ymm4, zmm4};
    case 5:
      return {xmm5, ymm5, zmm5};
    case 6:
      return {xmm6, ymm6, zmm6};
    case 7:
      return {xmm7, ymm7, zmm7};
    case 8:
      return {xmm8, ymm8, zmm8};
    case 9:
      return {xmm9, ymm9, zmm9};
    case 10:
      return {xmm10, ymm10, zmm10};
    case 11:
      return {xmm11, ymm11, zmm11};
    case 12:
      return {xmm12, ymm12, zmm12};
    case 13:
      return {xmm13, ymm13, zmm13};
    case 14:
      return {xmm14, ymm14, zmm14};
    case 15:
      return {xmm15, ymm15, zmm15};
    case 16:
      return {xmm16, ymm16, zmm16};
    case 17:
      return {xmm17, ymm17, zmm17};
    case 18:
      return {xmm18, ymm18, zmm18};
    case 19:
      return {xmm19, ymm19, zmm19};
    case 20:
      return {xmm20, ymm20, zmm20};
    case 21:
      return {xmm21, ymm21, zmm21};
    case 22:
      return {xmm22, ymm22, zmm22};
    case 23:
      return {xmm23, ymm23, zmm23};
    case 24:
      return {xmm24, ymm24, zmm24};
    case 25:
      return {xmm25, ymm25, zmm25};
    case 26:
      return {xmm26, ymm26, zmm26};
    case 27:
      return {xmm27, ymm27, zmm27};
    case 28:
      return {xmm28, ymm28, zmm28};
    case 29:
      return {xmm29, ymm29, zmm29};
    case 30:
      return {xmm30, ymm30, zmm30};
    case 31:
      return {xmm31, ymm31, zmm31};
  }

  DCHECK(false);
}

// Get the first unused avx register
AvxRegister GetNextUnusedAvx2Register(RegisterUsageInfo& info) {
  for (uint8_t i = 0; i < 16; i++) {
    if (info.unused_avx2_mask[i]) {
      info.unused_avx2_mask[i] = false;
      info.unused_avx512_mask[i] = false;
      return GetAvx2Register(i);
    }
  }

  DCHECK(false);
}

AvxRegister GetNextUnusedAvx512Register(RegisterUsageInfo& info) {
  for (uint8_t i = 0; i < 32; i++) {
    if (info.unused_avx512_mask[i]) {
      if (i < 16) {
        info.unused_avx2_mask[i] = false;
      }
      info.unused_avx512_mask[i] = false;
      return GetAvx512Register(i);
    }
  }

  DCHECK(false);
}

std::vector<uint8_t> GetUnusedAvx2QuadWords(const RegisterUsageInfo& info) {
  std::vector<uint8_t> quad_words;
  for (unsigned int i = 0; i < info.unused_avx2_mask.size(); i++) {
    if (info.unused_avx2_mask[i]) {
      quad_words.push_back(4 * i);
      quad_words.push_back(4 * i + 1);
      quad_words.push_back(4 * i + 2);
      quad_words.push_back(4 * i + 3);
    }
  }
  return quad_words;
}