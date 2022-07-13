#include "Own_Board.h"

enum {false, true};
typedef enum {off, on} states;

void delay(int n){
	for(int i = 0; i < n; i++){

	}
}

int main(){

	init_board();


	turn_off('g');
	turn_off('r');

	states actual = off;
	states next = off;
	int pulsado = off;

	while(true){

		switch(actual){
		case off:
			turn_off('r');
			turn_off('g');
			if(check('1')){
				pulsado = off;
			} else if(!(check('1'))){
				next = on;

			}
			break;
		case on:
			turn_on('r');
			delay(120000);
			turn_off('r');
			turn_on('g');
			delay(120000);
			turn_off('g');
			if(check('1')){
				next = off;
			}
			break;
		}

		if(actual != next){
			actual = next;
		}
	}

	return 0;
}
