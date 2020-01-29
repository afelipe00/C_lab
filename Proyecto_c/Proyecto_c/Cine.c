#include <stdio.h>


struct boleta
{
	unsigned char fecha[3];
	unsigned char ubicacion;
	unsigned char precio;
	unsigned char compra;

};

struct pelicula
{
	unsigned char nombre[35];
	struct boleta asientos[5][5];

};

struct cinema
{
	unsigned char nombre[35];
	struct pelicula movies[3];
};

void dibujo() {
	unsigned char dib[6][6] = { {' ',' ',' ',' ',' ',' '},
								{' ',' ',' ',' ',' ',' '},
								{' ',' ',' ',' ',' ',' '},
								{' ',' ',' ',' ',' ',' '},
								{' ',' ',' ',' ',' ',' '},
								{' ',' ',' ',' ',' ',' '} };
	unsigned char letra = 'a';
	printf("\n    1    2    3    4    5    6 \n");
	printf(" ----------------------------------\n");
	for (int i = 0; i < 6; i++)
	{
		printf("%c| ",letra);
		for (int j = 0; j < 6; j++)
		{
			printf("!%c!  ", dib[i][j]);
		}
		letra = letra + 1;
		printf(" |\n");
	}
	printf(" ----------------------------------\n");

}
void c_c() {
	struct cinema;
	dibujo();
}

int main(){
	c_c();
}