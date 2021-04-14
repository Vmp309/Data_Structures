#ifndef _PILHA_ENCADEADA_C
#define _PILHA_ENCADEADA_C

#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"

struct elemento
{
    int elemento;
    struct No *prox;
};

struct pilha
{
    struct No* elemento_topo;
    int topo;
};




/*Criar pilha vazia*/
Pilha * cria_pilha(){
    
    Pilha* p = (Pilha *) malloc (sizeof(Pilha));
    p->elemento_topo = (No*) malloc (sizeof(No));
    p->topo = 0;
    return p;
}



/*Inserir elemento no topo da pilha*/
int pilha_push(Pilha *pilha, int elemento){
    No* node = (No*) malloc (sizeof(No));
    node->prox = NULL;
    node->elemento = elemento;

    if (pilha->topo == 0){
        pilha->elemento_topo = node;
        pilha->topo = 1;

        printf("Numero no topo da pilha: %d\n", node->elemento);
        printf("Numero de elementos inseridos: %d\n", pilha->topo);
    
    }else{

        No* aux;
        aux = pilha->elemento_topo;
        pilha->elemento_topo = node;
        node->prox = aux;

        pilha->topo += 1;

        printf("Numero no topo da pilha: %d\n", node->elemento);
        printf("Numero de elementos inseridos: %d\n", pilha->topo);
    
    }
    
};




/*Retornar ou retirar elemento da pilha*/
int pilha_pop(Pilha *pilha){
    No* aux;
    int elemento;
    aux = pilha->elemento_topo;
    elemento = aux->elemento;
    pilha->elemento_topo = aux->prox;

    pilha->topo -= 1;
    
    free(aux);

    return elemento;
};



/*Checa se a pilha eh vazia*/
int pilha_vazia(Pilha *pilha){
    
    return (pilha->topo == 0);
};



/*Exclui a pilha completamente*/
void libera_pilha(Pilha **pilha){
    No* aux; /*Noh que percorre os elementos da pilha*/
    Pilha* auxiliar = pilha;
    
    int size = auxiliar->topo;
    int i;

    for (i = 0; i < size; i++){
        /*Liberando memoria de noh em noh*/
        aux = auxiliar->elemento_topo;
        auxiliar->elemento_topo = aux->prox;
        free(aux);
    }

    free(auxiliar);
    free(*pilha);
    free(pilha);
    *pilha = NULL;
};

/*Retorna o numero de elementos na pilha*/
int pilha_size(Pilha *pilha){
    return pilha->topo;
};




#endif