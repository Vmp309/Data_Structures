#ifndef FILA_ENCADEADA_C
#define FILA_ENCADEADA_C

#include<stdio.h>
#include<stdlib.h>
#include "fila_encadeada.h"

struct elemento
{
    int valor;
    No* prox;
};

struct fila
{
    No* inicio;
    No* fim;
    int size;
};


/*Cria fila vazia*/
Fila* cria_fila(){

    /*Aloca-se memoria mas nenhum valor eh inserido*/
    Fila* fila = (Fila*) malloc (sizeof(Fila));

    fila->fim = NULL;

    fila->inicio = NULL;

    fila->size = 0;

};


/*insere elemento no final da fila*/
int fila_push(Fila *fila, int elemento){
    /*Criamos um noh para percorrer a fila*/
    No* aux = (No*) malloc (sizeof(No));

    aux->prox = NULL;
    aux->valor = elemento;

    if(fila->fim == NULL){
        fila->inicio = aux;

    }else{
        fila->fim->prox = aux;
    }
    
    fila->fim = aux;

    fila->size++;
};


/*Retira e retorna elemento do inicio da fila*/
int fila_pop(Fila *fila){
    /*Noh auxiliar para percorrer lista*/
    No* aux = fila->inicio;
    int popped;

    popped = aux->valor;
    fila->inicio = aux->prox;

    free(aux);
    if (!fila->inicio){
        fila->fim = NULL;
    }

    fila->size--;
    return popped;
};


/*Checa se a fila eh vazia*/
int fila_vazia(Fila *fila){
    return (fila->inicio == NULL);
};



/*Exclui a fila completamente*/
void libera_fila(Fila *fila){
    /*Devemos percorrer a lista, apagando elemento
    por elemento*/
    int i;
    No* aux1 = fila->inicio;
    
    while (aux1)
    {
        /* code */
        No* aux2;
        aux2 = fila->inicio->prox;
        free(aux1);

        aux1 = aux2;
    }

    free(fila);
};



int fila_size(Fila* fila){
    return fila->size;
}




void print_fila(Fila* fila){
    No* aux = fila->inicio;
    while (aux != NULL){
        printf("Componente da fila: %d\n", aux->valor);

        aux = aux->prox;
    }
}

#endif