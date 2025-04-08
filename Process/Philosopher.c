#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 5

pthread_mutex_t forks[MAX];
sem_t mutex;

void * philosopher(void * num){
    int id=*(int *)num;
    while(1){
        printf("Philosopher %d is thinking!\n",id);
        sleep(1);
        sem_wait(&mutex)
        pthread_mutex_lock(&forks[id]);
        pthread_mutex_unlock(&forks[(id+1)%MAX]);   
        printf("Philosopher %d is eating!\n",id);
    }
}