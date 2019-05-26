#include <stdio.h>

int potencia(int *arg, int exp);

int cuentaCaracteres(char * cadena){
    int i=0;
    while(cadena[i] != '\0'){
        i++;
    }
    return i;
} 

int main( int argc, char * argv[]){
    int a = 2, b = 3;
    int resultado = potencia(&a,b);
    char cadena[] = "Hola mundo!";

    printf("El resultado es: %d \n", resultado);
    printf("Longitud de la cadena: %d \n", cuentaCaracteres(cadena));
    printf("El nuevo valor de a es: %d \n", a);
    return 0;
}

int potencia(int *arg, int exp){
    int resultado = 1;
    int base = *arg;
    for( int i = 0; i < exp; i++)
    {
        resultado *= base;
    }
    *arg = 100;
    return resultado;
}