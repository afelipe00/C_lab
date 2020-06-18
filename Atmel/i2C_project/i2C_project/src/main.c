#include <asf.h>

//Habilitación de PIOA
int *PIOA_PUDR = 0x400E0E60;  // Pull Up disable.
int *PIOA_PDR = 0x400E0E04;  // Disable Register.
int *PIOA_ABSR=0x400E0E70;

// Habilitación de PMC
int *PMC_PCR =0x400E070C;
int *PMC_PCER0 = 0x400E0610; // Manejamos la activacion de registros del reloj de los perisfericos para permitir la lectura y escritura (8)

//Habilitación UART
int *UART_RHR = 0x400E0818;        // Recive Holding Register
int *UART_BRGR = 0x400E0820;      // Baud Rate Generator
int *UART_THR = 0x400E081C;      // Transmit Holding Register
int *UART_SR = 0x400E0814;      // Status Register
int *UART_IMRK = 0x400E0810;   // Mask Register
int *UART_IER = 0x400E0808;   // Interrupt Enable Register
int *UART_MR = 0x400E0804;   // Mode Register for parity defined and Cahnnel Mode
int *UART_CR = 0x400E0800;  // Control Register

//Configuración
int *TWI_THR = 0x4008C034;     // Transmit Holding Register TWI
int *TWI_IER = 0x4008C024;    // Interrupt Enable Register
int *TWI_SR = 0x4008C020;    // Status Register
int *TWI_CWGR = 0x4008C010; // Clock Wavegorm Generator Register
int *TWI_MMR = 0x4008C004; // Master Mode Register.
int *TWI_CR = 0x4008C000;; // Control Register.

int main (void)
{
	sysclk_init();
	board_init();
	
	*PIOA_ABSR = 0x000;   // Perisfericos
	*PIOA_PDR = 0xFFFFFFFF;   // Pin Disable
	*PIOA_PUDR = 0xFFFFFFFF; // Se desabilitan los puertos pull-UP del UART.
	
	*PMC_PCR   =0x10020016;
	*PMC_PCER0 = 0x00400100; // Activando la entrada ADC configurada como la PID8 según datasheet
	
	*UART_IER = 0xFFFFFFFF;     // Configuracion de banderas.
	*UART_CR = 0x00000050;     // Se activa el receptor de datos
	*UART_MR = 0x00000801;    // Especificar que no tiene paridad.
	*UART_BRGR = 0x00000230; // Configuracion de CD (Se establece en 560, para tener un resultado de 9600)
	
	*TWI_CR = 0x00000025;      // Configuración de control register
	*TWI_MMR = 0x00030000;      // Indentificación del esclavo
	*TWI_IER = 0xFFFFFFFF;   // Activación de banderas
	*TWI_CWGR = 0x7FFFF;    // Relojito.
	
	
	while(1){
		*TWI_CR = 0x00000025;
		char a=*UART_RHR;  // Almacenamiento de recibido en uart a lo transmitido en I2C
		char b=a<<1;
		*UART_THR=a;
		if(TWI_SR == 0x00000004){//es evalua la bander txready
			*TWI_THR=a;
			*TWI_CR = 0x00000002;
		}
		delay_ms(10);
	}
}