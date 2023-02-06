#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

Matrix * createMat(size_t col, size_t row){
	Matrix *p = NULL;

	if( col == 0 || row ==0)
	{
		fprintf(stderr, " col or row euqal to zero\n");
		return false;
	}
	//allocate mem
	p = ( Matrix * )malloc(sizeof(Matrix));
	if( p==NULL ) 
	{
		fprintf(stderr, " Failed allocate mem for a matrix\n");
		return false;
	}
	p->col = col; p->row= row;
	p->data = ( float * )malloc( col * row * sizeof(float) ); 
	if( p->data == NULL )
	{
		fprintf(stderr, " Failed allocate mem for a matrix\n");
		free(p);
		return false;
	}
	return p;
}

bool delMat(Matrix *p)
{
	if( p == NULL ) 
	{
		fprintf(stderr, " Failed delete matrix ");
		return false;
	}
	if( p->data ) free(p->data);
	free(p);
	return true;	


}
bool initMat(Matrix *m1, size_t arrLen, const float *arr){
	
	size_t len = m1->col * m1->row;

	if(  arrLen > len )
	{
		fprintf(stderr, "in %s : param arr len exceed!\n",__FUNCTION__);
		return false;
	}
	//copy mat
	if( !memcpy(m1->data, arr, len*sizeof(float)) )
	{
		fprintf(stderr, "in %s : Failed mem copy\n",__FUNCTION__);
		return false;
	}
	return true;
}

bool addMat(const Matrix *m1, const Matrix *m2, Matrix *out){

	if( m1 == NULL || m1->data == NULL || m1->col == 0 || m1->row == 0)
	{
		fprintf(stderr," in %s Check the first param\n", __FUNCTION__);
		return false;
	}
	if( m2 == NULL || m2->data == NULL || m2->col == 0 || m2->row == 0)
	{
		fprintf(stderr," in %s Check the second param\n", __FUNCTION__);
		return false;
	}
	if(!MAT_SIZE_EQUAL(m1,m2) || !MAT_SIZE_EQUAL(m1,out))
	{
		fprintf(stderr," in %s MAT size not equal\n", __FUNCTION__);
		return false;
	}
	//add mat
	size_t len = m1->col * m1->row;
	const float *p1 = m1->data;
	const float *p2 = m2->data;
	float *p3 = out->data;

	for(size_t i = 0; i < len; i++)
	{
		*p3++ = *p1++ + *p2++;
	}

	return true;

}

bool mulMat(const Matrix *m1, const Matrix *m2, Matrix *out){

	MAT_TEST(m1)
	MAT_TEST(m2)
	MAT_TEST(out)	

	if( m1->col !=  m2->row || out->row != m1->row || out->col != m2->col)
	{
		fprintf(stderr, "in %s : Given mat are not multable\n",__FUNCTION__);
		return false;
	}
	//out = m1 .* m2
	


}

bool copyMat(Matrix *m1, Matrix *m2){

	if( !MAT_SIZE_EQUAL(m1,m2) )
	{
		fprintf(stderr, "in %s MAT szie not equal\n",__FUNCTION__);
		return false;
	}
	//copy mat
	if( !memcpy(m1, m2, m1->col * m1->row) )
	{
		fprintf(stderr, "in %s : Failed mem copy\n",__FUNCTION__);
		return false;
	}
	return true;
}


bool printMat( const Matrix *p )
{
	if( p == NULL )
	{
		fprintf(stderr, "printMat failed\n");
		return false;
	}
	printf("MAT:\n");
	for(size_t i = 0; i < p->row; i++)
	{
		for( size_t j = 0; j < p->col; j++ )
		{
			printf( "%f ", p->data[ i * p->col + j ] );
		}	
		printf("\n");
	}
	return true;
}

