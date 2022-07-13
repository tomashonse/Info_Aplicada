#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL46Z4.h"
#include "fsl_debug_console.h"
#include "Own_Board.h"

void init_board(){
	// Green led
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	PORTD->PCR[5] |= PORT_PCR_MUX(1);
	PTD->PCOR |= 1 << 5;
	PTD->PDDR |= 1 << 5;

	//Red led
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;
	PORTE->PCR[29] |= PORT_PCR_MUX(1);
	PTE->PCOR |= 1 << 29;
	PTE->PDDR |= 1 << 29;

	//SW1

	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[3] |= PORT_PCR_MUX(1);
	PTC->PDDR &= ~(1 << 3);
	PORTC->PCR[3] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;

	//SW3

	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
	PORTC->PCR[12] |= PORT_PCR_MUX(1);
	PTC->PDDR &= ~(1 << 12);
	PORTC->PCR[12] |= PORT_PCR_PE_MASK | PORT_PCR_PS_MASK;
}

void turn_on(char op){
	if(op == 'r' || op == 'R'){
		PTE->PCOR |= 1<<29;
	} else if(op == 'g' || op == 'G'){
		PTD->PCOR |= 1<<5;
	}
}

void turn_off(char op){
	if(op == 'r' || op == 'R'){
		PTE->PSOR |= 1<<29;
	} else if(op == 'g' || op == 'G'){
		PTD->PSOR |= 1<<5;
	}
}

void toggle(char op){
	if(op == 'r' || op == 'R'){
			PTE->PTOR |= 1<<29;
		} else if(op == 'g' || op == 'G'){
			PTD->PTOR |= 1<<5;
		}
}

void delay(int n){
	for(int i = 0; i < n; i++);
}

int check(char op){
	int ret;
	if(op == 'r' || op == 'R'){
		ret = PTE->PDIR & 1<<29;
	} else if(op == 'g' || op == 'G'){
		ret = PTD->PDIR & 1<<5;
	}
	if(op == '1'){
		ret = !(PTC->PDIR & 1<<3);
	} else if(op == '2'){
		ret = !(PTC->PDIR & 1<<12);
	}
	return ret;
}
