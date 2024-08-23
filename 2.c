#include <stdlib.h>
#include <stdio.h>

#define MAX_PILA 10

typedef struct _Pila {
    int *datos;
    int ultimo;
    int capacidad;
} Pila;


Pila * crear_pila() {
    Pila *nuevaPila = malloc (sizeof (struct _Pila));
    if (nuevaPila == NULL)
        return NULL;

    nuevaPila->capacidad = MAX_PILA;

    (*nuevaPila).datos = malloc (sizeof (int) * nuevaPila->capacidad);
    if((*nuevaPila).datos == NULL)
        return NULL;

    (*nuevaPila).ultimo = -1;
    return nuevaPila;    
}

int pila_es_vacia(Pila *a){
        return (*a).ultimo == -1;
}

int pila_top(const Pila *a){
    if ((*a).ultimo == -1)
        return -1;
    return (*a).datos[(*a).ultimo];
}

void pila_push(Pila *a, int x){
    if(a->ultimo + 1 == a->capacidad){
        (a->datos) = realloc((a->datos), (a->capacidad * 2) * sizeof(int));
        if (a->datos == NULL){
            printf("Hubo error al redimensionar la pila");
            return;
        }
        else
            a->capacidad*=2;
    }
    
    a->ultimo++;
    (*a).datos[(*a).ultimo] = x;

}

void pila_pop(Pila *a){
    if ((*a).ultimo == -1){
        printf("La lista esta vacia");
        return;
    }
    
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
    free(a->datos);
    free(a);
}

int main (){
    Pila *miPila = crear_pila();

    pila_push(miPila, 3);
    pila_push(miPila, 5);
    pila_push(miPila, 7);

    pila_imprimir(miPila);

    printf("------------------------------------------------------ \n");

    pila_pop(miPila);
    pila_pop(miPila);
    pila_push(miPila, 22);
    pila_push(miPila, 19);

    pila_imprimir(miPila);

    pila_destruir(miPila);

    return 0;
}