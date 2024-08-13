#include <stdlib.h>
#include <stdio.h>

#define MAX_PILA 10

typedef struct _Pila {
    int datos[MAX_PILA];
    int ultimo;
} Pila;

Pila * crear_pila() {
    Pila *nuevaPila = malloc (sizeof (struct _Pila));

    if (nuevaPila != NULL)
        (*nuevaPila).ultimo = -1;

    return nuevaPila;
}

int pila_es_vacia(Pila *a){
    if((*a).ultimo == -1)
        return 1;
    else
        return 0;
}

int pila_top(Pila *a){
    if ((*a).ultimo == -1)
        return -1;
    else
        return (*a).datos[(*a).ultimo];
}

void pila_push(Pila *a, int x){
    if ((*a).ultimo == MAX_PILA - 1)
        printf("Error la Pila esta llena");
    else {
        (*a).ultimo++;
        (*a).datos[(*a).ultimo] = x;
    }
}

void pila_pop(Pila *a){
    if ((*a).ultimo == -1)
        printf("La lista esta vacia");
    else
         (*a).ultimo--;
}

void pila_imprimir(const Pila *a){      //Estructura Directa
    int aux = (*a).ultimo;
    while (aux >= 0){
        printf("%i\n", (*a).datos[aux] );
        aux--;
    }
}

void pila_destruir(Pila *a){
    free(a);
}

int main (){
    Pila *miPila = crear_pila();

    pila_push(miPila, 3);
    pila_push(miPila, 5);
    pila_push(miPila, 7);

    pila_imprimir(miPila);

    pila_destruir(miPila);

    return 0;
}