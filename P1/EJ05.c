#include <stdio.h>
#include <stdlib.h>

void precios(float peso, float *precio){
	if(peso*(*precio) > 100){
		*precio = 0.9*(*precio);
	}
	printf("El gasto total es de: %.2f", peso*(*precio));
}

int main(){
	float peso = 10.0;
	float precio = 50.0;
	precios(peso, &precio);
	return 0;
}
