#include <stdlib.h>
#include <stdio.h>
#include "questao3.h"


int main (){

    Matriz* m = NULL;
    
    m = cria_matriz(2, 2);
    
    if (matriz_vazia(m)){
        printf("Matriz vazia\n");
    
    }else{
        
        printf("Matriz tem elemento nao nulo\n");    
    }

    matriz_print(m);

    
    int x;
    printf("Inserindo valor 3.5\n");
    x = insere_valor(m, 1, 1, 3.5);
    printf("Primeira insercao funcionou? %d\n", x);

    matriz_print(m);

    int z;
    printf("Inserindo valor 2.5\n");
    z = insere_valor(m, 1, 0, 2.5);
    printf("Segunda insercao funcionou? %d\n", z);

    printf("MATRIZ 2X2 COM ELEMENTOS INSERIDOS\n");
    matriz_print(m);

    float y;
    y = retorna_valor(m, 0, 0);
    printf("TESTE DE RETORNO DE VALOR - POSICAO(0, 0): %.2f\n", y);
    y = retorna_valor(m, 1, 0);
    printf(" SEGUNDO TESTE DE RETORNO DE VALOR - POSICAO(1, 0): %.2f\n", y);
    y = retorna_valor(m, 1, 1);
    printf("TERCEIRO TESTE DE RETORNO DE VALOR - POSICAO(1, 1): %.2f\n", y);
    




    if (matriz_vazia(m)){
        printf("Matriz vazia\n");
    
    }else{
        
        printf("Matriz tem elemento nao nulo\n");    
    }






    int input_zero; /*Lembrando que ao inserirmos zero, 
                    eliminamos um noh da lista, pois 
                    zeros nao devem ser armazenados*/
    input_zero = insere_valor(m, 1, 0, 0);

    matriz_print(m);

    
    //remove_matriz(m);
    
    /*if (m == NULL){
        printf("Matriz removida com sucesso\n");
    }else{
        printf("Erro ao excluir matriz\n");
    }*/

    //matriz_print(m);
    
    return 0;
}