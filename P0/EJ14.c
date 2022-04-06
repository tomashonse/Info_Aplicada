#include <stdio.h>
#include <stdlib.h>

int main(){

	int x = 1 , y = 3;
	printf("X = %d, Y = %d\n", x, y);

	x ^= y;
	y ^= x;
	x ^= y;

	printf("Ahora X = %d e Y = %d", x, y);
}
