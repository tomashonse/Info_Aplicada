#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ej_a(char *cadena){
	for(int i = 0; i < 100; i++){
		if(cadena[i] != ' '){
			printf("%c", cadena[i]);
		} else{
			printf("\n");
		}
	}
}

void ej_b(char *cadena){
	char *token;

	token = strtok(cadena, " ");

	while(token != NULL){
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}

int main(void){

	char cadena[100] = "After all this time?";
	int opc;

	printf("1 - Sin libreria");
	printf("2 - Con libreria");
	printf("0 para salir");
	scanf("%d", &opc);
	while(opc != 0){
		if(opc == 1){
			ej_a(cadena);
		} else if(opc == 2){
			ej_b(cadena);
		}
		printf("1 - Sin libreria");
		printf("2 - Con libreria");
		printf("0 para salir");
		scanf("%d", &opc);
	}
	return 0;
}

