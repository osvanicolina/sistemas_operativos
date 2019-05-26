#include <stdio.h>

int main(int argc,char *argv[]){
    int var1 = 10;
    int *apEntero = &var1;

    printf("Valor de var1 es: %d \n", var1);

    *apEntero = 30;
    printf("El nuevo valo de var1 es: %d \n", var1);

    return 0;
}