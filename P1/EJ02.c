/*
 Escriba un programa que defina las siguientes variables:
 int i=5, j[]={1,2,3,4,5,6,7,8,9,10};
char x = 'a', pal [] ="texto en c";
int *pi;
char *pc;
	1. Mostrar la dirección de “i” y su valor.
	2. Mostrar los mismos valores a través del puntero “pi”.
	3. Recorrer el vector “j” mostrando para cada elemento, su dirección y su valor.
	4. Recorra el vector accediendo a través del puntero “pi” y usando álgebra de
		punteros.
	5. Repita lo mismo con las variables char, el arreglo y el puntero.
	6. Finalmente muestre la dirección donde se almacenan ambos punteros.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int i = 5, j[]={1,2,3,4,5,6,7,8,9,10};
	char x = 'a', pal [] ="texto en c";
	int *pi;
	char *pc;
	printf("Mostrar la dirección de 'i' y su valor\n");
	printf("%p %d\n", &i, i);


	printf("Ahora usando punteros\n");
	pi = &i;
	printf("%p %d\n", pi, i);

	printf("Ahora recorrer el vector 'j' mostrando cada elemento, su dirección y su valor\n");
	for(int k = 0; k < 10; k++){
		printf("Elemento: %d Direccion: %p Valor: %d\n", k, &j[k], j[k]);
	}

	printf("Recorrer el vector accediendo a traves del puntero pi y usando el algebra de punteros\n");
	for(int k = 0; k < 10; k++){
		pi = &*(j+k);
		printf("Elemento %d Direccion: %p Valor: %d\n", k, pi, *(j+k));
	}

	printf("Ahora repito el proceso con los strings\n");
	printf("Mostrar la direccion de 'x' y su valor\n");
	printf("%p %c\n", &x, x);

	printf("Ahora usando punteros\n");
	pc = &x;
	printf("%p %c\n", pc, x);

	printf("Ahora recorrer el string 'pal' mostrando cada elemento, su direccion y su valor\n");
	for(int k = 0; k < strlen(pal); k++){
		printf("Elemento: %d Direccion: %p Valor: %c\n", k, &pal[k], pal[k]);

	}

	printf("Recorrer el string accediendo a traces del puntero pc y usando el algebra de punteros\n");
	for(int k = 0; k < strlen(pal); k++){
			pc = &*(pal+k);
			printf("Elemento %d Direccion: %p Valor: %c\n", k, pc, *(pal+k));
		}
	int **ppi;
	char **ppc;
	ppi = &pi;
	ppc = &pc;
	printf("Direccion de *pi: %p\n", ppi);
	printf("Direccion de *pc: %p\n", ppc);

	return 0;
}
