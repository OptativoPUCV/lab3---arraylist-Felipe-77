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

    ArrayList * nuevaLista = (ArrayList *) malloc(sizeof(ArrayList));
    if (!nuevaLista) exit(EXIT_FAILURE);

    nuevaLista->data = (void *) malloc(sizeof(void *) * 2);
    if (!nuevaLista->data) exit(EXIT_FAILURE);

    nuevaLista->capacity = 2;
    nuevaLista->size = 0;

    return nuevaLista;
}

void append(ArrayList * l, void * data){
    if (l->size == l->capacity){
        l->capacity *= 2;

        l->data = (void *) realloc(l->data, sizeof(void*) * l->capacity);
        if (!l->data) exit(EXIT_FAILURE);
    }

    l->data[l->size] = data;

    l->size++;
}

void push(ArrayList * l, void * data, int i){
    if (i > l->size) return;

    if (l->size == l->capacity){
        l->capacity *= 2;

        l->data = (void *) realloc(l->data, sizeof(void*) * l->capacity);
        if (!l->data) exit(EXIT_FAILURE);
    }

    int k;
    for (k = l->size - 1; k >= i; k--) l->data[k + 1] = l->data[k];

    l->data[i] = data;

    l->size++;
}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    if (i > l->size) return NULL;

    void *aux;
    int indice;
    if (i < 0) indice = l->size + i;
    else indice = i;
    
    aux = l->data[indice];
    return aux;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
