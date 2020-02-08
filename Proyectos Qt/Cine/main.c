#include <stdlib.h>
#include <stdio.h>


struct boleta
{
    unsigned char fecha[3];
    unsigned char ubicacion;
    unsigned int precio;
    unsigned char compra;

};

struct pelicula
{
    unsigned char nombre[10];
    struct boleta asientos[36];
    unsigned char mat[6][6]; /*= { {' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' '} };*/

};

struct cinema
{
    unsigned char nombre[10];  /*={ 'c','i','n','e','m','a','p','l','a','y' };*/
    struct pelicula movies[3];/* = { {{'e','l','p','a','y','a','s','o','i','t'},{0}},
                                  {{'e','l','p','a','y','a','s','o','o','t'},{0}},
                                  {{'e','l','p','a','y','a','s','o','u','t'},{0}} };*/
};

void dibujo(unsigned char dib[][6]) {
    unsigned char letra = 'a';
    printf("\n    1    2    3    4    5    6 \n");
    printf(" ----------------------------------\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%c| ", letra);
        for (int j = 0; j < 6; j++)
        {
            printf("!%c!  ", dib[i][j]);
        }
        letra = letra + 1;
        printf(" |\n");
    }
    printf(" ----------------------------------\n");

}
struct pelicula ver_peli(struct pelicula peli) {
    unsigned char assist[2];
    char band = 'f';
    char trash;
    dibujo(peli.mat);
    do {
        do {
            trash = getchar();
            printf("\ningrese fila\n");
            scanf_s("%c", &assist[0]);
            switch (assist[0])
            {
            case 'a':
                assist[0] = '1';
                band = 'v';
                trash = getchar();
                break;
            case 'A':
                assist[0] = '1';
                band = 'v';
                trash = getchar();
                break;
            case 'b':
                assist[0] = '2';
                band = 'v';
                trash = getchar();
                break;
            case 'B':
                assist[0] = '2';
                band = 'v';
                trash = getchar();
                break;
            case 'c':
                assist[0] = '3';
                band = 'v';
                trash = getchar();
                break;
            case 'C':
                assist[0] = '3';
                band = 'v';
                trash = getchar();
                break;
            case 'd':
                assist[0] = '4';
                band = 'v';
                trash = getchar();
                break;
            case 'D':
                assist[0] = '4';
                band = 'v';
                trash = getchar();
                break;
            case 'e':
                assist[0] = '5';
                band = 'v';
                trash = getchar();
                break;
            case 'E':
                assist[0] = '5';
                band = 'v';
                trash = getchar();
                break;
            case 'f':
                assist[0] = '6';
                band = 'v';
                trash = getchar();
                break;
            case 'F':
                assist[0] = '6';
                band = 'v';
                trash = getchar();
                break;
            default:
                printf("no valido\n");
                break;
            }
        } while (band == 'f');
        band = 'f';
        do
        {
            trash = getchar();
            printf("\ningrese columna\n");
            scanf_s("%c", &assist[1]);
            switch (assist[1])
            {
            case '1':
                band = 'v';
                trash = getchar();
                break;
            case '2':
                band = 'v';
                trash = getchar();
                break;
            case '3':
                band = 'v';
                trash = getchar();
                break;
            case '4':
                band = 'v';
                trash = getchar();
                break;
            case '5':
                band = 'v';
                trash = getchar();
                break;
            case '6':
                band = 'v';
                trash = getchar();
                break;
            default:
                printf("opcion no valida");
                break;
            }
        } while (band == 'f');
        if (peli.mat[(assist[0] - '0') - 1][(assist[1] - '0') - 1] == 'x') {
            printf("asiento ocupado ingrese otro asiento:\n");
            band = 'f';
        }
    } while (band == 'f');
    printf("\nasientos obtenidos: %c %c\n", assist[0], assist[1]);
    peli.mat[(assist[0] - '0') - 1][(assist[1] - '0') - 1] = 'x';
    dibujo(peli.mat);
    return peli;
}

struct cinema reserva(struct cinema cine) {
    char opc = '0';
    char trash;
    for (int i = 0; i < 3; i++)
    {
        printf("\n%d. ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", cine.movies[i].nombre[j]);
        }
    }
    printf("\n");
    do {
        trash = getchar();
        printf("ingrese la pelicula: ");
        scanf_s("%c", &opc);
        switch (opc)
        {
        case '1':
            cine.movies[0] = ver_peli(cine.movies[0]);
            trash = getchar();
            break;
        case '2':
            cine.movies[1] = ver_peli(cine.movies[1]);
            trash = getchar();
            break;
        case '3':
            cine.movies[2] = ver_peli(cine.movies[2]);
            trash = getchar();
            break;
        case '0':
            printf("\nAdios");
            trash = getchar();
            break;
        default:
            printf("\nno valida\n");
            break;
        }
    } while (opc != '0');
    return cine;
}

void ver_funcion(struct cinema cine) {
    char opc = '0';
    char trash;
    for (int i = 0; i < 3; i++)
    {
        printf("\n%d. ", i + 1);
        for (int j = 0; j < 10; j++)
        {
            printf("%c", cine.movies[i].nombre[j]);
        }
    }
    do {
        trash = getchar();
        printf("ingrese la pelicula: ");
        scanf_s("%c", &opc);
        switch (opc) {
        case '1':
            system("cls");
            dibujo(cine.movies[0].mat);
            break;
        case '2':
            system("cls");
            dibujo(cine.movies[1].mat);
            break;
        case '3':
            system("cls");
            dibujo(cine.movies[2].mat);
            break;
        default:
            break;
        }

    } while (opc != '0');
}

void c_co() {
    struct cinema cine = { 0 };
    unsigned char opc;
    char trash;

    do {
        printf("1.comprar boleta\n2.ver funciones\n");
        scanf_s("%c", &opc);
        switch (opc)
        {
        case '1':
            cine = reserva(cine);
            trash = getchar();
            break;
        case '2':
            ver_funcion(cine);
            trash = getchar();
            break;
        case '0':
            printf("\nAdios\n");
            trash = getchar();
        default:
            trash = getchar();
            printf("opcion no valida");
            break;
        }
    } while (opc != '0');

}

int main(void) {

}
