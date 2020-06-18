/*
 * maquinaestados1.c
 *
 * Created: 13/02/2019 1:20:45 p. m.
 * Author : Felipe Diaz
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    //inicio de registros
	DDRB = 0x00;//input
	DDRD = 0xFF;//output
	//delaracion e incializacion de variables
	int state = 0;
    while (1) 
    {
		switch(state){
			case 0:
				if(PINB & (1<<PINB0)){
					PORTD = 0b00000111;
					state = 1;
					while(PINB & (1<<PINB0)){}
				}
				break;
			case 1:
				if(PINB & (1<<PINB1)){
					PORTD = 0b00011000;
					_delay_ms(2000);
					PORTD = 0b00010000;
					state = 2;
					while(PINB & (1<<PINB1)){}
				}
				break;
			case 2:
				if(PINB & (1<<PINB2)){
					PORTD = 0b10000000;
					_delay_ms(2000);
					PORTD = 0b00000111;
					state = 3;
					while(PINB & (1<<PINB2)){}
				}
				break;
			default:
				break;
		}
		if(PINB & (1<<PINB3)){
			PORTD = 0b00000000;
			state = 0;
			while(PINB & (1<<PINB3)){}
		}
    }
}

