#include <iostream>
#include "vec.h"


void test_init()
{
    VecFunc<float>::init();
    VecFunc<double>::init();
    // VecFunc<int32_t>::init();
    // VecFunc<int64_t>::init();
}

template<typename T>
std::function<void(int64_t, int64_t, T *, T *, T *, T)> VecFunc<T>::fmadd_func;
template<typename T>
std::function<void(int64_t, int64_t, T *, T *, T *)> VecFunc<T>::add_func;
template<typename T>
std::function<void(int64_t, int64_t, T *, T *, T *)> VecFunc<T>::sub_func;
template<typename T>
std::function<void(int64_t, int64_t, T *, T *, T *)> VecFunc<T>::mul_func;
template<typename T>
std::function<void(int64_t, int64_t, T *, T *, T *)> VecFunc<T>::div_func;
