#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double **generador(int m, int n, float escalar){

	double **matrix;
	matrix = (double**)malloc(m*sizeof(double));
	for(int i = 0; i<m; i++){
		matrix[i] = (double*)malloc(n*sizeof(double));
	}
	// Carga de datos
	srand(time(NULL));
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = rand() % 1000000;
		}
	}
	return matrix;
}

double **producto_escalar(double **matrix, const float escalar, const int m, const int n){
	// Producto escalar
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			matrix[i][j] = escalar * matrix[i][j];
		}
	}
	return matrix;
}

void imprimir(double **matrix, const int m, const int n){

	printf("La matriz original de tamaño %i * %i es:\n", m, n);

	for(int i = 0; i < m; i++) {
		printf("|");
		for(int j = 0; j < n; j++){
			printf(" %lf \t", matrix[i][j]);
		}
		printf("| \n");
	}
}

int main(void){
	float escalar;
	int m, n;
	double **matriz;

	printf("Ingrese escalar, filas y columnas de la matriz\n");
	scanf("%f", &escalar);
	scanf("%d", &m);
	scanf("%d", &n);

	matriz = generador(m, n, escalar);

	imprimir(producto_escalar(matriz, escalar, m, n), m, n);

	return 0;
}
