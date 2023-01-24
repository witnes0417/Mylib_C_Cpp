#include "mylib.h"

void larger_of(double *x, double *y){
	if(*x > *y){
		*y=*x;
	}else{
		*x=*y;
	}
}

void test_delete_space(const char *str, int str_len){
	char sp[20]=""; // use malloc
	int n = 0, i;

	for(i=0;i < str_len;i++){
		if( str[i] != ' ' ) sp[n++] = str[i];
	}
	printf("str now is: %s\n",sp);
}


int is_within(const char *str, int str_len, char c){
	int i;

	for(i=0;i<str_len;i++){
		if(str[i] == c) return 1;	
		else continue;
	}

	return 0;
}

void sort_merge(int *a, int n){

	int *p1 ,*p2 ; 
	int tmp = 0,k=0, i=0, j=0;

	if(n == 2){
		if(a[0]>a[1]){
			tmp = a[0];
			a[0] = a[1];
			a[1] = tmp;
		}

		return;
	}	

	p1 = (int*)calloc(n/2,sizeof(int));
	p2 = (int*)calloc(n/2,sizeof(int));

	for(i=0;i<n/2;i++){
		p1[i] = a[i]; p2[i] = a[n/2+i]; 
	}

	sort_merge(p1,n/2);
	sort_merge(p2,n/2);

	i=0;
	for(k=0;k<n;k++){
		if(p1[i] < p2[j]){
			a[k] = p1[i]; i++;
		}else{
			a[k] = p2[j]; j++;
		}

		if(i==n/2 && j<n/2){
			for(;j<n/2;j++,k++){
				a[k] = p2[j];
			}
			return;
		}

		if(j==n/2 && i<n/2){
			for(;i<n/2;i++){
				a[++k] = p1[i];
			}
			return;
		}
	}

	free(p1); free(p2);

}


void find_nMin(int *arr,int n){
		
}



int find_subStringNum(char const *p1, char const *p2){
	int tlen = strlen(p1),sublen = strlen(p2);
	int i =0, j=0, num=0, c=0;

	if(sublen > tlen) return num;

	for(i=0;i<tlen;i++){
		if( p1[i] == p2[j]){
			if(++c == sublen){
				num++; c=0;
			}		
			if(++j > sublen -1 ) j=0;
		}else{
			if(sublen >= tlen -i ) return num;
			i+=c;
		}
	}

	return num;
}


void  mult_recur(uint64_t *a, uint64_t *b, int n, uint64_t *res){

	uint32_t  i =0, m = (uint32_t)(n/sizeof(uint64_t));
	uint64_t temp;

	if(n == 1) *res +=  (*a&1) * (*b&1);

	for(i=0; i <= m/2; i++){
		mult_recur( &a[i], &b[i],n/2,res);
		
	}

	for(i=m/2; i <= m; i++){
		mult_recur( &a[i], &b[i],n/2,res);
	}

	/* add result */
	for(i=0; i <= m; i++){
		temp = res[i] + res[i+m];
		if(temp < res[i]) {
			res[i+1]++;
			res[i] = temp;
		}
	}

}

/* t for target arr, n for arr element num */
/* m for bit len, d for dierction, l for move bit len */

void arr_bitMove(void *pArr, uint32_t n, uint32_t m, enum direc d, uint32_t l){

	char *p =(char *)pArr, tempc;
	/* b for char arr element num */
	uint32_t b = n*(m/8),
			 a = l/8, c=l%8,pbit;

	/* special case */
	if(a != 0){

		for(uint32_t i =0; i<b-a; i++){
			if(d == Right){
				p[i] = p[i+1]; 
			}else{
				p[b-i-1] = p[b-i-2];		
			}
		}

		for(uint32_t i =0; i<a; i++){
			if(d == Right){
				p[b-i-1] =0; 
			}else{
				p[i] = 0;
			}
		}
	}
	/* implement move */

	tempc =0;
	pbit =0;
	d=0;
	for(uint32_t i =0; i<c; i++){
		for(uint32_t j=0; j<b-a; j++){
			if(d == Right){
				tempc = p[b-1-a-j];
				tempc>>= 1; tempc|=pbit;
				if( (p[b-1-a-j]&1) == 1){
					 pbit  = 1<<7 ; 
				}else pbit =0;
				p[b-1-a-j] = tempc;
			}else{
				tempc = p[a+j];
				tempc <<= 1; tempc|=pbit;
				if( (p[a+j] & 1<<7) == 1){
					 pbit  = 1;
				}else pbit =0;
				p[a+j] = tempc;
			}
		}	
	}
}

