#include <omp.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int ndata=10;
    vector<float> x(ndata), cumsum(ndata,0);
    for (auto i=0;i<ndata;i++) x[i]=i*i;
    for (auto &val:x) cout<<val<<" ";cout<<endl;
    int start=0, end = x.size();
    float minval = x[0], maxval=x[0], sum=0;
    #pragma omp master
    {
        cout<<omp_get_thread_num()<<" total num threads "<<omp_get_max_threads()<<endl;
    }
    //for loop where default is variables shared
    //resulting in data race 
    #pragma omp parallel for \
    default(shared) schedule(static) 
    for (auto i = start; i < end; i++)
    {
        if (minval > x[i]) minval = x[i];
        if (maxval < x[i]) maxval = x[i];
        sum += x[i]; if(i>0) cumsum[i] = cumsum[i-1]+x[i];
    }
    //what happens if minval/maxval/sum accessed at the same time?
    //what is stored in cumsum? 
    cout<<"min"<<" "<<"max"<<" "<<"sum"<<" : "<<minval<<" "<<maxval<<" "<<sum<<endl;
    cout<<"cumsum ";
    for (auto &val:cumsum) cout<<val<<" ";
    cout<<endl;
}
