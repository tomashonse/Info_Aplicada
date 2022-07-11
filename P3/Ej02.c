#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL46Z4.h"
#include "fsl_debug_console.h"

#define TRUE 1
#define FALSE 0

void retardo (int n){
	for(int i = 0; i < n; i++){
	}
}

int main(void) {

	/*led VERDE*/
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTD->PCR[5] |= PORT_PCR_MUX(1);
	PTD->PCOR |= 1 << 5;
	PTD->PDDR |= 1 << 5;

	/*led ROJO*/
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[29] |= PORT_PCR_MUX(1);
	PTE->PCOR |= 1 << 29;
	PTE->PDDR |= 1 << 29;

	while(TRUE){
		PTE->PTOR |= 1<<29;
		retardo(300000);
		PTE->PTOR |= 1<<29;

		PTD->PTOR |= 1<<5;
		retardo(300000);
		PTD->PTOR |= 1<<5;
	}

    return 0 ;
}
