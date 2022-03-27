#include <stdio.h>
#include <stdlib.h>

unsigned rightRot(unsigned x, int n){

	for(int i = 0; i < n; i++){
		x = x >> 1;
	}

	return x;
}

int main(void){

	printf("%d", rightRot(123, 2));

	return 0;
}
