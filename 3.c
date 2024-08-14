#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo {
    int dato;
    struct _Nodo *siguiente;
} Nodo;

typedef struct _Pila {
    Nodo* inicio;
} Pila;

Pila* pila_crear(){
    Pila *nuevaPila = malloc (sizeof (Pila));
    if (nuevaPila != NULL)
        nuevaPila->inicio = NULL;

    return nuevaPila;
}

int pila_es_vacia(Pila *a){
    return (a->inicio == NULL);
}

int pila_top(Pila *a){
    if(pila_es_vacia(a)){
        printf("La pila esta vacia");
        return -1;
    }
    else{
        return ((a->inicio)->dato);
    }
}

Pila pila_push(Pila *a, int x){
    Nodo *nuevoNodo = malloc (sizeof (Nodo));
    if (nuevoNodo != NULL){
        nuevoNodo->dato = x;
        nuevoNodo->siguiente = a->inicio;
        a->inicio = nuevoNodo;
    }
}

Pila pila_pop(Pila *a){
    if (!pila_es_vacia(a)){
        Nodo *aux = a->inicio;
        a->inicio = aux->siguiente;
        free(aux);
    }
}

void pila_imprimir(Pila *a){
    Nodo *aux = a->inicio;
    while(aux != NULL){
        printf("%i\n", aux->dato);
        aux = aux->siguiente;
    }
}

void pila_destruir(Pila *a){
    while(a->inicio != NULL){
        pila_pop(a);
    }
    free(a);
}
int main (){
    Pila *miPila = pila_crear();

    pila_push(miPila, 10);
    pila_push(miPila, 5);
    pila_push(miPila, 8);

    pila_imprimir(miPila);

    pila_destruir(miPila);

    return 0;
}