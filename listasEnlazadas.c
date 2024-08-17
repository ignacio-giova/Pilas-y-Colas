#include <stdio.h>
#include <stdlib.h>

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo* SList;

int main() {
  SNodo *nuevo_nodo = malloc(sizeof(SNodo));
  // Es equivalente escribir:
  // SList nuevo_nodo = malloc(sizeof(SNodo));

  nuevo_nodo->dato = 5;
  nuevo_nodo->sig = NULL;

  // Quiero agregar un nodo a la lista, lo puedo agregar
  // al principio o al final

  // Agregado al principio
  SNodo *otro_nodo = malloc(sizeof(SNodo));
  otro_nodo->dato = 5;
  otro_nodo->sig = nuevo_nodo;

  // Agregado al final
  SNodo *otro_nodo_mas = malloc(sizeof(SNodo));
  otro_nodo_mas->dato = 9;
  otro_nodo_mas->sig = NULL;
  nuevo_nodo->sig = otro_nodo_mas;
  // Alternativa
  // nuevo_nodo->sig = malloc(sizeof(SNodo));
  // nuevo_nodo->sig->dato = 5;
  // nuevo_nodo->sig->sig = NULL;

  free(nuevo_nodo);
  free(otro_nodo);
  free(otro_nodo_mas);
  return 0;
}