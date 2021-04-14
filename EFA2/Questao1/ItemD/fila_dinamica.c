#ifndef _FILA_DINAMICA_C
#define _FILA_DINAMICA_C

#include <stdio.h>
#include <stdlib.h>
#include "fila_dinamica.h"

struct fila
{
    int *vetor; /*Vetor com elementos da fila*/
    int begin; /*posicao do inicio da fila*/
    int size; /*numero de elementos dentro da fila*/
    int dim; /*dimensão do vetor*/
};


/*Funcao para criar fila vazia*/
Fila* cria_fila(){
    Fila* f = (Fila*) malloc (sizeof(Fila));

    f->dim = 1;

    f->vetor = (int *) malloc (sizeof(int)*f->dim);

    f->begin = 0;    

    f->size = 0; /*Fila vazia*/ 
    
    return f;
};



/*Funcao para inserir elementos na fila*/
/*No caso da fila, os elementos sao adicionados ao
  final do vetor*/
int fila_push(Fila *fila, int elemento){

    int aux;

    if (fila->dim == fila->size){
        /*Se o vetor jah estiver cheio realocamos a memoria*/

        fila->dim *= 2; /*dobramos a capacidade do vetor*/

        fila->vetor = (int *) realloc (fila->vetor, sizeof(int) * fila->dim);

        if (fila->begin != 0){
            memmove(&fila->vetor[fila->dim - fila->begin], &fila->vetor[fila->begin],
            (fila->size - fila->begin)*sizeof(int
            ));
        }
    }


    aux = (fila->begin + fila->size) % fila->dim;
        fila->vetor[aux] = elemento;

        fila->size++;

    return 1;
};



/*Funcao para acessar ou retirar elemento da fila*/
/*No caso da fila, os elementos sao retirados no 
   inicio do vetor*/
int fila_pop(Fila*fila){

    int popped = fila->vetor[fila->begin];

    fila->begin = (fila->begin + 1) % fila->dim;
    fila->size--;

    return popped;
};



/*Funcao checa se a fila eh vazia*/
int fila_vazia(Fila *fila){
    return (fila->size == 0);
};


/*Funcao que exclui a fila completamente*/
void libera_fila(Fila *fila){
    free(fila->vetor);
    free(fila);
};





#endif