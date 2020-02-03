#include<stdio.h>
#include<string.h>


#define vect_tam = 100;

struct palabra
{
	unsigned char nombre[30];
	unsigned char sinonimo[30];
};

void listar(struct palabra dic[]) {

}

void buscar(struct palabra dic[]) {

}

int repeat(char word1[], char word2[]) {
	int repe = 0;
	int tam = 0;
	for (int i = 0; i < 30; i++)
	{
		if (word1 != '0') {
			tam = tam + 1;
		}
	}
	for (int i = 0; i < tam; i++)
	{
		if (word1[i] != word2[i]) {
			repe = 1;
		}
	}
	return repe;
}

void llenar(char word[], int opc) {
	for (int i = 0; i < 30; i++)
	{
		word[i] = '0';
	}
}

int num_palabras(struct palabra dic[]) {
	int tam = 0;
	for (int i = 0; i < 100; i++)
	{
		if (dic[i].nombre[0] == '0') {
			tam = i;
			break;
		}
	}
	return tam;
}

void agregar(struct palabra dic[]) {
	char opc = '1';
	char word[30];
	char repetida;
	int tam = 0, npal = 0;
	llenar(word,1);
	do
	{
		printf("ingrese la palabra: ");
		scanf_s("%s", &word);
		npal = num_palabras(dic);
		if (npal < 100) {
			for (int i = 0; i < 100; i++) {
				repetida = repeat(word, dic[i].nombre);
				if (repetida == '0') {
					printf("\npalabra existente en el diccionario\n");
					break;
				}
				else
				{
					for (int j = 0; j < 30; j++)
					{
						if (word != '0') {
							tam = tam + 1;
						}
						else
						{
							break;
						}
					}
					for (int j = 0; j < tam; j++)
					{
						dic[i].nombre[j] = word[j];
					}
					opc = '0';
				}
			}
		}
		else
		{
			printf("\ndiccionario lleno\n");
		}
	} while (opc != '0');
}

void menu_d() {
	struct palabra diccionario[10];
	char opc = '0';
	do
	{
		printf("1.Agregar palabra\n2.Buscar\n3.listar");
		printf("\ningrese la opcion: ");
		scanf_s("%c", &opc);
		switch (opc)
		{
		case '1':
			agregar(diccionario);
			break;
		case '2':
			buscar(diccionario);
			break;
		case '3':
			listar(diccionario);
			break;
		case '0':
			printf("Adios");
		default:
			printf("dato erroneo");
			break;
		}
	} while (opc != '0');
}

int main() {
	menu_d();
}