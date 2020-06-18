/*
 * PWMdelay.c
 *
 * Created: 18/02/2019 10:08:12 a. m.
 * Author : Felipe Diaz
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define periodo 1000

int timer = periodo/2;

void my_delay(int limit){
	for(int i = 0 ;i<=limit;i++){
		_delay_us(periodo/100);
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRB = 0x00;//input
	DDRD = 0xFF;//output
    while (1) 
    {
			if(PINB & (1<<PINB0) && (timer > 1)){
				timer--;
			}
			if(PINB & (1<<PINB1) && (timer < (periodo - 1))){
				timer++;
			}
			PORTD = 0x00;
			my_delay(periodo - timer);
			PORTD = 0xFF;
			my_delay(timer);
			
    }
}

