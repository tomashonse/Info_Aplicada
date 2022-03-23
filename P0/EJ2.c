#include <stdio.h>
#include <stdlib.h>

#define value 3

int main(void){

	setbuf(stdout, 0);

	int a[value], comparador;

	for(int i = 0; i < value; i++){
		printf("Ingrese el valor de la posicion %d del arreglo\n", i);
		scanf("%d", &a[i]);
	}

	printf("Ingrese el valor a comparar\n");
	scanf("%d", &comparador);
	while(comparador != 0){
		for(int j = 0; j < value; j++){
			if(a[j] == comparador){
				printf("El valor %d está en la posicion %d del arreglo\n", comparador, j);
			}
		}
		printf("Ingrese el valor a comparar\n");
		scanf("%d", &comparador);
	}


	return 0;
}
