#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void det_2(){
	double matrix[2][2];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			printf("Ingrese el elemento de la posición (%d, %d)\n", i, j);
			scanf("%lf", &matrix[i][j]);
		}
	}
	printf("%f", matrix[1][1]*matrix[2][2]-matrix[1][2]*matrix[2][1]);
}

void det_3(){
	double matrix[3][3];
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("Ingrese el elemento de la posición (%d, %d)\n", i, j);
			scanf("%lf", &matrix[i][j]);
		}
	}
	printf("%f", matrix[1][1]*matrix[2][2]*matrix[3][3] + matrix[1][2]*matrix[2][3]*matrix[3][1] + matrix[1][3]*matrix[2][1]*matrix[3][2] - matrix[3][1]*matrix[2][2]*matrix[1][3] - matrix[3][2]*matrix[2][3]*matrix[1][1] - matrix[3][3]*matrix[2][1]*matrix[1][2]);
}

int main(){

	int opc;

	printf("1 - Matriz orden 2\n");
	printf("2 - Matriz orden 3\n");
	scanf("%d", &opc);

	switch(opc){
	case 1:
		det_2();
		break;
	case 2:
		det_3();
		break;
	}

	return 0;
}
