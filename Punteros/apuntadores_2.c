#include <stdio.h>

int main( int argc, char * argv[]){

    int arreglo[6] = { 1, -10, 0 ,-1, 20, 7};
    int * apArray = arreglo; //&arreglo[0] es equivalente

    apArray ++; //Como es un apuntador a tipo entero, apunta 4 bytes más allá. Todo depende del tipo de dato
    printf("Contenido de la dirección de memoria apuntada por apArray: %d \n", *apArray);
    
    apArray += 4;
    printf("Contenido de la dirección de memoria apuntada por apArray: %d \n", *apArray);
    
    apArray -= 3;
    printf("Contenido de la dirección de memoria apuntada por apArray: %d \n", *apArray);
    
    return 0;
}