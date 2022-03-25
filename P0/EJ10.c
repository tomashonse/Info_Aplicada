#include <stdio.h>
#include <stdlib.h>

#define BitCheck(a, b) ((a) & 	(1 << (b))) // Compara si en el bit b de a hay un 0 o un 1
#define BitSet(a,b) ( (a) |= ( 1<<(b) ) ) // Pone un 1 en el bit b de a

int paridad_par(int number){

	int modified, contador = 0;

	for(int i =0; i < 8; i++){ // Hay 8 bits por byte
		if(BitCheck(number, i)){ // If(1) == true, if(0) == false
			contador++;
		}
	}
	if(contador % 2 == 0){ // Si contador es par entonces el número tiene cantidad par de bits
		return number;
	} else {
		modified = BitSet(number, 7); // Si contador es impar tiene cantidad impar de bits por lo que le agrego 1 en el más significativo
		return modified;

	}
}

int main(void){
	setbuf(stdout, 0);
	printf("%d", paridad_par(7));
}
