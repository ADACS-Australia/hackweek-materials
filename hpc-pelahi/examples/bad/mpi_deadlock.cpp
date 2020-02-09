#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;
int main (int argc, char* argv[]){

    int NTasks, ThisTask;
    int sum;
    MPI_Status status;

    MPI_Init(&argc,&argv);

    MPI_Comm_size(MPI_COMM_WORLD, &NTasks);
    MPI_Comm_rank(MPI_COMM_WORLD, &ThisTask);

    if (NTasks < 2) {
        if (ThisTask == 0) cerr<<"Not enough tasks, please ensure 2 or more"<<endl;
        MPI_Abort(MPI_COMM_WORLD,1);
    }

    int sendtask, recvtask, tag;
    int numelements = ThisTask + 1;
    vector<int> data(numelements, ThisTask), recvdata;
    //now lets send information
    if (ThisTask % 2 == 0) {
        sendtask = ThisTask + 1;
        recvtask = ThisTask + 1;
        recvdata.resize(sendtask+1);
        tag = recvtask;
        MPI_Send(data.data(), data.size(), MPI_INTEGER, recvtask, tag,MPI_COMM_WORLD);
        MPI_Recv(recvdata.data(), recvdata.size(), MPI_INTEGER, recvtask, tag, MPI_COMM_WORLD, &status);
    }
    else {
        sendtask = ThisTask - 1;
        recvtask = ThisTask - 1; 
        recvdata.resize(sendtask+1);
        tag = recvtask;
        MPI_Recv(recvdata.data(), recvdata.size(), MPI_INTEGER, recvtask, tag, MPI_COMM_WORLD, &status);
        MPI_Send(data.data(), data.size(), MPI_INTEGER, recvtask, tag, MPI_COMM_WORLD);
    }
    
    for (auto itask=0;itask<NTasks;itask++) {
        if (ThisTask == itask) {
            cout<<"Task "<<ThisTask<<" has following:"<<endl;
            cout<<"Sending to "<<sendtask<<endl;
            cout<<"Data ";for (auto x:data) cout<<x<<" ";cout<<endl;
            cout<<"Receiving from "<<recvtask<<endl;
            cout<<"Data ";for (auto x:recvdata) cout<<x<<" ";cout<<endl;
        }
        MPI_Barrier(MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
    return 0;
} 
