#include <stdio.h>
#include <stdlib.h>

#define MAX_COLA 10

typedef struct _Cola{
    int *datos;
    int primero, ultimo;
    int capacidad
} Cola;

Cola * cola_crear(){
    Cola * nuevaCola = malloc (sizeof(Cola));
    if (nuevaCola == NULL){
        printf("No se le puedo asignar memoria");
        return NULL;
    }

    nuevaCola->capacidad = MAX_COLA;

    nuevaCola->datos = malloc (nuevaCola->capacidad * sizeof(int));
    if(nuevaCola->datos == NULL){
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

// Como ver para dar mas memoria
void cola_encolar(Cola *a, int x){
    //Arreglar aca
    if(a->primero == (a->ultimo + 1) % MAX_COLA){ //Cola llena
        (a->datos) = realloc ((a->datos), (a->capacidad * 2) * sizeof(int));
        if (a->datos == NULL){
            printf("Hubo error al redimensionar la pila");
            return;
        }
        if(a->primero > a->ultimo){ //Mover la parte derecha a la derecha (For - While)
            int aux= a->capacidad;
            for(int i=0; a->primero != a->capacidad - 1 - i; i++){ //Condicion si llega a primero
                a->datos[(a->capacidad * 2) - 1 - i] = a->datos[(a->capacidad)- 1 - i]; 
            }
            a->primero = a->capacidad;
        }
        a->capacidad*=2;
    }
    a->ultimo = (a->ultimo + 1) % MAX_COLA;
    a->datos[a->ultimo] = x;
}

void cola_desencolar(Cola *a){
    if (cola_es_vacia(a)){
        printf("La cola esta vacia");
        return;
    }
    
    a->primero= (a->primero + 1) % MAX_COLA;
}

void cola_imprimir(Cola *a){
    if (cola_es_vacia(a)){
        printf("La cola esta vacia");
        return;
    }
    
    for(int i=1; i <= abs(a->primero - a->ultimo) ; i++){
        printf("%i\n", a->datos[(a->primero + i) % MAX_COLA]);
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

    cola_imprimir(miCola);

    cola_destruir(miCola);
}