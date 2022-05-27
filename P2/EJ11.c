#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum vt {v1=1200,v2=2400,v3=4800,v4=9600} VT;

int main(){

	printf("\nUso de la enumeracion: ");
	printf("\nv1 = %d", v1 );
	printf("\nv2 = %d", v2 );
	printf("\nv3 = %d", v3 );
	printf("\nv4 = %d", v4 );

	getchar();
	return 0;
}
