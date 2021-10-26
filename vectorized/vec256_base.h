#ifndef __VEC256_BASE_H__
#define __VEC256_BASE_H__
#include <iostream>

template <typename T>
class VectorizedAvx2
{
    static void fmadd(int64_t begin, int64_t end, T * x, T * y, T *out, T alpha);
    static void add(int64_t begin, int64_t end, T * x, T * y, T *out);
    static void div(int64_t begin, int64_t end, T * x, T * y, T *out);
    static void mul(int64_t begin, int64_t end, T * x, T * y, T *out);
};


#endif