#include <stdlib.h>
#include <stdio.h>
#include "fila_dinamica.h"


int main () {

    /*Testando funcao que cria pilha vazia*/
    Fila* fi = cria_fila();

    printf ("Endereco da memoria alocada para a fila: %x\n", fi);

    /*Testando a funcao que checa se a pilha eh vazia*/
    if (fila_vazia(fi)){
        printf("Pilha vazia\n");
    
    }else{
        printf("Pilha nao vazia\n");
    }
    

    /*Testando a funcao de insercao de elementos na fila*/
    fila_push(fi, 1);

    fila_push(fi, 30);

    fila_push(fi, 15);

    /*Testando se a fila esta vazia novamente*/
    if (fila_vazia(fi)){
        printf("Pilha vazia\n");
    
    }else{
        printf("Pilha nao vazia\n");
    }
    

    /*Testando a retirada ou acesso aos elementos da fila*/
    printf("Primeiro elemento da fila: %d\n", fila_pop(fi));

    printf("Primeiro elemento da fila: %d\n", fila_pop(fi));

    printf("Primeiro elemento da fila: %d\n", fila_pop(fi));

    return 0;
}