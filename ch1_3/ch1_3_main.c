#include <stdio.h>

extern int subnum(int a, int b);

int main(){
	int sum;

	sum = subnum(1, 5);
	printf("sub 1,5 = %d\n", sum);
}
