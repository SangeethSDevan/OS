#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 5 

int buffer[MAX],in=0,out=0;
sem_t full,empty;
pthread_mutex_t mutex;

void* producer(void * num){
    for(int i=0;i<MAX;i++){
        int item=i;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in]=item;
        in=(in+1)%MAX;
        printf("Produced item %d\n",item);
        sleep(1);

        sem_post(&full);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
void * consumer(void * args){
    for(int i=0;i<MAX;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item=buffer[out];
        out=(out+1)%MAX;
        printf("Consumed item %d\n",item);

        sem_post(&empty);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}
int main(){
    pthread_t prod,cons;
    sem_init(&full,0,0);
    sem_init(&empty,0,MAX);
    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    pthread_join(prod,NULL);
    pthread_join(cons,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
}