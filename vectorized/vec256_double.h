#ifndef __VEC256_DOUBLE_H__
#define __VEC256_DOUBLE_H__
#include "vec256_base.h"
#include <immintrin.h>

template <>
class VectorizedAvx2<double>
{

public:

    static void fmadd(int64_t begin, int64_t end, double * x, double * y, double *out, double alpha)
    {
        int64_t i = begin;
        int64_t stride = 4;
        
        __m256d _alpha = _mm256_set1_pd(alpha);

        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m256d _x1 = _mm256_loadu_pd(x+i);
            __m256d _x2 = _mm256_loadu_pd(x+i+stride);

            __m256d _y1 = _mm256_loadu_pd(y+i);
            __m256d _y2 = _mm256_loadu_pd(y+i+stride);

            __m256d _o1 = _mm256_fmadd_pd(_x1, _alpha, _y1);
            __m256d _o2 = _mm256_fmadd_pd(_x2, _alpha, _y2);

            _mm256_storeu_pd(out+i, _o1);
            _mm256_storeu_pd(out+i+stride, _o2);
        }
        
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] * alpha + y[i];
            }
        }
    }

    static void add(int64_t begin, int64_t end, double * x, double * y, double *out)
    {
        int64_t i = begin;
        int64_t stride = 4;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m256d _x1 = _mm256_loadu_pd(x+i);
            __m256d _x2 = _mm256_loadu_pd(x+i+stride);

            __m256d _y1 = _mm256_loadu_pd(y+i);
            __m256d _y2 = _mm256_loadu_pd(y+i+stride);

            __m256d _o1 = _mm256_add_pd(_x1, _y1);
            __m256d _o2 = _mm256_add_pd(_x2, _y2);

            _mm256_storeu_pd(out+i, _o1);
            _mm256_storeu_pd(out+i+stride, _o2);
        }
        
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] + y[i];
            }
        }
    }

    static void sub(int64_t begin, int64_t end, double * x, double * y, double *out)
    {
        int64_t i = begin;
        int64_t stride = 4;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m256d _x1 = _mm256_loadu_pd(x+i);
            __m256d _x2 = _mm256_loadu_pd(x+i+stride);

            __m256d _y1 = _mm256_loadu_pd(y+i);
            __m256d _y2 = _mm256_loadu_pd(y+i+stride);

            __m256d _o1 = _mm256_sub_pd(_x1, _y1);
            __m256d _o2 = _mm256_sub_pd(_x2, _y2);

            _mm256_storeu_pd(out+i, _o1);
            _mm256_storeu_pd(out+i+stride, _o2);
        }
        
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] - y[i];
            }
        }
    }

    static void mul(int64_t begin, int64_t end, double * x, double * y, double *out)
    {
        int64_t i = begin;
        int64_t stride = 4;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m256d _x1 = _mm256_loadu_pd(x+i);
            __m256d _x2 = _mm256_loadu_pd(x+i+stride);

            __m256d _y1 = _mm256_loadu_pd(y+i);
            __m256d _y2 = _mm256_loadu_pd(y+i+stride);

            __m256d _o1 = _mm256_mul_pd(_x1, _y1);
            __m256d _o2 = _mm256_mul_pd(_x2, _y2);

            _mm256_storeu_pd(out+i, _o1);
            _mm256_storeu_pd(out+i+stride, _o2);
        }
        
        if(i < end)
        {
            for(; i < end; i++)
            {
                out[i] = x[i] * y[i];
            }
        }
    }

    static void div(int64_t begin, int64_t end, double * x, double * y, double *out)
    {
        int64_t i = begin;
        int64_t stride = 4;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m256d _x1 = _mm256_loadu_pd(x+i);
            __m256d _x2 = _mm256_loadu_pd(x+i+stride);

            __m256d _y1 = _mm256_loadu_pd(y+i);
            __m256d _y2 = _mm256_loadu_pd(y+i+stride);

            __m256d _o1 = _mm256_div_pd(_x1, _y1);
            __m256d _o2 = _mm256_div_pd(_x2, _y2);

            _mm256_storeu_pd(out+i, _o1);
            _mm256_storeu_pd(out+i+stride, _o2);
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