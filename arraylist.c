#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {

    ArrayList * nuevaLista = (ArrayList *) malloc(sizeof(ArrayList));   //Primero se reserva memoria para la lista
    if (!nuevaLista) exit(EXIT_FAILURE);                                //y se comprueba que la reserva se haya hecho correctamente

    nuevaLista->data = (void *) malloc(sizeof(void *) * 2);             //Reservamos memoria para el arreglo que almacenará los datos
    if (!nuevaLista->data) exit(EXIT_FAILURE);

    nuevaLista->capacity = 2;       //Inicializacion de los parametros de la lista
    nuevaLista->size = 0;

    return nuevaLista;
}

void append(ArrayList * l, void * data){
    if (l->size == l->capacity){        //En esta condicional verificamos si el arreglo esta lleno
        l->capacity *= 2;               //De ser así, se incrementa su tamaño al doble 

        l->data = (void *) realloc(l->data, sizeof(void*) * l->capacity);
        if (!l->data) exit(EXIT_FAILURE);
    }

    l->data[l->size] = data;        //Guardamos el dato en la ultima posicion

    l->size++;                      //Aumenta el size del arreglo
}

void push(ArrayList * l, void * data, int i){
    if (i > l->size) return;        //Comprobamos para un i válido

    if (l->size == l->capacity){    //En esta condicional verificamos si el arreglo esta lleno
        l->capacity *= 2;           //De ser así, se incrementa su tamaño al doble 

        l->data = (void *) realloc(l->data, sizeof(void*) * l->capacity);
        if (!l->data) exit(EXIT_FAILURE);
    }

    int k;
    for (k = l->size - 1; k >= i; k--) {        //Bucle para mover los datos una casilla a la derecha
        l->data[k + 1] = l->data[k];
    }

    l->data[i] = data;

    l->size++;
}

void* pop(ArrayList * l, int i){
    if (i > l->size) return NULL;

    void *aux = (i < 0) ? l->data[l->size + i] : l->data[i];

    int k;
    for (k = i; k < l->size; k++){
        l->data[k] = l->data[k + 1];
    }
    l->size--;

    return aux;
}

void* get(ArrayList * l, int i){
    if (i > l->size) return NULL;       //Verificamos que i sea válido

    return (i < 0) ? l->data[l->size + i] : l->data[i];     //Retornamos el dato que corresponda segun el signo de i
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
