#include <stdlib.h>
#include <stdio.h>
#include "fila_encadeada.h"


int main (){

    int i;
    int valor;

    /*Criando fila vazia*/
    Fila *fi;
    fi = cria_fila();

    printf("Endereco de memoria alocada para a TAD: %x\n", fi);




    /*Testando se a fila eh vazia*/
    if (fila_vazia(fi)){
        printf("Vazia\n");
    }else
    {
        printf("Nao vazia\n");
    }
    



    /*Inserindo elementos*/
    for(i = 0; i < 7; i++){
        fila_push(fi, i);
    }

    printf("Tamanho da fila depois da insercao: %d\n", fila_size(fi));



    /*Testando se a fila eh vazia novamente*/
    if (fila_vazia(fi)){
        printf("Vazia\n");
    }else
    {
        printf("Nao vazia\n");
    }
    
    
    print_fila(fi);
    
    /*Retirando e retornando elementos*/
    for (i = 0; i < 7; i++){
        
        printf("Elemento retirado da fila: %d  ", fila_pop(fi));
        printf("Tamanho da fila: %d\n\n", fila_size(fi));
    }


    libera_fila(fi);


    return 0;
}