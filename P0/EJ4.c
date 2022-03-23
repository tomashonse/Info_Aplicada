#include <stdlib.h>
#include <stdio.h>
void ej_a(){
	int n;
	printf("Ingrese el orden de la matriz\n");
	scanf("%d", &n);
	double aux, tr = 0;
	for(int i = 0; i < n; i++){
		printf("Ingrese el elemento de la posicion (%d, %d)\n", i+1, i+1);
		scanf("%lf", &aux);
		tr += aux;
	}
	printf("La traza de la matriz es: %f\n", tr);
}
void ej_b(){
	int m, n;
	printf("Ingrese la cantidad de renglones de la matriz\n");
	scanf("%d", &m);
	printf("Ingrese la cantidad de columnas de la matriz\n");
	scanf("%d", &n);
	double *matrix;
	matrix = malloc(m*n*sizeof(double));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			printf("\nIngrese el elemento de la posicion (%d, %d)\n", i+1, j+1);
			scanf("%lf", &matrix[i*n+j]);
		}
	}
	printf("\nMatriz transpuesta");
	for(int i=0; i < n; i++){
		printf("\n|\t");
	    for(int j=0; j < m; j++){
	    	printf("%lf\t",matrix[n*j+i]);
	    }
	}
	free(matrix);
}
void ej_c(){
	int m1, n1, m2, n2;
	printf("Ingrese la cantidad de renglones de la primera matriz\n");
	scanf("%d", &m1);
	printf("Ingrese la cantidad de columnas de la primera matriz\n");
	scanf("%d", &n1);
	printf("Ingrese la cantidad de renglones de la segunda matriz\n");
	scanf("%d", &m2);
	printf("Ingrese la cantidad de columnas de la segunda matriz\n");
	scanf("%d", &n2);
	if(n1 == m2){
		double **matrix1, **matrix2, **matrix_result;
		matrix1 =(double**)calloc(m1, sizeof(double*));
		for(int i = 0; i < m1; i++){
			matrix1[i] = (double*)calloc(n1, sizeof(double));
		}
		matrix2 = (double**)calloc(m2, sizeof(double*));
		for(int i = 0; i < m2; i++){
			matrix2[i] = (double*)calloc(n2, sizeof(double));
		}
		matrix_result = (double**)calloc(m2, sizeof(double*));
		for(int i = 0; i < m2; i++){
			matrix_result[i] = (double*)calloc(n1, sizeof(double));
		}
		for(int i = 0; i < m1; i++){
			for(int j = 0; j < n1; j++){
				printf("Ingrese el elemento (%d, %d) de la primera matriz\n", i+1, j+1);
				scanf("%lf", &matrix1[i][j]);
			}
		}
		for(int i = 0; i < m2; i++){
			for(int j = 0; j < n2; j++){
				printf("Ingrese el elemento (%d, %d) de la segunda matriz\n", i+1, j+1);
				scanf("%lf", &matrix2[i][j]);
			}
		}
		for(int i = 0; i < m1; i++){
			for(int j = 0; j < n2; j++){
				double temp = 0;
				for(int k = 0; k < n2; k++){
					temp += matrix1[i][k] * matrix2[k][j];
				}
				matrix_result [i][j] = temp;
			}
		}
		for(int i=0; i < m1; i++){
			printf("\n|\t");
			for(int j=0; j < n2; j++){
			    printf("%f\t",matrix_result[i][j]);
			}
		}
		for(int i = 0; i < m1; i++){
			free(matrix1[i]);
		}
		free(matrix1);
		for(int i = 0; i < m2; i++){
			free(matrix2[i]);
		}
		free(matrix2);
		for(int i = 0; i < m1; i++){
			free(matrix_result[i]);
		}
		free(matrix_result);
	} else{
		printf("Producto de matrices no valido\n");
	}
}
int main(void){
	setbuf(stdout, 0);
	int op;
	printf("\n1 - Calcular traza\n");
	printf("2 - Trasponer matriz\n");
	printf("3 - Producto de matrices\n");
	printf("Presione cualquier otra tecla para salir\n");
	scanf("%d", &op);
	while(op == 1 || op == 2 || op == 3){
		if(op == 1){
			ej_a();
		}
		if(op == 2){
			ej_b();
		}
		if(op == 3){
			ej_c();
		}
		printf("\n1 - Calcular traza\n");
		printf("2 - Trasponer matriz\n");
		printf("3 - Producto de matrices\n");
		printf("Presione cualquier otra tecla para salir\n");
		scanf("%d", &op);
	}
	printf("Fin del programa\n");
	return 0;
}
