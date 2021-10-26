#include <iostream>
#include <stdlib.h>
#include "mu_malloc.h"

void mu_alloc(float **x, float **y, float **o, int len)
{
    float * tmp_x = (float *)malloc(len * sizeof(float));
    float * tmp_y = (float *)malloc(len * sizeof(float));
    float * tmp_o = (float *)malloc(len * sizeof(float));

    for(int i = 0; i < len; i++)
    {
        // printf("i = %d \n",i);
        tmp_x[i] = i;
        tmp_y[i] = 1.5;
    }

    *x = tmp_x;
    *y = tmp_y;
    *o = tmp_o;
}



void print(float * data, int len)
{
    for(int i = 0; i < len; i++)
    {
        float tmp = i;
        // printf("len = %f \n", data[i]);
        printf("data[%d] = %f \n", i, data[i]);

    }
}


