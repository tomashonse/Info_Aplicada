#include <stdio.h>
#include <stdlib.h>

unsigned get_bits(unsigned x, int p, int n){
	// Creo una máscara de n bits
	char mask = (1 << n) - 1; // Esto devuelve una máscara de n bits, por ejemplo si n=3 devuelve 0000 0111

	// Ahora comparo con el vector x shifteado p posiciones a la derecha y devuelvo el valor.
	return (x >> p) & mask;
}

int main(){

	unsigned x = 12;
	int p = 4, n = 3;

	printf("%d", get_bits(x, p, n));

	/*
	 	 x = 12 = 0000 1100
	 	 mask = (1 << 3) - 1 -> 0000 1000 - 0000 0001 = 0000 0111
	 	 x >> p = x >> 4 -> 0000 0000
	 	 0000 0000 & 0000 0111 = 0000 0000
	 	 Retorna 0
	 */

	return 0;
}

