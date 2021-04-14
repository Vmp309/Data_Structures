#ifndef PILHA_DINAMICA
#define PILHA_DINAMICA


typedef struct pilha Pilha;


/*Cria pilha vazia*/
Pilha * cria_pilha();


/*Insere elemento no topo da pilha*/
int pilha_push(Pilha *pilha, int elemento);

/*Retorno de elemento que estah no topo*/
int pilha_pop(Pilha *pilha, int *elemento);

/*Funcao que checa se a pilha eh vazia*/
int pilha_vazia(Pilha *pilha);

/*Exclui a pilha completamente*/
void libera_pilha(Pilha *pilha);

#endif