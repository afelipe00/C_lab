#include <stdio.h>

int main()
{
    char let = 'n';
    int a = 3;
    char mask = 0x01;
    printf("variable sin corrimiento: %c\n",mask);
    mask = mask << let;
    printf("variable con corrimiento: %c\n",mask);
    return 0;
}
