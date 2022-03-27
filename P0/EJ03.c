#include <stdio.h>
#include <stdlib.h>

#define dias 5

int main(void){

	setbuf(stdout, 0);

	int lluvia[dias], mayor = 0, menor, dia_mayor, dia_menor, acc = 0;
	float prom;

	for(int i = 0; i < dias; i++){
		printf("\nIngrese los mm de lluvia del dia %d del mes\n", i+1);
		scanf("%d", &lluvia[i]);
		acc += lluvia[i];
	}
	menor = lluvia[1];
	prom = (float)acc/dias;

	for(int j = 0; j < dias; j++){
		if(lluvia[j] > mayor){
			mayor = lluvia[j];
			dia_mayor = j+1;
		}
		if(lluvia[j] < menor){
			menor = lluvia[j];
			dia_menor = j+1;
		}
	}
	printf("\nPromedio: %f\n", prom);
	printf("\nEl dia de mayor lluvia fue el %d y llovio %dmm\n", dia_mayor, mayor);
	printf("\nEl dia de menor lluvia fue el %d y llovio %dmm\n", dia_menor, menor);
	return 0;
}
