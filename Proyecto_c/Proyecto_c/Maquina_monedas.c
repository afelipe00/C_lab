#include <stdio.h>

void extractos(int extract[]) {
	printf("\nultimos 10 extractos\n");
	for (int i = 0; i < 10; i++) {
		printf("%d : %d \n", i + 1, extract[i]);
	}
}
int realizar_pago(int dinero, int extract[]) {
	int con50 = 0, con100 = 0, con200 = 0, con500 = 0, con1000 = 0, con10000 = 0;
	int pago = 0;
	printf("\ningrese valor del pago: \n");
	scanf_s("%d", &pago);
	for (int i = 0; i < 10; i++)
	{
		if (extract[i] == 0) {
			extract[i] = pago;
			break;
		}
	}
	if (pago % 5 == 0 && pago < dinero) {
		while (pago > 0) {
			if (pago >= 10000) {
				con10000++;
				dinero = dinero - 10000;
				pago = pago - 10000;
			}
			else if (pago >= 1000) {
				con1000++;
				dinero = dinero - 1000;
				pago = pago - 1000;
			}
			else if (pago >= 500) {
				con500++;
				dinero = dinero - 500;
				pago = pago - 500;
			}
			else if (pago >= 200) {
				con200++;
				dinero = dinero - 200;
				pago = pago - 200;
			}
			else if (pago >= 100) {
				con100++;
				dinero = dinero - 100;
				pago = pago - 100;
			}
			else if (pago >= 50) {
				con50++;
				dinero = dinero - 50;
				pago = pago - 50;
			}
		}
		printf("\n cantidad de monedas: \n");
		printf("50: %d 100: %d 200: %d 500:  %d 1000: %d 10000: %d", con50, con100, con200, con500, con1000, con10000, "\n");
	}
	else
	{
		printf("\nvalor erroneo\n");
	}
	return dinero;
}
int ingresar_monedas() {
	int	moneda = 0, suma = 0;
	char opc = 0, trash = 0;
	do {
		printf("\ningrese valor de la moneda: \n");
		printf("1. 50\n2. 100\n3. 200\n4. 500\n5. 1000\n6.10000\n( -1 para salir)\n");
		scanf_s("%c", &opc);
		switch (opc)
		{
		case '1':
			moneda = 50;
			break;
		case '2':
			moneda = 100;
			break;
		case '3':
			moneda = 200;
			break;
		case '4':
			moneda = 500;
			break;
		case '5':
			moneda = 1000;
			break;
		case '6':
			moneda = 10000;
			break;
		case 's':
			moneda = 0;
			break;
		default:
			printf("moneda no valida");
			break;
		}
		suma = suma + moneda;
		//trash = getchar();
	} while (opc != 's');
	return suma;
}

int menu() {
	char opc = 0;
	int dinero = 0, extract[10] = { 0,0,0,0,0,0,0,0,0,0 };
	printf("ingrese opcion:\n");
	printf("1.Ingresar monedas\n2.Realizar pagos\n3.Consultar Extractos\n");
	scanf_s("%c", &opc);
	switch (opc)
	{
	case '1':
		dinero = ingresar_monedas();
		break;
	case '2':
		dinero = realizar_pago(dinero, extract);
		break;
	case '3':
		extractos(extract);
		break;
	default:
		break;
	}
}
/*
int main(void) {
	menu();
}
*/