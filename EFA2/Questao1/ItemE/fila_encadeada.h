#ifndef FILA_ENCADEADA_H
#define FILA_ENCADEADA_H


typedef struct elemento No;


typedef struct fila Fila;


/*Cria fila vazia*/
Fila* cria_fila();


/*insere elemento no final da fila*/
int fila_push(Fila *fila, int elemento);


/*Retira e retorna elemento do inicio da fila*/
int fila_pop(Fila *fila);


/*Checa se a fila eh vazia*/
int fila_vazia(Fila *fila);


/*Exclui a fila completamente*/
void libera_fila(Fila *fila);


/*Retorna o tamanho da fila*/
int fila_size(Fila* fila);


void print_fila(Fila *fila);

#endif