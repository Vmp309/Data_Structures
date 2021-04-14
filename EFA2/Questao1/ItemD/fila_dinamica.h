#ifndef _FILA_DINAMICA_H
#define _FILA_DINAMICA_H

typedef struct fila Fila;


/*Funcao para criar fila vazia*/
Fila* cria_fila();


/*Funcao para inserir elementos na fila*/
int fila_push(Fila *fila, int elemento);


/*Funcao para acessar ou retirar elemento da fila*/
int fila_pop(Fila*fila);


/*Funcao checa se a fila eh vazia*/
int fila_vazia(Fila *fila);


/*Funcao que exclui a fila completamente*/
void libera_fila(Fila *fila);

#endif