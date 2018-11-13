#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
  
#define N 5
int THINKING=2;

int phil[N] = { 0, 1, 2, 3, 4 }; 
int EATING=0;
int HUNGRY=1;
 int state[N]; 
sem_t mutex; 
sem_t S[N]; 
  
void test(int phnum) { 
    if (state[phnum] == HUNGRY && state[(phnum + 4) % N] != EATING && state[(phnum + 1) % N] != EATING) { 
        state[phnum] = EATING; 
        sleep(2); 
        printf("Philosopher %d takes fork #%d and #%d\n", phnum + 1, (phnum + 4) % N + 1, phnum + 1); 
        printf("Philosopher %d is Eating\n", phnum + 1); 
        sem_post(&S[phnum]); 
    } 
} 
  
// take chopstick
void take_fork(int phnum) { 
    sem_wait(&mutex); 
    state[phnum] = HUNGRY;   
    printf("Philosopher %d is Hungry\n", phnum + 1); 
    test(phnum); 
    sem_post(&mutex); 
    sem_wait(&S[phnum]); 
    sleep(1); 
} 
  
//Put down chopsticks 
void put_fork(int phnum) {  
    sem_wait(&mutex); 
    state[phnum] = THINKING; 
    printf("Philosopher %d puts down fork #%d and #%d down\n", 
           phnum + 1, (phnum + 4) % N + 1, phnum + 1); 
    printf("Philosopher %d is thinking\n", phnum + 1); 
    test((phnum + 4) % N); 
    test((phnum + 1) % N); 
    sem_post(&mutex); 
} 
  
void* philospher(void* num) { 
    while (1) { 
        int* i = num; 
        sleep(1); 
        take_fork(*i); 
        sleep(0); 
        put_fork(*i); 
    } 
} 
  
int main(void){ 
    int i; 
    pthread_t thread_id[N]; 
    sem_init(&mutex, 0, 1); 
    for (i = 0; i < N; i++){  
        sem_init(&S[i], 0, 0); 
    }
  
    for (i = 0; i < N; i++) { 
        //Create processes for the philosopher
        pthread_create(&thread_id[i], NULL, philospher, &phil[i]); 
        printf("Philosopher %d is thinking\n", i + 1); 
    } 
  
    for (i = 0; i < N; i++){
        pthread_join(thread_id[i], NULL); 
    }

    return 0;
} 
