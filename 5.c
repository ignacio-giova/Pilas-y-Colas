#include <stdio.h>
#include <stdlib.h>

#define MAX_COLA 30

typedef struct _Cola{
    int datos[MAX_COLA];
    int primero, ultimo;
} Cola;

Cola * cola_crear(){
    Cola * nuevaCola = malloc (sizeof(Cola));
    if (nuevaCola == NULL){
        printf("No se le puedo asignar memoria");
        return NULL;
    }

    nuevaCola->primero = 0;
    nuevaCola->ultimo = 0;

    return nuevaCola;
}

int cola_es_vacia (Cola *a){
   return a->primero == a->ultimo;
}

int cola_primero(Cola *a){
    if (cola_es_vacia(a)){
        printf("La cola esta vacia");
        return -1;
    }
    return a->datos[a->primero];
}

void cola_encolar(Cola *a, int x){
    if(a->primero == (a->ultimo + 1) % MAX_COLA){
        printf("La cola esta llena");
    }
    else{
        a->ultimo = (a->ultimo + 1) % MAX_COLA;
        a->datos[a->ultimo] = x;
    }
}

void cola_desencolar(Cola *a){
    if (cola_es_vacia(a))
        printf("La cola esta vacia");
    else{
        a->primero= (a->primero + 1) % MAX_COLA;
    }
}

void cola_imprimir(Cola *a){
    if (cola_es_vacia(a))
        printf("La cola esta vacia");
    else{
        for(int i=0; i <= abs(a->primero - a->ultimo) ; i++){
            printf("%i\n", a->datos[(a->primero + i) % MAX_COLA]);
        }
    }
}

void cola_destruir(Cola *a){
    free(a);
}

int main(){
    Cola *miCola = cola_crear();

    cola_encolar(miCola, 3);
    cola_encolar(miCola, 6);
    cola_encolar(miCola, 10);

    cola_imprimirV2(miCola);

    cola_destruir(miCola);
}