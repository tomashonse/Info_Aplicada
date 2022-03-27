#include <stdio.h>
#include <stdlib.h>

int main(void){

	int x = 10, y = 20, z = 30, aux;

	printf("Los valores son x = %d y = %d z = %d", x, y, z);

	aux = z;
	z = y;
	y = x;
	x = aux;

	printf("\nAhora los valores son x = %d y = %d z = %d", x, y, z);

	return 0;
}
