#include <stdio.h>
#include <stdlib.h>

#define MINIMO2(A, B) (A < B) ? A : B
#define MINIMO3(A, B, C) (MINIMO2(A, B) < C) ? MINIMO2(A, B) : C

int main(void) {
printf("%d", MINIMO2(5,3));
printf("%d", MINIMO3(7,3,4));

	return 0;

}
