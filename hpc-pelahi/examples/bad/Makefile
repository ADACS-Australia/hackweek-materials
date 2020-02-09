MPICC = mpicc
MPICXX = mpic++
CC = gcc
CXX = g++

OMP_FLAGS = -fopenmp
OACC_FLAGS = -fopenacc
PTHREAD_FLAGS = -pthread 

CFLAGS = -g 
CXXFLAGS = -g -std=c++11 

all: mpi_deadlock omp_datarace pthreads_datarace oacc_datarace 

mpi_deadlock: mpi_deadlock.cpp
	$(MPICXX) $(CXXFLAGS) mpi_deadlock.cpp -o mpi_deadlock
omp_datarace: omp_datarace.cpp
	$(CXX) $(OMP_FLAGS) $(CXXFLAGS) omp_datarace.cpp -o omp_datarace
pthreads_datarace: pthreads_datarace.cpp
	$(CC) $(CFLAGS) $(PTHREAD_FLAGS) pthreads_datarace.cpp -o pthreads_datarace
oacc_datarace: oacc_datarace.cpp
	$(CXX) $(OACC_FLAGS) $(CXXFLAGS) oacc_datarace.cpp -o oacc_datarace

clean:
	rm -r mpi_deadlock omp_datarace omacc_datarace pthreads_datarace

