#include <stdio.h>
#include <stdlib.h>

#define BitClear(a,b) ( (a) &= ~( 1<<(b) ) )

int solve (int x){
	BitClear(x, 7);
	BitClear(x, 0);
	int contador = 0;
	if (x ^ 0){
		contador++;
	}
	if(contador != 0){
		return 1;
	} else{
		return 0;
	}
}

int main(){

	int x = 35;

	printf("%d", solve(x));

	return 0;
}
