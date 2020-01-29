#include <stdio.h>

void imprimir(char tablero[][12]) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 12; j++) {
			printf("%c", tablero[i][j]);
		}
		printf("\n");
	}
}
void numbers(int vec[], char tablero[][12]) {
	int num = 0;
	for (int i = 0; i < 12; i++) {
		//fila 1
		if (vec[num] == 0 || vec[num] == 2 || vec[num] == 3 || vec[num] == 5 || vec[num] == 6 || vec[num] == 7 || vec[num] == 8 || vec[num] == 9) {
			if (i == 0 || i == 3 || i == 4 || i == 7 || i == 8 || i == 11) {
				tablero[0][i] = ' ';
			}
			else
			{
				tablero[0][i] = '-';
			}
		}
		else {
			tablero[0][i] = ' ';
		}
		//fila 2 y 3
		if (vec[num] == 1 || vec[num] == 2 || vec[num] == 3 || vec[num] == 7) {
			if (i == 3 || i == 7 || i == 11) {
				tablero[1][i] = '|';
				tablero[2][i] = '|';
			}
			else
			{
				tablero[1][i] = ' ';
				tablero[2][i] = ' ';
			}
		}
		else if (vec[num] == 5 || vec[num] == 6) {
			if (i == 0 || i == 4 || i == 8) {
				tablero[1][i] = '|';
				tablero[2][i] = '|';
			}
			else
			{
				tablero[1][i] = ' ';
				tablero[2][i] = ' ';
			}
		}
		else
		{
			if (i == 0 || i == 3 || i == 4 || i == 7 || i == 8 || i == 11) {
				tablero[1][i] = '|';
				tablero[2][i] = '|';
			}
			else
			{
				tablero[1][i] = ' ';
				tablero[2][i] = ' ';
			}
		}
		//fila 4
		if (vec[num] == 2 || vec[num] == 3 || vec[num] == 4 || vec[num] == 5 || vec[num] == 6 || vec[num] == 8 || vec[num] == 9) {
			if (i == 0 || i == 3 || i == 4 || i == 7 || i == 8 || i == 11) {
				tablero[3][i] = ' ';
			}
			else
			{
				tablero[3][i] = '-';
			}
		}
		else {
			tablero[3][i] = ' ';
		}
		//fila 5 y 6
		if (vec[num] == 1 || vec[num] == 3 || vec[num] == 4 || vec[num] == 5 || vec[num] == 7 || vec[num] == 9) {
			if (i == 3 || i == 7 || i == 11) {
				tablero[4][i] = '|';
				tablero[5][i] = '|';
			}
			else
			{
				tablero[4][i] = ' ';
				tablero[5][i] = ' ';
			}
		}
		else if (vec[num] == 2) {
			if (i == 0 || i == 4 || i == 8) {
				tablero[4][i] = '|';
				tablero[5][i] = '|';
			}
			else
			{
				tablero[4][i] = ' ';
				tablero[5][i] = ' ';
			}
		}
		else
		{
			if (i == 0 || i == 3 || i == 4 || i == 7 || i == 8 || i == 11) {
				tablero[4][i] = '|';
				tablero[5][i] = '|';
			}
			else
			{
				tablero[4][i] = ' ';
				tablero[5][i] = ' ';
			}
		}
		// fila 7
		if (vec[num] == 2 || vec[num] == 3 || vec[num] == 5 || vec[num] == 6 || vec[num] == 8 || vec[num] == 0) {
			if (i == 0 || i == 3 || i == 4 || i == 7 || i == 8 || i == 11) {
				tablero[6][i] = ' ';
			}
			else
			{
				tablero[6][i] = '-';
			}
		}
		else {
			tablero[6][i] = ' ';
		}
		//cambio de numero
		if (i > 6) {
			num = 2;
		}
		else if (i > 2) {
			num = 1;
		}
	}
	imprimir(tablero);
}
void leds() {
	int num, opc;
	int vec[3] = { 0,0,0 };
	char tablero[7][12]; //matriz que representa los 3 numeros
	do {
		printf("\nIngrese numero entre 0 y 999 (-1 para terminar): ");
		scanf_s("%i", &num);
		opc = num;
		if (num >= 1000 || num < 0) {
			printf("\nel numero es erroneo");
		}
		else {
			for (int i = 2; i >= 0; i--) {
				vec[i] = num % 10;
				num = num / 10;
			}
			numbers(vec, tablero);
		}
		system("pause");
		system("cls");
	} while (opc != -1);
}
/*
int main(void) {
	leds();
}
*/