#include <stdio.h>
#include <stdlib.h>

// Parte a

#ifdef TRUE
#undef TRUE
#define TRUE 1
#endif

// Parte b
#if (TRUE == 1)
	#undef TRUE
	#define TRUE 2
#endif

// Parte c
#ifndef TRUE
#define TRUE 1
#else
#undef TRUE
#define TRUE 1
#endif


int main(void){

	return 0;
}
