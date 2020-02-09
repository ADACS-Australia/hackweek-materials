#include <pthread.h>
#include <stdio.h>
#define NT 10
#define NI 100
int Global, oldGlobal;
void *Thread1(void *x) {Global++;return NULL;}
void *Thread2(void *x) {Global--;return NULL;}
int main() {
  pthread_t t[NT];
  oldGlobal=Global=2;
  for (auto i=0;i<NI;i++) {
    for (auto j=0;j<NT;j++) {
        if (j<NT/2) pthread_create(&t[j], NULL, Thread2, NULL);
        else pthread_create(&t[j], NULL, Thread1, NULL);
        //if (Global<=oldGlobal) pthread_create(&t[j], NULL, Thread1, NULL);
        //else pthread_create(&t[j], NULL, Thread2, NULL);
        //pthread_join(t[j], NULL);
    }
    for (auto j=0;j<NT;j++) pthread_join(t[j], NULL);
    if (Global!= oldGlobal) {
      printf("Issue after %d iteration have %d\n",i, Global);
      break;
    }
  }
}

