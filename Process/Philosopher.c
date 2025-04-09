#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 5

sem_t forks[MAX];
pthread_t philosophers[MAX];

void * philosopher(void * num){
    int id=*(int *) num;
    while(1){
        printf("Philosopher %d is thinking!\n",id);
        if(id==MAX-1){
            sem_wait(&forks[id]);
            sem_wait(&forks[(id+1)%MAX]);
        }else{
            sem_wait(&forks[(id+1)%MAX]);
            sem_wait(&forks[id]);
        }

        printf("Philosopher %d is eating!\n",id);
        sleep(2);
        sem_post(&forks[id]);
        sem_post(&forks[(id+1)%MAX]);
    }
}
void main(){
    int id[MAX];
    for(int i=0;i<MAX;i++){
        sem_init(&forks[i],0,1);
    }
    for(int i=0;i<MAX;i++){
        id[i]=i;
        pthread_create(&philosophers[i],NULL,philosopher,&id[i]);
    }
    for(int i=0;i<MAX;i++){
        pthread_join(philosophers[i],NULL);
    }
    for(int i=0;i<MAX;i++){
        sem_destroy(&forks[i]);
    }
}