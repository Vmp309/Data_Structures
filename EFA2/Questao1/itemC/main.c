#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"

int main (){

    /*Testando a criacao da pilha*/
    Pilha* pi;
    pi = cria_pilha();

    printf("Endereco de memoria alocado para a pilha: %x\n", pi);




    /*Testando insercao de elemento na pilha*/
    pilha_push(pi, 2);

    pilha_push(pi, 4);

    pilha_push(pi, 50);

    printf("Numero de elementos antes da retirada: %d\n\n", pilha_size(pi));


    /*Testanto retirada dos elementos do topo*/
    int valor_topo1 = pilha_pop(pi);
    printf("Elemento no topo da pilha: %d\n Numero de elementos atualizado: %d\n\n", valor_topo1, pilha_size(pi));

    int valor_topo2 = pilha_pop(pi);
    printf("Elemento no topo da pilha: %d\n Numero de elementos atualizado: %d\n\n", valor_topo2, pilha_size(pi));

    int valor_topo3 = pilha_pop(pi);
    printf("Elemento no topo da pilha: %d\n Numero de elementos atualizado: %d\n\n", valor_topo3, pilha_size(pi));


    libera_pilha(&pi);

    return 0;
}