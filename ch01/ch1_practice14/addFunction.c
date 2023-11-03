#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	if(argc != 3){
		printf("NOT AVAILABLE PARAMETER!!\n");
		return -1;
	}
	int num1 = atoi(argv[1]);
	int num2 = atoi(argv[2]);
	int sum = 0;
	for(int i = num1; i<=num2; i++){
		sum+=i;
	}
	printf("ans = %d\n", sum);
	return 0;
}
		
