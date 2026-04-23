#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *fun1();
void *fun2();
int shared = 1; // shared variable
int main(){
pthread_t thread1,thread2;
pthread_create(&thread1,NULL,fun1,NULL);
pthread_create(&thread2,NULL,fun2,NULL);
pthread_join(thread1,NULL);
pthread_join(thread2,NULL);
printf("%d",shared);
}

void *fun1(){
int x;
x = shared; // thread (reads , value of shared varaible)
printf("%d",x);
x++;
printf("%d",x);
sleep(1); // prempt to 2
shared = x; // thread | udates the value of shared varaible
printf("%d",shared);
}

void *fun2(){
int y;
y = shared;
printf("%d\n",y);
sleep(1);
shared = y;
printf("%d\n" , shared);
}