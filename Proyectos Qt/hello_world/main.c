#include <stdio.h>

int main()
{
    int *ptr;
    int a = 20;
    ptr = &a;
    *ptr = *ptr + a;
    printf("%i",*ptr);
}
