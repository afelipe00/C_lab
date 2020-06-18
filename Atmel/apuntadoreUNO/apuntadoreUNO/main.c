/*
 * apuntadoreUNO.c
 *
 * Created: 25/02/2019 8:01:07 p. m.
 * Author : Felipe Diaz
 */ 
#define  F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>


int main(void)
{
	int *ptr_ddrd = 0x2A;//DDRD
	int *ptr_portd = 0x2B;//PORTB
    /* Replace with your application code */
    while (1) 
    {
		*ptr_portd |= 0xFF;
		_delay_ms(1000);
		*ptr_portd |= 0x00;
		_delay_ms(1000);
    }
}

