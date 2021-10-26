#include "thread_loop.h"
#include "omp.h"

#define NUM_THREADS 8

void init_num_threads() 
{
    omp_set_num_threads(NUM_THREADS);
}


inline int64_t divup(int64_t x, int64_t y) {
  return (x + y - 1) / y;
}

void parallel_loop(int64_t begin, int64_t end, std::function< void(int64_t, int64_t)> f, int64_t grain_size)
{
    std::cout << "begin = " << begin << " end = " << end << " grain_size = " << grain_size << std::endl;

    #pragma omp parallel
    {
        int64_t num_threads = omp_get_num_threads();
        // std::cout << "omp_get_num_threads() = " << num_threads << std::endl;
        if (grain_size > 0) {
        num_threads = std::min(num_threads, divup((end - begin), grain_size));
        }
        std::cout << "num_threads = " << num_threads << std::endl;
        int64_t chunk_size = divup((end - begin), num_threads);
        std::cout << "chunk_size = " << chunk_size << std::endl;

        int64_t tid = omp_get_thread_num();
        // std::cout << "omp_get_thread_num() = " << tid << std::endl;
        
        int64_t begin_tid = begin + tid * chunk_size;
        int64_t end_tid = std::min(end, chunk_size + begin_tid);
        if (begin_tid < end) {
            f(begin_tid, end_tid);
        }
    }
}