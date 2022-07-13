#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL46Z4.h"
#include "fsl_debug_console.h"

void retardo(int n){
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

	/*pulsador SW1*/
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[3] |= PORT_PCR_MUX(1);
	PTC->PDDR &= ~(1 << 3);
	PORTC->PCR[3] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
	/*SW3*/
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[12] |= PORT_PCR_MUX(1);
	PTC->PDDR &= ~(1 << 12);
	PORTC->PCR[12] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

	uint8_t sw1 = 0;
	uint8_t sw3 = 0;

	PTE->PSOR |= 1 << 29;
	PTD->PSOR |= 1 << 5;

	while(1){
		if((!(PTC->PDIR & (1 << 3)) && sw1 == 0) && (!(PTC->PDIR & (1 << 12)) && sw3 == 0)){
			PTE->PTOR |= 1<<29;
			retardo(300000);
			PTE->PTOR |= 1<<29;

			PTD->PTOR |= 1<<5;
			retardo(300000);
			PTD->PTOR |= 1<<5;
		}
	}

	return 0 ;
}
