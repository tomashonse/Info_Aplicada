#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct TipoPunto{
	double abcisa; // x
	double ordenada; // y
}TipoPunto;
typedef struct TipoCiudad{
	TipoPunto situacion;
	char nombre[50];
}TipoCiudad;

void Reordenar (struct TipoCiudad ciudades[], int num_ciudades, const char nombre_ciudad_referencia[]) {
	int i,j,k;
	struct TipoCiudad temp;
	double distancia,dist;

	for( i=0; i<num_ciudades; i++){
		// Pone en primera posición a la ciudad de referencia
		if(strcmp(nombre_ciudad_referencia,ciudades[i].nombre)==0) {
			temp = ciudades[0];
			ciudades[0]=ciudades[i];
			ciudades[i]=temp;
			break;
		}
    }
	for(i=1;i<num_ciudades-1;i++){
        // distancia es la distancia entre la ciudad de referencia y la i-ésima ciudad
		distancia=sqrt(pow((ciudades[0].situacion.abcisa-ciudades[i].situacion.abcisa),2)+pow((ciudades[0].situacion.ordenada-ciudades[i].situacion.ordenada),2));
		k=i;
		for(j=i+1;j<num_ciudades;j++){
            // dist es la distancia entre la ciudad de referencia y la (i+1)-ésima ciudad
			dist=sqrt(pow((ciudades[0].situacion.abcisa-ciudades[j].situacion.abcisa),2)+pow((ciudades[0].situacion.ordenada-ciudades[j].situacion.ordenada),2));
			if(dist<distancia){
            	distancia=dist;
				k=j;
			}
		}
		temp=ciudades[i];
		ciudades[i]=ciudades[k];
		ciudades[k]=temp;
	}
}

int main(void){



	return 0;
}
