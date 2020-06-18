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

int *DACC_MR = 0x400C8004;//modo de habilitacion del dacc
int *DACC_CDR = 0x400C8020;//conversion data register
int *DACC_CHER = 0x400C8010;//chanel enable register
int *DACC_ISR = 0x400C8030;//interrupcion status register (bandera que dice si el registro esta lleno)
int *PMC_PCER1 = 0x400E0700;// PMC peripherical clock enable register

 
int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	int i = 0;	
	board_init();
	*PMC_PCER1 = 0x0000040;
	*DACC_MR = 0x00000100;
	*DACC_CHER = 0x00000003;
	while(1){
		if (*DACC_ISR == 0x00000002){
			*DACC_CDR = i;
			i++;	
		}
		if(*DACC_CDR==0xFF6){
			i=0;
		}else{
			i=i;
		}
	}
	/* Insert application code here, after the board has been initialized. */
}
