#include <asf.h>

//delcaracion de los registros
//UART
//int *uart_cr = 0x400E0800;
int *uart_rhr = 0x400E0818;
int *uart_brgr = 0x400E0820;
int *uart_thr = 0x400E0814;
int *uart_sr = 0x400E0814;
int *uart_imrk = 0x400E0810;
int *uart_ier = 0x400E0808;
int *uart_mr = 0x400E0804;
int *uart_cr = 0x400E0800;


//PIO C	
int *pioc_oer = 0x400E1210;
int *pioc_per = 0x400E1200; 
int *pioc_sodr = 0x400E1230; 
int *pioc_osr = 0x400E1218; 
int *pioc_codr = 0x400E1234;
//PIO A
int *pioa_pudr = 0x400E0E60; 
int *pioa_per = 0x400E0E00; 
int *pioa_absr = 0x400E0E70;

//PMC
int *pmc_pcer0 = 0x400E0610;

int main (void){
	/* Insert system clock initialization code here (sysclk_init()). */
	board_init();
	sysclk_init();
	//pio c
	*pioc_per = 0x000000FF;
	*pioc_osr = 0x000001FF;
	*pioc_oer = 0x000001FF;
	*pioc_codr = 0xFFFFFFFF;
	//pio a
	*pioa_absr = 0x00000300;
	*pioa_per = 0x00000300;
	*pioa_pudr = 0x00000300;
	//pmc
	*pmc_pcer0 = 0x00000100;
	//uart
	*uart_cr = 0x00000050;
	*uart_mr = 0x00000801;
	*uart_brgr = 0x00000230;
	
	//variables
	char x,z;
	while(1){		
		*uart_thr = 'b';
	}
	/* Insert application code here, after the board has been initialized. */
}
