#include <stdio.h>

typedef struct Complejo
{
    float real;
    float imaginario;   
}Complejo; // también se puede poner el typedef y puede tener más separados por comas
// si no se pone el typedef, lo que está después de las llaves y antes del punto y coma serían variables declaradas
//typedef struct Complejo Complejo; Equivalente de typedef

void imprimirComplejo(Complejo *complejo);
Complejo sumarComplejos(Complejo numero1, Complejo numero2);
Complejo multiplicarComplejos(Complejo numero1, Complejo numero2);

int main(int argc, char * argv[])
{   
    Complejo numero1 = {12.3, 10};
    Complejo numero2 = {2, -17};
    numero1.real = 1.0;

    imprimirComplejo(&numero1);

    Complejo resultado = sumarComplejos(numero1, numero2);
    imprimirComplejo(&resultado);
    
    resultado = multiplicarComplejos(numero1, numero2);
    imprimirComplejo(&resultado);
    return 0;
}

void imprimirComplejo(Complejo *complejo){
    printf("(%.4f,%+.4f)\n", complejo -> real, (*complejo).imaginario); // Dereferenciaciones equivalentes
}

Complejo sumarComplejos(Complejo numero1, Complejo numero2){
    Complejo suma = {numero1.real + numero2.real, numero1.imaginario + numero2.imaginario};
    return suma;
}

Complejo multiplicarComplejos(Complejo numero1, Complejo numero2){
    Complejo multiplicacion = {numero1.real*numero2.real - numero1.imaginario*numero2.imaginario, 
                                numero1.real*numero2.imaginario + numero1.imaginario*numero2.real};
    return multiplicacion;            
}