void arr_mult(){

}

void arr_add(){

}

/* void mult_Karatsuba(uint64_t x, uint64_t y,int n, uint64_t *res){ */
/*  */
/* 	uint64_t mask = ((uint64_t)1<<(n/2))-1; */
/* 	uint64_t a,b,c,d,p,q; */
/* 	uint32_t m = (uint32_t)(n/sizeof(uint64_t)); */
/* 	uint64_t *z0 = (uint64_t *)calloc(m,sizeof(uint64_t)), */
/* 			 *z1 = (uint64_t *)calloc(m,sizeof(uint64_t)), */
/* 			 *z2 = (uint64_t *)calloc(m,sizeof(uint64_t)); */
/*  */
/* 	if(n == 1){ */
/* 		*res = x*y; */
/* 		return;	 */
/* 	} */
/*  */
/* 	a = x>>n/2; b = x&mask;  */
/* 	c = y>>n/2; d = y&mask; */
/* 	p = a+b; q = c+d; */
/*  */
/* 	mult_Karatsuba(p,q,n/2,z0); */
/* 	mult_Karatsuba(a,c,n/2,z1); */
/* 	mult_Karatsuba(b,d,n/2,z2); */
/*  */
/* 	for(uint32_t i = 0; i < m; i++){ */
/* 		res[i] = z1[i] << n */
/* 	} */
/*  */
/* 	return ((z1<<n) + ((z0-z1-z2)<<n/2) + z2); */
/* 	 */
/* } */
/*  */

__int128 mult_Karatsuba(uint64_t x, uint64_t y,int n){

	uint64_t mask = ((uint64_t)1<<(n/2))-1;
	__int128 a,b,c,d,p,q;
	__int128 z0,z1,z2; 

	if(n == 1)return x*y;

	a = x>>n/2; b = x&mask; 
	c = y>>n/2; d = y&mask;
	p = a+b; q = c+d;

	z0=mult_Karatsuba(p,q,n/2);
	z1=mult_Karatsuba(a,c,n/2);
	z2=mult_Karatsuba(b,d,n/2);

	return ((z1<<n) + ((z0-z1-z2)<<n/2) + z2);
}





int main(int argc, char* argv[]){
	//	char input[100];

	//	double x=133.123e32, y= 133.122e31;
	//	larger_of(&x,&y);
	//
	//	printf("x,y : %g,%g",x,y);
	//	 
	//    while (1) {
	//        printf("请输入字符串：");
	//        scanf(" %[^\n] ", input);
	//		gets(input);
	//		printf("the input str is：%s\n",input);
	//		printf("len is: %d\n", (int)strlen(input));
	//		test_delete_space(input, strlen(input));
	//        if (strlen(input) == 0) {
	//            break;
	//		}
	//	}
	
	/* merge sort test */
	/* int arra[8]= {1,9,4,7,2,9,1,2}; */
	/* int i=0; */
    /*  */
	/* printf("arr:"); */
	/* for(i=0;i<(int)(sizeof(arra)/sizeof(int));i++){ */
	/* 	printf(" %d",arra[i]); */
	/* } */
    /*  */
	/* sort_merge(arra,8); */
    /*  */
	/* printf("\nsorted arr:"); */
	/* for(i=0;i<(int)(sizeof(arra)/sizeof(int));i++){ */
	/* 	printf(" %d",arra[i]); */
	/* } */

	/* enum A {apple, pear, orange}; */
	/* printf("%d",); */

	/* uint64_t a = 1111111111111111111 , b = 11111111111111111; */
	/* char *c; */
	/* __int128 d; */
    /*  */
	/* d = mult_Karatsuba(a,b,64); */
	/* c = (char *)&d; */
	/* for(int i =0; i<16;i++){ */
	/* 	printf("%02x", *(c+15-i)&0xff); */
	/* }	 */


	/* char a[] = "aaabbbaacccaaaa"; */
	/* char b[] = "aa"; */
	/* printf("aa in array:%d",find_subStringNum(a,b)); */


	return 0;
}




