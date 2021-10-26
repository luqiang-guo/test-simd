#ifndef __VEC_DEFAULT_H__
#define __VEC_DEFAULT_H__

#include <iostream>


template <typename T>
class VectorizedDefault
{

public:

    static void fmadd(int64_t begin, int64_t end, T * x, T * y, T *out, T alpha)
    {
        for (int64_t i = begin; i <= end; i ++) {
            out[i] = x[i] * alpha + y[i];
        }
    }

    static void add(int64_t begin, int64_t end, T * x, T * y, T *out)
    {
        for (int64_t i = begin; i <= end; i ++) {
            out[i] = x[i] + y[i];
        }
    }

    static void sub(int64_t begin, int64_t end, T * x, T * y, T *out)
    {
        for (int64_t i = begin; i <= end; i ++) {
            out[i] = x[i] - y[i];
        }
    }

    static void mul(int64_t begin, int64_t end, T * x, T * y, T *out)
    {
        for (int64_t i = begin; i <= end; i ++) {
            out[i] = x[i] * y[i];
        }
    }

    static void div(int64_t begin, int64_t end, T * x, T * y, T *out)
    {
        for (int64_t i = begin; i <= end; i ++) {
            out[i] = x[i] / y[i];
        }
    }

};

#endif