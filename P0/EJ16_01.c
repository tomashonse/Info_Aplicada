#include <stdio.h>
#include <stdlib.h>

unsigned char Set(unsigned char Datos, short Linea){

	char mask = (1 << Linea) - 1;

	return Datos |= mask;
}

unsigned char Clear(unsigned char Datos, short Linea){

	char mask = (1 << Linea);

	return Datos ^ mask;
}

int main(){

	unsigned char Datos = 35;
	short Linea = 3;

	printf("%d\n", Set(Datos, Linea));

	/*

		Datos = 35 = 0010 0011
		Linea = 3
		return -> 39

	*/
	Datos = 155;
	Linea = 4;
	printf("%d", Clear(Datos, Linea));
	/*

	  	Datos = 155 = 1001 1011
		Linea = 4
		return -> 1000 1011 = 139



	 */


	return 0;
}
