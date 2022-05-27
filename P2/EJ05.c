#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int m, n;
	int **coef;
}matrix;

matrix init(matrix matriz){

    printf("Ingrese la cantidad de filas\n");
    scanf("%d", &matriz.m);
    printf("Ingrese la cantidad de columnas\n");
    scanf("%d", &matriz.n);

    matriz.coef = calloc(matriz.m, sizeof(int));
    for(int i = 0; i < matriz.m; i++){
    	matriz.coef[i] = calloc(matriz.n, sizeof (int));
    }

    for(int i = 0; i < matriz.m; i++){
        for(int j = 0; j < matriz.n; j++){
            matriz.coef[i][j] = rand() % 10000;
        }
    }

    return matriz;
}
matrix suma(matrix m1, matrix m2){
    matrix result;
    if((m1.m == m2.m) & (m1.n == m2.n)){
        // La suma de matrices solo es válida si tienen la misma dimensión
        // La suma de matrices se realiza componente a componente

        result.m = m1.m;
        result.n = m1.n;

        result.coef = calloc(result.m, sizeof(int));
        for(int i = 0; i < result.m; i++){
        	result.coef[i] = calloc(result.n, sizeof (int));
        }

        for(int i = 0; i < result.m; i++){
            for(int j = 0; j < result.n; j++){
                result.coef[i][j] = m1.coef[i][j] + m2.coef[i][j];
            }
        }
    }
    else{
        printf("Error las dimensiones deben ser iguales\n");
        exit(-1);
    }
    return result;
}

int main(){

    setbuf(stdout, 0);
    srand(time(NULL));

	matrix m1, m2, result;

    m1 = init(m1);
    m2 = init(m2);

    result = suma(m1, m2);

    printf("\n\nResultado");
	for(int i=0; i < result.m; i++){
		printf("\n|\t");
		for(int j=0; j < result.n; j++){
			printf("%d\t",result.coef[i][j]);
		}
		printf("|");
	}
    free(result.coef);
    free(m1.coef);
    free(m2.coef);


	return 0;
}
