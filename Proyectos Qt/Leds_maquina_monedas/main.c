#include <stdio.h>
#include <stdlib.h>
//programa de leds
void imprimir_leds(char tablero[][12]) {
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
    imprimir_leds(tablero);
}

void leds() {
    int num, opc;
    int vec[3] = { 0,0,0 };
    char tablero[7][12]; //matriz que representa los 3 numeros
    do {
        printf("\nIngrese numero entre 0 y 999 (-1 para terminar): ");
        scanf("%i", &num);
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

//programa de maquina de monedas
void extractos(int extract[]) {
    printf("\nultimos 10 extractos\n");
    for (int i = 0; i < 10; i++) {
        printf("%d : %d \n", i + 1, extract[i]);
    }
}

int realizar_pago(int num_monedas[],int dinero, int extract[]) {
    int con50 = 0, con100 = 0, con200 = 0, con500 = 0, con1000 = 0, con10000 = 0;
    int pago = 0;
    printf("\ndinero disponible: %i",dinero);
    printf("\ningrese valor del pago: \n");
    scanf("%d", &pago);
    for (int i = 0; i < 10; i++)
    {
        if (extract[i] == 0) {
            extract[i] = pago;
            break;
        }
    }
    if (pago % 5 == 0 && pago < dinero) {
        while (pago > 0) {
            if (pago >= 10000 && num_monedas[5] > 0) {
                con10000++;
                dinero = dinero - 10000;
                pago = pago - 10000;
                num_monedas[5] = num_monedas[5] -1;
            }
            else if (pago >= 1000 && num_monedas[4] > 0) {
                con1000++;
                dinero = dinero - 1000;
                pago = pago - 1000;
                num_monedas[4] = num_monedas[4] -1;
            }
            else if (pago >= 500 && num_monedas[3] > 0) {
                con500++;
                dinero = dinero - 500;
                pago = pago - 500;
                num_monedas[3] = num_monedas[3] -1;
            }
            else if (pago >= 200 && num_monedas[2] > 0) {
                con200++;
                dinero = dinero - 200;
                pago = pago - 200;
                num_monedas[2] = num_monedas[2] -1;
            }
            else if (pago >= 100 && num_monedas[1] > 0) {
                con100++;
                dinero = dinero - 100;
                pago = pago - 100;
                num_monedas[1] = num_monedas[1] -1;
            }
            else if (pago >= 50 && num_monedas[0] > 0) {
                con50++;
                dinero = dinero - 50;
                pago = pago - 50;
                num_monedas[0] = num_monedas[0] -1;
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

int ingresar_monedas(int num_monedas[]) {
    int	moneda = 0, suma = 0,cantidad = 0;
    char opc = 0, trash = 0;
    do {
        trash = getchar();
        printf("\ningrese valor de la moneda: \n");
        printf("1. 50\n2. 100\n3. 200\n4. 500\n5. 1000\n6.10000\n( s para salir)\n");
        scanf("%c", &opc);
        switch (opc)
        {
        case '1':
            moneda = 50;
            printf("\ningrese cantidad: ");
            scanf("%i",&cantidad);
            num_monedas[0] = cantidad;
            cantidad = 0;
            suma = suma + moneda * num_monedas[0];
            break;
        case '2':
            moneda = 100;
            printf("\ningrese cantidad: ");
            scanf("%i",&cantidad);
            num_monedas[1] = cantidad;
            cantidad = 0;
            suma = suma + moneda * num_monedas[1];
            break;
        case '3':
            moneda = 200;
            printf("\ningrese cantidad: ");
            scanf("%i",&cantidad);
            num_monedas[2] = cantidad;
            cantidad = 0;
            suma = suma + moneda * num_monedas[2];
            break;
        case '4':
            moneda = 500;
            printf("\ningrese cantidad: ");
            scanf("%i",&cantidad);
            num_monedas[3] = cantidad;
            cantidad = 0;
            suma = suma + moneda * num_monedas[3];
            break;
        case '5':
            moneda = 1000;
            printf("\ningrese cantidad: ");
            scanf("%i",&cantidad);
            num_monedas[4] = cantidad;
            cantidad = 0;
            suma = suma + moneda * num_monedas[4];
            break;
        case '6':
            moneda = 10000;
            printf("\ningrese cantidad: ");
            scanf("%i",&cantidad);
            num_monedas[5] = cantidad;
            cantidad = 0;
            suma = suma + moneda * num_monedas[5];
            break;
        case 's':
            moneda = 0;
            break;
        default:
            printf("moneda no valida");
            break;
        }
    } while (opc != 's');
    printf("\nsuma %d",suma);
    system("pause");
    return suma;
}

void monedas() {
    char opc = 0,trash = 0;
    int num_monedas[6];
    int dinero, extract[10] = { 0,0,0,0,0,0,0,0,0,0 };
    do{
        printf("1.Ingresar monedas\n2.Realizar pagos\n3.Consultar Extractos\n");
        trash = getchar();
        printf("ingrese opcion (s para salir):\n");
        scanf("%c", &opc);
        switch (opc)
        {
        case '1':
            dinero = ingresar_monedas(num_monedas);
            break;
        case '2':
            dinero = realizar_pago(num_monedas,dinero, extract);
            system("pause");
            break;
        case '3':
            extractos(extract);
            break;
        case 's':
            printf("adios");
            break;
        default:
            break;
        }
    }while(opc != 's');

}

void menu_principal(){
    int opc = 0;
    do{
        system("cls");
        printf("1.numeros LED\n2.maquina de monedas\n");
        printf("ingrese opcion(solo numeros, 0 para salir): ");
        scanf("%d",&opc);
        switch (opc) {
        case 1:
           leds();
           break;
        case 2:
           monedas();
           break;
        case 0:
            printf("adios");
            break;
        default:
           printf("variable erronea");
           break;
        }
    }while (opc != 0) ;

}

int main(void) {
    menu_principal();
}
