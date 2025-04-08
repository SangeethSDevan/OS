#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define MAX 5
int buffer[MAX],in=0,out=0;
sem_t empty,full;
pthread_mutex_t mutex;

void * producer(void * args){
    for(int i=0;i<MAX;i++){
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        int item=i;
        buffer[in]=item;
        printf("Produced item: %d\n",item);
        in=(in+1)%MAX;

        pthread_mutex_unlock(&mutex);
        sem_post(&full); 
        sleep(1);     
    }
    return NULL;
}
void * consumer(void * args){
    for(int i=0;i<MAX;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        int item=buffer[out];
        out=(out+1)%MAX;
        printf("Consumed item: %d\n",item);

        pthread_mutex_unlock(&mutex);
        sem_wait(&empty);
        sleep(1);
    }
    return NULL;
}
void main(){
    pthread_t prod,cons;
    sem_init(&empty,0,MAX);
    sem_init(&full,0,0);
    pthread_mutex_init(&mutex,NULL);

    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    pthread_join(prod,NULL);
    pthread_join(cons,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);
}