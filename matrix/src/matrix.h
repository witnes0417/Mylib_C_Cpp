#ifndef _MATRIX_H
#define _MATRIX_H

#define MAT_SIZE_EQUAL(m1,m2) (m1->row == m2->row && m1->col == m2->col)
#define MAT_TEST(mat) \
if( mat == NULL || mat->data == NULL || mat->col == 0 || mat->row == 0)\
{\
	fprintf(stderr," in %s : Passed mat is not qualified, pls check.\n", __FUNCTION__);\
	return false;\
}
#define MAT_MULTABLE(m1,m2,out) \
if( m1->col !=  m2->row || out->row != m1->row || out->col != m2->col)\
{\
	fprintf(stderr, "in %s : Given mat are not multable\n",__FUNCTION__);\
	return false;\
}

#include <stdbool.h>
#include <stddef.h>

typedef struct Matrix{
	size_t col;
	size_t row;
	float *data;
} Matrix;

Matrix * createMat(size_t col, size_t row);
bool delMat(Matrix *p);
bool initMat(Matrix *m1, size_t arrLen, const float *arr);
bool copyMat(Matrix *m1, Matrix *m2);
bool addMat(const Matrix *m1, const Matrix *m2, Matrix *out);
bool printMat(const Matrix *p);
bool mulMat(const Matrix *m1, const Matrix *m2, Matrix *out);

#endif
