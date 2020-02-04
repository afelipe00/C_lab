#include<stdio.h>
#include<string.h>


#define vect_tam = 100;

struct palabra
{
    unsigned char nombre[30];
    unsigned char sinonimo[30];
};

void vaciar(struct palabra dic[],unsigned char word[], int opc) {
    //1 si es un vector , 0 si es la estructura
    if(opc == 1){//validacion de la opcion a llenar
        for (int i = 0; i < 30; i++)//ciclo que recorre el vector de la palabra 30 porque es el maximo numero de letras
        {
            word[i] = ' ';//llenado de 0
        }
    }else {
        for(int i = 0;i < 100;i++){
            for (int j =0;j<30;j++){
                dic[i].nombre[j] = ' ';
                dic[i].sinonimo[j] = ' ';
            }
        }
    }
}
int tam_pal(unsigned char word[]){
    int num_let = 0;
    for (int i = 0; i < 30; i++)
    {
        if (word[i] != ' ') {
            num_let = num_let + 1;
        }
        else
        {
            break;
        }
    }
    return num_let;
}
void imprimir_d(struct palabra dic[]){
    printf("\n");
    //vaciar(dic);
    for(int i = 0 ; i<100;i++){
        if(dic[i].nombre[0] != ' '){
            printf("palabra: ");
            for(int j = 0; j < 30;j++){
                printf("%c",dic[i].nombre[j]);
            }
            printf(" sinonimo: ");
            for(int j = 0; j < 30;j++){
                printf("%c",dic[i].sinonimo[j]);
            }
            printf("\n");
        }
    }
}
void listar(struct palabra dic[]) {
    struct palabra temp ;
    for(int i = 0 ; i<100;i++){
        for(int j = 0; j < 99 ;j ++){
            if(dic[j].nombre[0] > dic[j+1].nombre[0]){
                temp = dic[j];
                dic[j] = dic[j+1];
                dic[j+1] = temp;
            }
        }
    }
    imprimir_d(dic);
    system("pause");
}
void buscar(struct palabra dic[],unsigned char word[]) {
    int tam_word = 0;
    int repe = 0;
    vaciar(dic,word,1);
    printf("\ningrese palabra: ");
    scanf("%s", word);
    tam_word = tam_pal(word);
    for(int i = 0; i < 100; i ++){
        for(int j = 0; j < tam_word; j ++){
            if (dic[i].nombre[j]== word[j]){
                repe = repe + 1;
            }
        }
        if (repe == tam_word){
            printf("\nel sinonimo es: ");
            tam_word = tam_pal(dic[i].sinonimo);
            for(int k = 0;k< tam_word;k++){
                printf("%c",dic[i].sinonimo[k]);
            }
            break;
        }
        repe = 0;
    }
    if(repe == 0){
        printf("\npalabra no existente\n");
    }
    printf("\n");
    system("pause");
}

int repeat(unsigned char word1[], unsigned char word2[]) {//recibe dos palabras y valida si son iguales
    int repe = 0;//variable que retorna 1 si son diferentes 0 si son iguales
    int tam = 0;//variable que identifica el tamaño de la palabra
    tam = tam_pal(word1);//llamado funcion para identificar tamaño de la palabra
    for (int i = 0; i < tam; i++)//for que identifica si las dos palabras son diferentes
    {
        if (word1[i] != word2[i]) {//validacion si el caracter es diferente
            repe = 1;//si es diferente repe = 1
        }
    }
    return repe;
}

int num_palabras(struct palabra dic[]) {
    int tam = 0;
    for (int i = 0; i < 100; i++)
    {
        if (dic[i].nombre[0] != ' ') {
            tam = tam + 1;

        }
    }
    return tam;
}

void agregar(struct palabra dic[],unsigned char word[]) {
    char opc = '1';//variable de salida de ciclo
    int repetida;//variable que me indica si la palabra ya esta en el diccionario
    int num_let = 0, npal = 0;//tam = tamaño de la palabra y npal = numero de palabras en el diccionario
    vaciar(dic,word,1);//llamado a la funcion llenar (llena con 0)
    do//ciclo de funciones
    {
        printf("ingrese la palabra: ");
        scanf("%s", word);//lectura de la palabra
        num_let = tam_pal(word);//identificacion del tamaño de la palabra
        npal = num_palabras(dic);//busqueda de cuanta palabras hay en el diccionario
        for (int i = 0 ; i < num_let; i++){
            printf("%c ",word[i]);
        }
        if (npal < 100) {//si el diccionario no esta lleno
            for (int i = 0; i < 100; i++) {//recorre todo el diccionario en busqueda de una palabra repetida
                repetida = repeat(word, dic[i].nombre);//funcion repeat valida si las dos palabras son iguales
                if (repetida == 0) {
                    printf("\npalabra existente en el diccionario\n");
                    break;
                }
            }
            if(repetida != 0){
                for (int i = 0 ; i < num_let; i++){
                    dic[npal].nombre[i] = word[i];
                }
                printf("\npalabra ingresada\n");
                printf("ingrese el sinonimo: ");
                scanf("%s",word);
                for (int i = 0 ; i < num_let; i++){
                    dic[npal].sinonimo[i] = word[i];
                }
                for (int i = 0 ; i < num_let; i++){
                    printf("%c ",word[i]);
                }
                printf("\nsinonimo ingresado\n");
                system("pause");
                opc = '0';
            }
        }
        else
        {
            printf("\ndiccionario lleno\n");
            opc = '0';
        }
    } while (opc != '0');
}

void menu_d() {
    struct palabra diccionario[100];//declaro la estructura del diccionario
    unsigned char word[30];//vector donde se almacena la palabra escrita
    char opc = '0';
    char tra = '0';//variable que me maneja la opcion del menu
    vaciar(diccionario,word,0);//llena el diccionario con 0
    printf("--------------DICCIONARIO MASTER 3000-----------------\npresione enter para continuar");
    do//ciclo de opciones
    {
        tra = getchar();
        system("cls");
        printf("--------------DICCIONARIO MASTER 3000-----------------\n");
        printf("\n1.Agregar palabra\n2.Buscar\n3.listar");//impresion del menu
        printf("\ningrese la opcion: ");
        scanf("%c", &opc);//lectura de la opcion
        switch (opc)//selector de casos
        {
        case '1':
            agregar(diccionario,word);//llamado funcion agregar
            break;
        case '2':
            buscar(diccionario,word);//llamado funcion buscar
            break;
        case '3':
            listar(diccionario);//llamado funcion listar
            break;
        case '0':
            printf("Adios\n");//caso de salida
            break;
        default:
            printf("\ndato erroneo");//impresion de dato erroneo
            break;
        }
    } while (opc != '0');//opcion de 0 para salir
}

int main() {
    char datos[2000];
    FILE *fp= fopen("prueba.csv","w+");

    fread(datos,)
    menu_d();
}
