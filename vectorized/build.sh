g++ -o vectorized \
cpu_capbility.cpp \
mu_malloc.cpp \
thread_loop.cpp \
vec.cpp \
main.cpp \
--std=c++11 \
-mfma -mavx512f \
-fopenmp \
-I../cpuinfo-out/include \
-L../cpuinfo-out/lib \
-lcpuinfo -lclog -lpthread \

