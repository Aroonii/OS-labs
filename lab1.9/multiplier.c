#include <stdio.h>
#include <stdlib.h>
#define NUM_BUFFERS

long* readMatrix(char *filename);



int main(int argc, char **argv) {


float *matrix;
long i, size;

size = atoi(argv[1]);
matrix = malloc(sizeof(float)*size);

for(i=0; i<size; i++) {
	matrix[i] = i*2;
}

for (i=0; i<size; i++) {
	printf("%f\n", matrix[i]);
}
	free(matrix);
	





return 0;

}


/*matrix*/
long* readMatrix(char *filename) {




}




