#include <stdio.h>
#include <stdlib.h>

int rojo(unsigned int a){
	return (a >> 16);
}

char verde(unsigned int a){
	return (a >> (8)) & ~ (~0 << 16);
}

char azul(unsigned int a){
	return (a >> (0)) & ~ (~0 << 8);
}

void componentesRGB(unsigned int a){
	printf("Cantidad de rojo: %d\n", rojo(a));
	printf("Cantidad de verde: %d\n", verde(a));
	printf("Cantidad de azul: %d\n", azul(a));
}

int main(){
	unsigned int a = 0xAFB23C; // 0xRRGGBB

	componentesRGB(a);

	return 0;
}

