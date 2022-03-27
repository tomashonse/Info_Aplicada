#include <stdio.h>
#include <stdlib.h>

//pone a 1 el bit b del número a
#define BitSet(a,b) ((a)|=(1<<(b)))
//pone a 0 el bit b del número a
#define BitClear(a,b) ( (a) &= ~( 1<<(b) ) )
//verifica si el bit b del número a es un 0 o un 1
// retorna el valor del bit (0 o 1)
#define BitCheck(a,b) ( (a) & ( 1<<(b) ) )
//cambia el bit b del número a por su valor complementario
//si el bit es 0 lo pone a 1 y si es 1 lo pone a 0
#define BitToggle(a,b) ( (a) ^= ( 1<<(b) ) )

int main(void){

	int a = 7, b = 7, c = 0;

	printf("BitSet 7 = 00000111, b = 7, retorna 135 = 10000111\n");
	printf("%d\n", BitSet(a, b));
	a = 7;
	printf("BitClear 7 = 00000111, c = 0, retorna 6 = 00000110\n");
	printf("%d\n", BitClear(a, c));
	a = 7;
	printf("BitCheck 7 = 00000111, c = 0, retorna un 1\n");
	printf("%d\n", BitCheck(a, c));

	a = 7;
	printf("BitToggle 7 = 00000111, c = 0, retorna 6 = 00000110\n");
	printf("%d\n", BitClear(a, c));

	return 0;
}
