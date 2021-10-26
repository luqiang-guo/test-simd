#ifndef __VEC512_DOUBLE_H__
#define __VEC512_DOUBLE_H__
#include "vec512_base.h"
#include <immintrin.h>

template <>
class VectorizedAvx512<double>
{

public:

    static void fmadd(int64_t begin, int64_t end, double * x, double * y, double *out, double alpha)
    {
        int64_t i = begin;
        int64_t stride = 8;
        
        __m512d _alpha = _mm512_set1_pd(alpha);

        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m512d _x1 = _mm512_loadu_pd(x+i);
            __m512d _x2 = _mm512_loadu_pd(x+i+stride);

            __m512d _y1 = _mm512_loadu_pd(y+i);
            __m512d _y2 = _mm512_loadu_pd(y+i+stride);

            __m512d _o1 = _mm512_fmadd_pd(_x1, _alpha, _y1);
            __m512d _o2 = _mm512_fmadd_pd(_x2, _alpha, _y2);

            _mm512_storeu_pd(out+i, _o1);
            _mm512_storeu_pd(out+i+stride, _o2);
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
        int64_t stride = 8;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m512d _x1 = _mm512_loadu_pd(x+i);
            __m512d _x2 = _mm512_loadu_pd(x+i+stride);

            __m512d _y1 = _mm512_loadu_pd(y+i);
            __m512d _y2 = _mm512_loadu_pd(y+i+stride);

            __m512d _o1 = _mm512_add_pd(_x1, _y1);
            __m512d _o2 = _mm512_add_pd(_x2, _y2);

            _mm512_storeu_pd(out+i, _o1);
            _mm512_storeu_pd(out+i+stride, _o2);
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
        int64_t stride = 8;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m512d _x1 = _mm512_loadu_pd(x+i);
            __m512d _x2 = _mm512_loadu_pd(x+i+stride);

            __m512d _y1 = _mm512_loadu_pd(y+i);
            __m512d _y2 = _mm512_loadu_pd(y+i+stride);

            __m512d _o1 = _mm512_sub_pd(_x1, _y1);
            __m512d _o2 = _mm512_sub_pd(_x2, _y2);

            _mm512_storeu_pd(out+i, _o1);
            _mm512_storeu_pd(out+i+stride, _o2);
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
        int64_t stride = 8;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m512d _x1 = _mm512_loadu_pd(x+i);
            __m512d _x2 = _mm512_loadu_pd(x+i+stride);

            __m512d _y1 = _mm512_loadu_pd(y+i);
            __m512d _y2 = _mm512_loadu_pd(y+i+stride);

            __m512d _o1 = _mm512_mul_pd(_x1, _y1);
            __m512d _o2 = _mm512_mul_pd(_x2, _y2);

            _mm512_storeu_pd(out+i, _o1);
            _mm512_storeu_pd(out+i+stride, _o2);
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
        int64_t stride = 8;
        
        for (; i <= end - 2*stride; i += 2*stride) 
        {
            __m512d _x1 = _mm512_loadu_pd(x+i);
            __m512d _x2 = _mm512_loadu_pd(x+i+stride);

            __m512d _y1 = _mm512_loadu_pd(y+i);
            __m512d _y2 = _mm512_loadu_pd(y+i+stride);

            __m512d _o1 = _mm512_div_pd(_x1, _y1);
            __m512d _o2 = _mm512_div_pd(_x2, _y2);

            _mm512_storeu_pd(out+i, _o1);
            _mm512_storeu_pd(out+i+stride, _o2);
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