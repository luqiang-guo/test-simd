#ifndef __THREAD_LOOP_H__
#define __THREAD_LOOP_H__
#include <iostream>

#include <stdio.h>
#include <functional>

void init_num_threads();

void parallel_loop(int64_t begin, int64_t end, std::function< void(int64_t, int64_t)> f, int64_t grain_size = 32768);

#endif