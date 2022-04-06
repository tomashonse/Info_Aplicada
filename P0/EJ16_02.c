#include <stdio.h>
#include <stdlib.h>

#define BitClear(a,b) ( (a) &= ~( 1<<(b) ) )
#define BitCheck(a,b) ( (a) & ( 1<<(b) ) )

enum band{
	AM = 0,
	FM = 1
};

int get_sythesizer_divider(unsigned char a){
	int b = (int)a;

	BitClear(b, 0);
	BitClear(b, 6);
	BitClear(b, 7);

	return (b >> 1)+1;
}

int get_band(unsigned char a){
	return (a & 0b01000000) ? FM : AM;
}


int main(){

	unsigned char a = 0b11111111; //
	printf("%d\n", get_sythesizer_divider(a));

	if(get_band(a)){
		printf("FM");
	} else{
		printf("AM");
	}

	return 0;
}
