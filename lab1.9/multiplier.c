#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<unistd.h>
#include<stdint.h>
#include <string.h>

#define MAT_A "./matA.dat"
#define MAT_B "./matB.dat"
#define ROW_SIZE 2000
#define COLUMN_SIZE 2000
#define MAX_THREADS 10
#define MATRIX_SIZE COLUMN_SIZE*ROW_SIZE


//functions
long *readMatrix(char *filename);
long *getRow(int row, long *matrix);
int getLock(void);
int releaseLock(int Lock);
int dotProduct(long *vec1, long *vec2);
long *multiply(long *matA, long *matB);
int saveResultMatrix(long *result);
void *thread_runner(void *params);

//Global variables
float *matrix;
long i, size;
long **buffers;
pthread_mutex_t *mutexes;  	//mutex array
pthread_mutex_t row_mutex;
long *result, *row_buff, *column_buff, n, NUM_BUFFERS, row_count =-1;
pthread_t threads[MAX_THREADS];


typedef struct{
	long *matA;
	long *matB;
} args;

args parameters;



int main(void) {

unsigned long i=0;
long *matA, *matB, *res;
pthread_attr_t attr;
pthread_t *threads;
args parameters;

threads =malloc(MAX_THREADS*sizeof(pthread_t));
matA=malloc(MATRIX_SIZE*sizeof(long));
matB =malloc(MATRIX_SIZE*sizeof(long));
//row1=malloc(ROW_SIZE*sizeof(long));
//column1=malloc(COLUMN_SIZE*sizeof(long));
result=malloc(MATRIX_SIZE*sizeof(long));
row_buff=malloc(ROW_SIZE*sizeof(long));
column_buff=malloc(COLUMN_SIZE*sizeof(long));

pthread_attr_init(&attr);

printf("input desired number of buffers: ");
fflush(stdout);
scanf("%d", &NUM_BUFFERS);

buffers=malloc(NUM_BUFFERS*sizeof(long*));

for(i=0;i<NUM_BUFFERS; i++){
	buffers[i]=malloc(ROW_SIZE*sizeof(long));
}

mutexes=malloc(NUM_BUFFERS*sizeof(pthread_mutex_t));


memcpy(matA,readMatrix(MAT_A), MATRIX_SIZE*sizeof(long));
memcpy(matB,readMatrix(MAT_B), MATRIX_SIZE*sizeof(long));

memcpy(res,multiply(matA,matB),MATRIX_SIZE*sizeof(long));

/**
unsigned long j;
for(j=0;j<MATRIX_SIZE;j++){
	matA[j]=1;
}

for(j=0;j<MATRIX_SIZE;j++){
	matB[j]=2;
}

*/

/**
parameters.matA=matA;
parameters.matB=matB;

do{
	for(j=0;j<MAX_THREADS;j++){
		pthread_create(&threads[j],&attr,multiply,(void *) &parameters);
	}
	
	for(j=0;j<MAX_THREADS;j++){
		pthread_join(threads[j],NULL);
	}
	
}while(k++<COLUMN_SIZE/MAX_THREADS);

*/

free(mutexes);
free(matA);
free(matB);
free(result);
free(row_buff);
free(column_buff);

	




//owA1=getRow(1,matA);
//rowB0=getRow(0,matB);



return 0;

}


long* readMatrix(char *filename) {

int i;
long *matrix;


matrix=(long*)malloc(4000000*sizeof(long));
FILE *file;



file = fopen(filename, "r");
for(i=0; i<4000000; i++) {
	fscanf(file, "%ld", &matrix[i]);
}

fclose(file);

return matrix;
}



int dotProduct(long *vec1, long *vec2) {

long result = 0;
unsigned long i;
for(i=0;i<ROW_SIZE; i++) {

	result+=vec1[i]*vec2[i];
}
return result;
}



long *getRow(int row, long *matrix) {
	unsigned long i;
	unsigned long index=ROW_SIZE*row;
	for(i=0; i<ROW_SIZE; i++) {
		row_buff[i]=matrix[index++];
	}
	return row_buff;

}

long *getColumn(int column, long *matrix) {
	unsigned long i;
	for(i=0; i<COLUMN_SIZE; i++) {
		column_buff[i]=matrix[i*COLUMN_SIZE+column];
	}
	
	return column_buff;
}

int getLock(void) {

	int i =0;
	do{
		if(0==pthread_mutex_trylock(&mutexes[i])) {
			return i;
		}
	}while(i++<NUM_BUFFERS-1);

	return -1;

}

int releaseLock(int lock) {
	int result;
	if(0==pthread_mutex_unlock(&mutexes[lock])){
	result=0;
	}
	else{result=-1;}
	
	return result;
}

long *multiply(long *matA, long *matB) {
	unsigned long i, j, n=0;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	parameters.matA=matA;
	parameters.matB=matB;

do{
	for(i=0;i<MAX_THREADS;i++){
		pthread_create(&threads[i],&attr,thread_runner,(void *) n);
		n++;
	}
	
	for(i=0;i<MAX_THREADS;i++) {
		pthread_join(threads[i], NULL);
	}

	}while(j++<(ROW_SIZE/MAX_THREADS)-1);
		return result;

}


int saveResultMatrix(long *result) {
return 0;
}

void *thread_runner(void *params){
	int lock;
	unsigned long i;
	long *row, *column;

	while(-1==(lock=getlock()));
	pthread_mutex_lock(&row_mutex);
	row_count++;
	row=malloc(ROW_SIZE*sizeof(long));
	column=malloc(COLUMN_SIZE*sizeof(long));
	memcpy(row,getRow(n,parameters.matA),ROW_SIZE*sizeof(long));

	for(i=0; i<COLUMN_SIZE;i++){
		memcpy(column,getColumn(i,parameters.matB),ROW_SIZE*sizeof(long));
		buffers[lock][i]=dotProduct(row,column);
		}

	for(i=0;i<COLUMN_SIZE;i++){
		result[n*ROW_SIZE+i]=buffers[lock][i];
	}
	
	free(row);
	free(column);
	pthread_mutex_unlock(&row_mutex);
	releaseLock(lock);
	pthread_exit(0);
}


	




