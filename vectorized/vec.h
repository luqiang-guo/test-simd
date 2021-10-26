#ifndef __VEC_H__
#define __VEC_H__
#include <functional>
#include "cpu_capbility.h"
#include "vec256.h"
#include "vec512.h"
#include "vec_default.h"

template<typename T>
class VecFunc
{
public:
    static void init()
    {
        auto capability = compute_cpu_capability();
        switch (capability) {
            case CPUCapability::DEFAULT:
                std::cout << "NO SIMD" << std::endl;
                fmadd_func = VectorizedDefault<T>::fmadd;
                add_func = VectorizedDefault<T>::add;
                sub_func = VectorizedDefault<T>::sub;
                mul_func = VectorizedDefault<T>::mul;
                div_func = VectorizedDefault<T>::div;
                break;
            case CPUCapability::AVX2:
                std::cout << "AVX2" << std::endl;
                fmadd_func = VectorizedAvx2<T>::fmadd;
                add_func = VectorizedAvx2<T>::add;
                sub_func = VectorizedAvx2<T>::sub;
                mul_func = VectorizedAvx2<T>::mul;
                div_func = VectorizedAvx2<T>::div;
                break;
            case CPUCapability::AVX512:
                std::cout << "AVX512" << std::endl;
                fmadd_func = VectorizedAvx512<T>::fmadd;
                add_func = VectorizedAvx512<T>::add;
                sub_func = VectorizedAvx512<T>::sub;
                mul_func = VectorizedAvx512<T>::mul;
                div_func = VectorizedAvx512<T>::div;
                break;
            default:
                break;
        }
    }

    //begin end x y out alpha
    static std::function<void(int64_t, int64_t, T *, T *, T *, T)> fmadd_func;
    static std::function<void(int64_t, int64_t, T *, T *, T *)> add_func;
    static std::function<void(int64_t, int64_t, T *, T *, T *)> sub_func;
    static std::function<void(int64_t, int64_t, T *, T *, T *)> mul_func;
    static std::function<void(int64_t, int64_t, T *, T *, T *)> div_func;
};


void test_init();

// #define MATH_BINARY_BROADCAST_FUNC_SEQ                  \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_add", Add)            \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_sub", Sub)            \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_mul", Mul)            \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_div", Div)            \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_minimum", Min)        \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_maximum", Max)        \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_floor_mod", FloorMod) \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_fmod", FMod)          \
//   OF_PP_MAKE_TUPLE_SEQ("broadcast_pow", Pow

#endif
