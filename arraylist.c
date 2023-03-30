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

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
