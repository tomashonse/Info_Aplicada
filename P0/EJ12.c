#include <stdio.h>
#include <stdlib.h>

#define BitCheck(a, b) ((a) & ( 1 << (b))) // Compara si en el bit b de a hay un 0 o un 1
#define BitToggle(a,b) ( (a) ^= ( 1<<(b) ) ) // Invierte el valor de la posicion b del bit a

 unsigned setbits(unsigned x, int p, int n, unsigned y){
	 unsigned x1 = x;
	 if(n <= p){
		 for(int i = p; i > p-n; i--){
			 if(BitCheck(x1, i) != BitCheck(y, i)){
				 BitToggle(x1, i);
			 }
		 }
	 } else{
		 printf("El valor de p debe ser numericamente mayor o igual al valor de n\n");
		 return 0;
	 }
	 return x1;
 }

int main(void){
	setbuf(stdout, 0);
	unsigned x = 147, y = 177;
	int p = 3, n = 3;
	printf("%d\n", setbits(x, p, n, y));
	return 0;
}
