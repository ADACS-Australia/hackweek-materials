# hackweek-materials for HPC

Material related to an intro to HPC. Ideally we will make use of [ozstar.swin.edu.au], project oz980. The working directory will be in /fred/oz980/ADACS/HPC/. Please ensure you request an account and request to become a member of this project (visit [https://supercomputing.swin.edu.au/account-management/]). 

For these hands on sessions, if you wish to run on your own machine, you will need
- gcc/g++ >=4.9 to have c++11
- MPI with [openmpi](https://www.open-mpi.org/) >=3.0
- [R](https://cran.r-project.org/), [Rmpi](https://wiki.rc.usf.edu/index.php/R_and_Rmpi), [gpuR](https://cran.r-project.org/web/packages/gpuR/vignettes/gpuR.pdf)
- Python >=3, [mpi4py](https://mpi4py.readthedocs.io/en/stable/), [threading](https://docs.python.org/3/library/threading.html), [multiprocessing](https://docs.python.org/3/library/multiprocessing.html?highlight=multiprocessing#module-multiprocessing)

Lecture materials are found [here](https://docs.google.com/presentation/d/1ms1-31meztR6hQSq6c8DsOJd33bUvOoN7sqdRgLH_ag/edit?usp=sharing)

**Before the lecture would be helpful if this [survey](https://www.surveymonkey.com/r/S7T8VY3) could be completed.**

## Ozstar Info

To run code on ozstar, please try the following:
```
Login to username@ozstar.swin.edu.au
cd /fred/oz980/ADACS/HPC/PLAYGROUND
mkdir usersname
source /fred/oz980/ADACS/HPC/examples/scripts/modulelist.sh
```

This will setup your environment to load an appropriate list of modules. We will then try compiling some examples and try out some code. 
