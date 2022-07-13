#include <Own_Board.h>

typedef enum {false, true} bool;
typedef enum {off, blink}states;

#define var 10000


int main(){

a	init_board();
	turn_off('r');
	turn_off('g');

	int time = 100000;
	states actual = off;
	states next = off;
	bool sw1 = false;
	bool sw3 = false;

	while(true){
		switch(actual){
		case off:
			if(check('1') && sw1 == false){
				next = blink;
			}
			break;
		case blink:
			if(check('1') && sw1 == false){
				time-=var;
				if(time < 0){
					time = 0;
				}
			}
			if(check('2') && sw3 == false){
				time+=var;
			}
			toggle('g');
			delay(time);
			toggle('r');
			delay(time);

		}
		if(actual != next){
			actual = next;
		}
	}
}
