#include "Own_Board.h"

enum boolean {false, true};

enum states {off, on};
int encendido = 0;
int presionado = 0;

int main(){

	init_board();

	turn_off('g');
	turn_off('r');

	while(true){
		if(!(check('1')) && presionado == 0){
			turn_on('r');
			encendido = on;
		}

		if(check('1') && encendido == on){
			presionado = 1;
		}

		if(!(check('2')) && presionado == 1){
			turn_off('r');
			encendido = off;
		}

		if(check('2') && encendido == off){
			presionado = 0;
		}


	}
	return 0;
}

