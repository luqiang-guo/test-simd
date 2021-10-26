#ifndef __VEC512_FLOAT_H__
#define __VEC512_FLOAT_H__
#include "vec512_base.h"
#include <immintrin.h>

template <>
class VectorizedAvx512<float>
{

public:

    static void fmadd(int64_t begin, int64_t end, float * x, float * y, float *out, float alpha)
    {
        int64_t i = begin;
        int64_t stride = 16;
        
        __m512 _alpha = _mm512_set1_ps(alpha);

        for (; i <= end - 2*stride; i += 2*stride) {
            __m512 _x1 = _mm512_loadu_ps(x+i);
            __m512 _x2 = _mm512_loadu_ps(x+i+stride);

            __m512 _y1 = _mm512_loadu_ps(y+i);
            __m512 _y2 = _mm512_loadu_ps(y+i+stride);

            __m512 _o1 = _mm512_fmadd_ps(_x1, _alpha, _y1);
            __m512 _o2 = _mm512_fmadd_ps(_x2, _alpha, _y2);

            _mm512_storeu_ps(out+i, _o1);
            _mm512_storeu_ps(out+i+stride, _o2);
        }
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] * alpha + y[i];
            }
        }
    }

    static void add(int64_t begin, int64_t end, float * x, float * y, float *out)
    {
        int64_t i = begin;
        int64_t stride = 16;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m512 _x1 = _mm512_loadu_ps(x+i);
            __m512 _x2 = _mm512_loadu_ps(x+i+stride);

            __m512 _y1 = _mm512_loadu_ps(y+i);
            __m512 _y2 = _mm512_loadu_ps(y+i+stride);

            __m512 _o1 = _mm512_add_ps(_x1, _y1);
            __m512 _o2 = _mm512_add_ps(_x2, _y2);

            _mm512_storeu_ps(out+i, _o1);
            _mm512_storeu_ps(out+i+stride, _o2);
        }
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] + y[i];
            }
        }
    }

    static void sub(int64_t begin, int64_t end, float * x, float * y, float *out)
    {
        int64_t i = begin;
        int64_t stride = 16;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m512 _x1 = _mm512_loadu_ps(x+i);
            __m512 _x2 = _mm512_loadu_ps(x+i+stride);

            __m512 _y1 = _mm512_loadu_ps(y+i);
            __m512 _y2 = _mm512_loadu_ps(y+i+stride);

            __m512 _o1 = _mm512_sub_ps(_x1, _y1);
            __m512 _o2 = _mm512_sub_ps(_x2, _y2);

            _mm512_storeu_ps(out+i, _o1);
            _mm512_storeu_ps(out+i+stride, _o2);
        }
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] - y[i];
            }
        }
    }

    static void mul(int64_t begin, int64_t end, float * x, float * y, float *out)
    {
        int64_t i = begin;
        int64_t stride = 16;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m512 _x1 = _mm512_loadu_ps(x+i);
            __m512 _x2 = _mm512_loadu_ps(x+i+stride);

            __m512 _y1 = _mm512_loadu_ps(y+i);
            __m512 _y2 = _mm512_loadu_ps(y+i+stride);

            __m512 _o1 = _mm512_mul_ps(_x1, _y1);
            __m512 _o2 = _mm512_mul_ps(_x2, _y2);

            _mm512_storeu_ps(out+i, _o1);
            _mm512_storeu_ps(out+i+stride, _o2);
        }
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] * y[i];
            }
        }
    }

    static void div(int64_t begin, int64_t end, float * x, float * y, float *out)
    {
        int64_t i = begin;
        int64_t stride = 16;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m512 _x1 = _mm512_loadu_ps(x+i);
            __m512 _x2 = _mm512_loadu_ps(x+i+stride);

            __m512 _y1 = _mm512_loadu_ps(y+i);
            __m512 _y2 = _mm512_loadu_ps(y+i+stride);

            __m512 _o1 = _mm512_div_ps(_x1, _y1);
            __m512 _o2 = _mm512_div_ps(_x2, _y2);

            _mm512_storeu_ps(out+i, _o1);
            _mm512_storeu_ps(out+i+stride, _o2);
        }
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] / y[i];
            }
        }
    }

};

#endif