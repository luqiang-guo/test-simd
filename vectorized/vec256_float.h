#ifndef __VEC256_FLOAT_H__
#define __VEC256_FLOAT_H__
#include "vec256_base.h"
#include <immintrin.h>

template <>
class VectorizedAvx2<float>
{

public:

    static void fmadd(int64_t begin, int64_t end, float * x, float * y, float *out, float alpha)
    {
        int64_t i = begin;
        int64_t stride = 8;
        
        __m256 _alpha = _mm256_set1_ps(alpha);

        for (; i <= end - 2*stride; i += 2*stride) {
            __m256 _x1 = _mm256_loadu_ps(x+i);
            __m256 _x2 = _mm256_loadu_ps(x+i+stride);

            __m256 _y1 = _mm256_loadu_ps(y+i);
            __m256 _y2 = _mm256_loadu_ps(y+i+stride);

            __m256 _o1 = _mm256_fmadd_ps(_x1, _alpha, _y1);
            __m256 _o2 = _mm256_fmadd_ps(_x2, _alpha, _y2);

            _mm256_storeu_ps(out+i, _o1);
            _mm256_storeu_ps(out+i+stride, _o2);
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
        int64_t stride = 8;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m256 _x1 = _mm256_loadu_ps(x+i);
            __m256 _x2 = _mm256_loadu_ps(x+i+stride);

            __m256 _y1 = _mm256_loadu_ps(y+i);
            __m256 _y2 = _mm256_loadu_ps(y+i+stride);

            __m256 _o1 = _mm256_add_ps(_x1, _y1);
            __m256 _o2 = _mm256_add_ps(_x2, _y2);

            _mm256_storeu_ps(out+i, _o1);
            _mm256_storeu_ps(out+i+stride, _o2);
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
        int64_t stride = 8;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m256 _x1 = _mm256_loadu_ps(x+i);
            __m256 _x2 = _mm256_loadu_ps(x+i+stride);

            __m256 _y1 = _mm256_loadu_ps(y+i);
            __m256 _y2 = _mm256_loadu_ps(y+i+stride);

            __m256 _o1 = _mm256_sub_ps(_x1, _y1);
            __m256 _o2 = _mm256_sub_ps(_x2, _y2);

            _mm256_storeu_ps(out+i, _o1);
            _mm256_storeu_ps(out+i+stride, _o2);
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
        int64_t stride = 8;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m256 _x1 = _mm256_loadu_ps(x+i);
            __m256 _x2 = _mm256_loadu_ps(x+i+stride);

            __m256 _y1 = _mm256_loadu_ps(y+i);
            __m256 _y2 = _mm256_loadu_ps(y+i+stride);

            __m256 _o1 = _mm256_mul_ps(_x1, _y1);
            __m256 _o2 = _mm256_mul_ps(_x2, _y2);

            _mm256_storeu_ps(out+i, _o1);
            _mm256_storeu_ps(out+i+stride, _o2);
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
        int64_t stride = 8;

        for (; i <= end - 2*stride; i += 2*stride) {
            __m256 _x1 = _mm256_loadu_ps(x+i);
            __m256 _x2 = _mm256_loadu_ps(x+i+stride);

            __m256 _y1 = _mm256_loadu_ps(y+i);
            __m256 _y2 = _mm256_loadu_ps(y+i+stride);

            __m256 _o1 = _mm256_div_ps(_x1, _y1);
            __m256 _o2 = _mm256_div_ps(_x2, _y2);

            _mm256_storeu_ps(out+i, _o1);
            _mm256_storeu_ps(out+i+stride, _o2);
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