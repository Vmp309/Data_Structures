#ifndef _PILHA_ENCADEADA_H
#define _PILHA_ENCADEADA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct elemento No;

typedef struct pilha Pilha;


/*Criar pilha vazia*/
Pilha * cria_pilha();


/*Inserir elemento no topo da pilha*/
int pilha_push(Pilha *pilha, int elemento);


/*Retornar ou retirar elemento da pilha*/
int pilha_pop(Pilha *pilha);



/*Checa se a pilha eh vazia*/
int pilha_vazia(Pilha *pilha);


/*Exclui a pilha completamente*/
void libera_pilha(Pilha **pilha);


/*Retorna o numero de elementos na pilha*/
int pilha_size(Pilha *pilha);

#endif