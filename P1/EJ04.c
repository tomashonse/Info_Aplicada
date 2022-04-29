#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *dias[] = {"lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"};

char* dias_semana(int n){
	return dias[n-1];
}

int main(){
	int dia = 3;
	printf("%d corresponde a %s", dia, dias_semana(dia));
	return 0;
}
