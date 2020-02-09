#include <omp.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
 int main( int argc, char* argv[])
{
 
    // Size of vectors
    int n = 100000; 
    // Input vectors
    double *a, *b, *c;
  
    // Allocate memory for each vector
    a = new double[n];
    b = new double[n];
    c = new double[n];
 
    // Initialize content of input vectors, vector a[i] = sin(i)^2 vector b[i] = cos(i)^2
    int i;
    
    // issue with running this on GPU 
    // will likely get a linking error like
    // lto1: fatal error: LTO_tags out of range: Range is 0 to 421, value is 1006632960
    // mkoffload: fatal error: x86_64-linux-gnu-accel-nvptx-none-gcc-9 returned 1 exit status
    // the reason being that math sine not in openacc 
    // #pragma acc kernels copyout(a[0:n],b[0:n])
    for(i=0; i<n; i++) {
        a[i] = sin(i)*sin(i);
        b[i] = cos(i)*cos(i);
    } 
    // but other simplier functions can be passed to openacc 
    /*
    #pragma acc kernels copyout(a[0:n],b[0:n])
    for(i=0; i<n; i++) {
        a[i] = i*i;
        b[i] = 1.0/((i+1.0)*(i+1.0));
    } 
    */ 
 
    // sum component wise and save result into vector c and get sum
    // here sum would have a data race except OpenACC hinting 
    // tells the compiler to put in a reduction clause, avoiding data race
    double sum = 0.0;
    #pragma acc kernels copyin(a[0:n],b[0:n]), copyout(c[0:n])
    for(i=0; i<n; i++) {
        c[i] = a[i] + b[i];
        sum += c[i];
    }
    sum = sum/n;
    printf("final result: %f\n", sum);
 
    // Release memory
    delete[] a;
    delete[] b;
    delete[] c;
 
    return 0;
}

