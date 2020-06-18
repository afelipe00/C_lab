/*
 * BlinkUNO.c
 *
 * Created: 12/02/2019 5:18:36 p. m.
 * Author : Felipe Diaz
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
    // REGISTROS
	DDRD = 0xFF;
    while (1) 
    {
	    PORTD = 0xFF;
		_delay_ms(1000);
		PORTD = 0x00;
		_delay_ms(1000);
	}
	
}

