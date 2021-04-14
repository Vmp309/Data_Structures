#ifndef PILHA_DINAMICA
#include "pilha_dinamica.h"
#include <stdlib.h>
#include <stdio.h>


struct pilha
{
    int *vetor;
    int top;
    int vetor_size;
};







/*Cria pilha*/
Pilha * cria_pilha(){
    Pilha *pi;
    pi = (Pilha *) malloc (sizeof(Pilha));

    if (pi){
        pi->top = -1;
        pi->vetor = (int *) malloc (sizeof(int));
        pi->vetor_size = 1; /*Cabe um elemento no vetor*/
    }
    
    return pi;
}






/*Insere elemento no topo da pilha*/
int pilha_push(Pilha *pilha, int elemento){

    if (pilha->top == -1){

        /*Se for o primeiro elemento
          a ser inserido*/

        pilha->vetor[0] = elemento;

        pilha->top += 1;
        printf("Testanto se deu certo: %d\n", pilha->vetor[0]);
        return 1;

    }else if (pilha->top == pilha->vetor_size - 1) {
        /*Se a pilha jah estiver cheia
          alocamos um novo espaco*/

        pilha->top += 1;

        int posicao = pilha->top;

        pilha->vetor = (int *) realloc (pilha->vetor, (pilha->vetor[0] + pilha->top)*sizeof(int));

        if (pilha->vetor){
            pilha->vetor[posicao] = elemento;
            printf("Testanto se deu certo: %d\n", pilha->vetor[posicao]);
            return 1;
        }

    }else{
        /*Se a pilha ainda nao 
           estiver cheia apenas 
           inserimos o elemento*/

        pilha->top += 1;
        int posicao = pilha->top;
        pilha->vetor[pilha->top] = elemento;
        printf("Testanto se deu certo: %d\n", pilha->vetor[posicao]);
        return 1;
    }

    return 0;
}















/*Retorno de elemento que estah no topo*/
int pilha_pop(Pilha *pilha, int *elemento){

    if(!pilha)
        return 0;
    
    if(pilha->top == -1)
        return 0;
    
    *elemento = pilha->vetor[pilha->top];
    pilha->top -= 1;    
    return 1;

}










/*Funcao que checa se a pilha eh vazia*/
int pilha_vazia (Pilha *pilha){
    return (pilha->top == -1);
}










/*Exclui a pilha completamente*/
void libera_pilha(Pilha *pilha){
    free(pilha->vetor);
    free(pilha->top);
    free(pilha->vetor_size);
    free(pilha);
};



#endif