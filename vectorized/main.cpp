#include <iostream>
#include "thread_loop.h"
#include "mu_malloc.h"
#include "vec.h"
// #include "vec.cpp"
// #include "vec256.h"
// #include "vec512.h"
// #include "cpu_capbility.h"
// #include "vec_default.h"

template<typename T>
void vec_add(T * x, T * y, T *out, T alpha, int64_t len)
{
    parallel_loop(0, len, [=](int64_t begin, int64_t end){
        VecFunc<T>::fmadd_func(begin, end, x, y, out , alpha);
    }, 32768);
}

template<typename T>
void vec_sub(T * x, T * y, T *out, int64_t len)
{
    parallel_loop(0, len, [=](int64_t begin, int64_t end){
        VecFunc<T>::sub_func(begin, end, x, y, out);
    }, 32768);
}

template<typename T>
void vec_mul(T * x, T * y, T *out, int64_t len)
{
    parallel_loop(0, len, [=](int64_t begin, int64_t end){
        VecFunc<T>::mul_func(begin, end, x, y, out);
    }, 32768);
}


template<typename T>
void vec_div(T * x, T * y, T *out, int64_t len)
{
    parallel_loop(0, len, [=](int64_t begin, int64_t end){
        VecFunc<T>::div_func(begin, end, x, y, out);
    }, 32768);
}


int main()
{
    // 初始化线程
    init_num_threads();

    test_init();

    int len  = 224*224*3;
    float *x, *y, *out, alpha = 0.5;

    mu_alloc(&x, &y, &out, len);

    vec_add(x, y, out, alpha, len);

    // print(out, len);

    vec_sub(x, y, out, len);
    vec_mul(x, y, out, len);
    vec_div(x, y, out, len);

    // print(out, len);

    return 0;
}
