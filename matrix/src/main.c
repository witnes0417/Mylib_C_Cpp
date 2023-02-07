#include "matrix.h"
#include <stdio.h>

#include <stdio.h>

int main(int argc, char* argv[]){

	Matrix *m1 = createMat(3,4);
	Matrix *m2 = createMat(3,4);
	Matrix *m3 = createMat(3,4);
	Matrix *m4 = createMat(4,4);
	Matrix *m5 = NULL;
	Matrix *m6 = createMat(3,3);
	Matrix *m7 = createMat(3,3);
	Matrix *m8 = createMat(3,3);

	float arr[12] = {1,2,3,4,5,6,7,8,9,10,11,12};

	initMat(m1,12,arr);
	initMat(m2,12,arr);
	initMat(m6,6,arr);
	initMat(m7,6,arr);
	printMat(m1);
	printMat(m6);

	mulMat(m6,m7,m8);
	printMat(m8);

	addMat(m1,m2,m3);	
	printMat(m3);
	addMat(m1,m2,m4);
	printMat(m5);

	return 0;
}
