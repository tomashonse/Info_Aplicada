#include "Own_Board.h"

enum boolean {false, true};

typedef enum {off, on} states;

int main(){

	init_board();

	turn_off('g');
	turn_off('r');

	states actual = off;
	states next = off;

	int presionado = off;

	while(true){

		switch(actual){
		case off:
			turn_off('r');
			if(check('1')){
				presionado = off;
			} else if(!(check('1')) && presionado == off){ // !(check('1')) = 1 && (presionado == off) = 1
				next = on;
				presionado = on;
			}
			break;
		case on:
			turn_on('r');
			if(check('1')){
				presionado = off;
			} else if(!(check('1')) && presionado == off){
				next = off;
				presionado = on;
			}
			break;
		}
		if(actual != next){
			actual = next;
		}
	}
	return 0;
}
