#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main(){
	setbuf(stdout, 0);
	int dimension;
	printf("Ingrese la dimension del arreglo, debe ser menor a %d. Pulse 0 para salir\n", DIM);
	scanf("%d", &dimension);
	float *a;
	a = malloc(dimension*sizeof(float));
	for(int i = 0; i < dimension; i++){
		printf("Ingrese el elemento de la posicion %d\n", i);
		scanf("%f", (a+i)); // Aca ya tengo una dirección, entonces no tengo que poner & ni *
	}
	for(int i = dimension-1; i >= 0; i--){
		printf("%.2f\n", *(a+i)); // Acá pongo el * porque necesito el contenido de la variable
	}
	return 0;
}
