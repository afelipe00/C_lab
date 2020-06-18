/*
 * 8leds.c
 *
 * Created: 10/02/2019 9:02:19 p. m.
 * Author : Felipe Diaz
 */ 

#define F_CPU 160000000L
#include <avr/io.h>
#include <util/delay.h>

int main(void){
    //definir registros
	DDRB = 0x00;//input
	DDRD = 0xFF;//output
	int x = 00000000;
	while (1) {		
		if(PINB & (1<<PINB0)){//singifica si esta encendido(0 pin)
			x++;
			while(PINB & (1<<PINB0)){}
		}else if(PINB & (1<<PINB1)){//singifica si esta encendido(1 pin)
			x--;
			while(PINB & (1<<PINB1)){}
		}else if (PINB & (1<<PINB2)){//singifica si esta encendido(2 pin)
			x = x*2;
			while(PINB & (1<<PINB2)){}
		}else if(PINB & (1<<PINB3)){//singifica si esta encendido(3 pin)
			x = x/2;
			while(PINB & (1<<PINB3)){}
		}
		PORTD = x;	
	}
}

