#include <stdio.h>
#include <stdlib.h>

typedef struct X{
    int dato;
}X;


int main(int argc, char *argv[])
{
    int *x =(int *) malloc(sizeof(int));
    *x = 10;
    printf("%d \n", *x);
    free(x);
    printf("%d \n", *x);

    X *apX =(X*) malloc(sizeof(X));
    if(apX == NULL){
        printf("No se asignó la memoria");
    }
    apX -> dato = 2;
    printf("%d \n", apX->dato);
    free(apX);
    printf("%d \n", apX->dato);
}