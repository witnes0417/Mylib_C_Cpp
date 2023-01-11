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
	int arra[8]= {1,9,4,7,2,9,1,2};
	int i=0;

	printf("arr:");
	for(i=0;i<(int)(sizeof(arra)/sizeof(int));i++){
		printf(" %d",arra[i]);
	}

	sort_merge(arra,8);

	printf("\nsorted arr:");
	for(i=0;i<(int)(sizeof(arra)/sizeof(int));i++){
		printf(" %d",arra[i]);
	}

	return 0;
}




