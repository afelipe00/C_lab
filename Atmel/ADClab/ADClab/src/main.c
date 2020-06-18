 /**
 * \file
 *
 * \brief Empty user application template
 *
 */

/**
 * \mainpage User Application template doxygen documentation
 *
 * \par Empty user application template
 *
 * Bare minimum empty user application template
 *
 * \par Content
 *
 * -# Include the ASF header files (through asf.h)
 * -# "Insert system clock initialization code here" comment
 * -# Minimal main function that starts with a call to board_init()
 * -# "Insert application code here" comment
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
/*
 * Support and FAQ: visit <a href="https://www.microchip.com/support/">Microchip Support</a>
 */
#include <asf.h>

int *pio_per_c = 0x400E1200;//enable register
int *pio_oer_c = 0x400E1210;//output register
int *pio_sodr_c = 0x400E1230;// set output register
int *pio_codr_c = 0x400E1234;// clear output data
int *pio_pdr_b = 0x400E1004;
int *pio_pudr = 0x400E1060;

// adc
int *adc_cher = 0x400C0010;
int *adc_cr = 0x400C0000;
int *adc_mr = 0x400C0004;
int *adc_cdr = 0x400C0078;

//pmc
int *pmc_cer1 = 0x400E0700;
int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	sysclk_init();
	board_init();
	//PIO
	
	*pio_per_c = 0x000001FE;
	*pio_oer_c = 0x000001FE;
	//ADC
	*adc_cher = 0x00000400;
	*adc_cr = 0x00000002;
	*adc_mr = 0x0000FF80;
	//PMC
	*pmc_cer1 = 0x00000020;
	int lectura = 0;
	while(1){
		lectura = (*adc_cdr >> 3);
		*pio_sodr_c = lectura;
		*pio_codr_c =~lectura;
		delay_ms(1000);
	}
}
