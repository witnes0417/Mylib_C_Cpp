#include <stdio.h>

int main() {
	int a=1, b=2;
	int c=0;
	c=a++||b++;

	printf("a:%d,b:%d,c:%d",a,b,c);
}

