#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL46Z4.h"
#include "fsl_debug_console.h"

void retardo(int veces){
	for(int i = 0; i < veces; i++){
	}
}
int main(){

	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[29] |= PORT_PCR_MUX(1);
	PTE->PCOR |= 1<<29;
	PTE->PDDR |= 1<<29;

	for(;;){
		PTE->PCOR |= 1<<29;
		retardo(5000000);
		PTE->PSOR |= 1<<29;
		retardo(5000000);
	}
	return 0;
}
