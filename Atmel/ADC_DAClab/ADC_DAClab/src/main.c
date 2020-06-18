#include <asf.h>

/*CONFIGURACION DE LAS DIRECCIONES*/
//direcciones de los PIO
int *pio_pdr_b = 0x400E1004;//pio deshabilitacion del canal b
int *pio_pudr_b = 0x400E1060;// pull up disable register del canal b

//direcciones de los ADC
int *adc_cher = 0x400C0010;//habilitacion de los canales del adc
int *adc_cr = 0x400C0000;// 
int *adc_mr = 0x400C0004;// modo de habilitacion del canal
int *adc_cdr = 0x400C0078;

//direcciones del DAC
int *DACC_MR = 0x400C8004;//modo de habilitacion del dacc
int *DACC_CDR = 0x400C8020;//conversion data register
int *DACC_CHER = 0x400C8010;//chanel enable register
int *DACC_ISR = 0x400C8030;//interrupcion status register (bandera que dice si el registro esta lleno)

//direcciones del PMC
int *pmc_cer1 = 0x400E0700;

int main (void)
{
	sysclk_init();
	board_init();
	//CONFIGURACION DE LOS VALORES DE LOS PUERTOS Y CANALES
	//PIO
	*pio_pdr_b = 0x00008000;
	*pio_pudr_b = 0x00008000;
	//ADC
	*adc_cher = 0x00000400;
	*adc_cr = 0x00000002;
	*adc_mr = 0x0000FF80;
	//DAC
	*DACC_MR = 0x00000100;
	*DACC_CHER = 0x00000003;
	//PMC
	*pmc_cer1 = 0x00000060;
	//VARIABLE DONDE SE ALMACENA EL ADC
	int lectura = 0;
	//CICLO INFINITO
	while(1){
		lectura = *adc_cdr;
		if (*DACC_ISR&0x1 == 0x1){
			*DACC_CDR |= lectura; 
		}
		delay_ms(1);
	}
}
