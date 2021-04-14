#include <stdio.h>
#include <stdlib.h>
#include "pilha_dinamica.h"

int main (){

    Pilha *p;
    int i;

    /*Criando uma pilha vazia com vetor dinamico*/
    p = cria_pilha();

    printf("Endereco da alocacao de memoria: %x\n", p);



    /*Testando a funcao pilha_vazia*/
    if (pilha_vazia(p)){
        printf("Pilha vazia\n");
    }else{
        printf("Pilha nao vazia\n");
    }



    /*Adicionando o primeiro elemento na pilha*/
    pilha_push(p, 1);

    pilha_push(p, 2);

    pilha_push(p, 3);



    /*Testando a funcao pilha_vazia*/
    if (pilha_vazia(p)){
        printf("Pilha vazia\n");
    }else{
        printf("Pilha nao vazia\n");
    }



    /*Tirando elementos da pilha pelo topo*/
    int elemento;
    pilha_pop(p, &elemento);
    printf("Elemento do topo: %d\n", elemento);

    pilha_pop(p, &elemento);
    printf("Elemento do topo: %d\n", elemento);

    pilha_pop(p, &elemento);
    printf("Elemento do topo: %d\n", elemento);



    /*Excluindo a pilha por completo*/
    libera_pilha(p);


    return 0;
}