#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Libro{
    char titulo[50];
    char autor[50];
    char isbn[13];
}Libro;

typedef struct Nodo{
    Libro libro;
    struct Nodo* siguiente;
}Nodo;

typedef struct Lista
{
    Nodo *cabeza;
    int cantidad;
}Lista;

Nodo * CrearNodo(Libro *libro);
void DestruirNodo(Nodo *nodo);
void InsertarPrincipio(Lista *lista, Libro *libro);
void InsertarFinal(Lista *lista, Libro *libro);
void InsertarDespues( int n, Lista *lista, Libro *libro);
Libro *Obtener(int n, Lista *lista);
int Contar(Lista *lista);
void EliminarPrincipio(Lista *lista);
int EstaVacia(Lista *lista);
void EliminarUltimo(Lista *lista);
void EliminarElemento(int n , Lista *lista);
void ImprimirLibros(Lista *lista);

int main(int argc, char *argv[]){
    Lista lista = {NULL,0};
    Libro libro = {"Un alma sola", "Osvani Colina", "si es bueno"};
    Libro libroFinal = {"Hola", "Puerquita", "Ok"};
    printf("Iniciando...\n");
    InsertarPrincipio(&lista, &libro);
    InsertarPrincipio(&lista, &libro);
    InsertarFinal(&lista, &libroFinal);
    EliminarPrincipio(&lista);
    EliminarUltimo(&lista);
    ImprimirLibros(&lista);
    printf("Terminando...\n");
}

void ImprimirLibros(Lista *lista){
    Nodo *elemento = lista -> cabeza;
    int contador = 1;
    printf("Imprimiendo elementos...\n");
    while(elemento){
        printf("Libro %d llamado: %s \n", contador, elemento -> libro.titulo);
        elemento = elemento -> siguiente;
        contador++;
    }
}

Nodo * CrearNodo(Libro *libro){
    Nodo *nodo = (Nodo *) malloc(sizeof(Nodo));
    strncpy(nodo->libro.titulo, libro->titulo,50);
    strncpy(nodo->libro.autor, libro->autor,50);
    strncpy(nodo->libro.isbn, libro->isbn,13);
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo *nodo){
    free(nodo);
}

void InsertarPrincipio(Lista *lista, Libro *libro){
    Nodo *nodo = CrearNodo(libro);
    nodo -> siguiente = lista -> cabeza;
    lista -> cabeza = nodo;
    lista -> cantidad++;
}

void InsertarFinal(Lista *lista, Libro *libro){
    Nodo *nodo = CrearNodo(libro);
    if(lista->cabeza == NULL)
    {
        lista -> cabeza = nodo;
    }
    else 
    {
        Nodo *puntero = lista -> cabeza;
        while(puntero -> siguiente)
        {
            puntero = puntero -> siguiente;
        }

        puntero -> siguiente = nodo;
    }
    lista -> cantidad++;
}

void InsertarDespues( int n, Lista *lista, Libro *libro){
    Nodo *nodo = CrearNodo(libro);
    if( lista -> cabeza == NULL)
    {
        lista -> cabeza = nodo;
    }
    else
    {
        Nodo *puntero = lista -> cabeza;
        int posicion = 0;
        while(posicion < n && puntero -> siguiente)
        {
            puntero = puntero -> siguiente;
            posicion++;
        }
        nodo -> siguiente = puntero -> siguiente;
        puntero -> siguiente = nodo;
    }
    lista -> cantidad++;
}

Libro *Obtener(int n, Lista *lista){
    if(lista->cabeza == NULL){
        return NULL;
    }
    else
    {   
        Nodo *puntero = lista -> cabeza;
        int posicion = 0;

        while(posicion < n)
        {   
            if(puntero -> siguiente == NULL){
                return NULL;
            }
            puntero = puntero -> siguiente;
            posicion++;
        }
        return &(puntero -> libro);
    }
}

int Contar(Lista *lista){
    return lista -> cantidad;
}

void EliminarPrincipio(Lista *lista){
    if(lista -> cabeza)   
    {   
        Nodo *puntero = lista -> cabeza;
        lista -> cabeza = puntero -> siguiente;
        DestruirNodo(puntero);
        lista -> cantidad--;
    }
}

int EstaVacia(Lista *lista){
    return lista -> cabeza == NULL;
}

void EliminarUltimo(Lista *lista){
    if(lista -> cabeza)
    {
        if(lista -> cabeza -> siguiente)    
        {    
            Nodo *puntero = lista -> cabeza;
            while(puntero -> siguiente -> siguiente){
                puntero = puntero -> siguiente;
            }
            Nodo *ultimo = puntero -> siguiente;
            puntero -> siguiente = NULL;
            DestruirNodo(ultimo);
        }
        else
        {
            Nodo *ultimo = lista -> cabeza;
            lista -> cabeza = NULL;
            DestruirNodo(ultimo);
        }
        lista -> cantidad--;     
    }
}

void EliminarElemento(int n , Lista *lista){
    if(lista -> cabeza){
        if(n==0)
        {
            EliminarPrincipio(lista);
        }
        else if(n < lista -> cantidad)
        {
            Nodo *puntero = lista -> cabeza;
            int posicion = 0;
            while(posicion < (n-1)){
                puntero = puntero -> siguiente;
                posicion++;
            }
            Nodo *eliminado = puntero -> siguiente;
            puntero -> siguiente = eliminado -> siguiente;
            DestruirNodo(eliminado);
            lista -> cantidad--;
        }
    }
}
