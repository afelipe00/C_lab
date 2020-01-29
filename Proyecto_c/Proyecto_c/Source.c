#include<stdio.h>

int main()
{
    int radio;
    float area, perimetro;

    // SALIDA: mensaje un pantalla
    printf("Introduce el radio del circulo: ");

    //ENTRADA: recibir dato desde teclado
    scanf_s("%d", &radio);

    // calculos
    area = 3.1416 * radio * radio;
    perimetro = 3.1416 * radio * 2;

    //SALIDA: resultado en pantalla
    printf("El area es %.2f y el perimetro %.2f", area, perimetro);
    getch();

    return 0;
}