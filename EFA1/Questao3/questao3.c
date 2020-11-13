#include <stdlib.h>
#include <stdio.h>
#include "questao3.h"


/*Para implementar a matriz esparsa eh necesario que cada linha 
seja representada por uma lista em que cada noh corresponde a 
uma coluna em que a posicao(linha, coluna) seja um valor diferente
de zero */


struct no
{
    /* data */
    int j; // Numero da coluna
    float valor; //Valor armazenado na posicao (i, j)

    struct No* prox; /*Aponta para o proximo noh (ou coluna) em 
                        que a posicao (linha, coluna), o valor 
                        seja diferente de zero*/
};


struct matriz
{
    /* data */
    int n_linhas; // Numero de linhas da matriz
    int n_colunas;// Numero de colunas da matriz

    No** linha;
};












//Funcao que cria a matriz
//int m e n representam o numero de linhas e colunas da matriz respectivamente
Matriz * cria_matriz(int m, int n){
    int i;
    Matriz* matriz =  (Matriz *) malloc(sizeof(Matriz));

    matriz->n_linhas = m;
    matriz->n_colunas = n;
    matriz->linha = (No**) malloc (m * sizeof(No*));

    for (i = 0; i < m; i++){
        matriz->linha[i] = NULL;
    }


    return matriz;
};











//Funcao que remove a matriz esparsa
void remove_matriz(Matriz* matriz){
    
    int l;

    for (l = 0; l < matriz->n_linhas; l++){
        /*Checamos quais ponteiros estao nulos e quais nao estao*/
        if (matriz->linha[l] == NULL){
            continue;
        
        }else{
            /*Se nao estiver nulo, utilizamos a
             funcao insere_valor para inserirmos
              zero na posicao atual. A funcao insere_valor, 
              quando recebe o valor zero como numero a ser
               passado para a posicao, automaticamente elimina esse noh da lista
               pois o valor passado eh zero e nao deve ser armazenado*/
            No* aux;
            aux = matriz->linha[l];

            while(matriz->linha[l] != NULL || matriz->linha[l]->prox != NULL){
                insere_valor(matriz, l, aux->j, 0);

            }
        }
    }

    for (l = 0; l < matriz->n_linhas; l++){
        free(matriz->linha[l]);
    }

    free(matriz);
};
















//Funcao que insere um valor na posicao (i, j)
int insere_valor(Matriz* matriz, int i, int j, float valor){

    /*Primeiro checamos se os valores passados sao validos*/
    if (i >= matriz->n_linhas || j >= matriz->n_colunas || i < 0 || j < 0){
        return 0;
    }

    
    /*Devemos checar se a linha/lista eh vazia*/
    if (matriz->linha[i] == NULL){
        
        /*Criamos um noh para armazenar a coluna e o valor*/
        
        No* aux = malloc (sizeof(No));
        aux->prox = NULL;
        aux->j = j;
        aux->valor = valor;
        matriz->linha[i] = aux;
        
        printf("Valor inserido primeira vez: %f\n", aux->valor);
        printf("Coluna inserida primeira vez: %d\n", aux->j);
        return 1;
    
    }else{
        No* anterior;
        No* atual;
        
        anterior = NULL;
        atual = matriz->linha[i];
    
        /*Se a lista/linha nao for vazia temos que saber se o noh(coluna) jah existe na lista*/
        while(atual->prox != NULL && atual->j < j){
            
            anterior = atual;
            atual = atual->prox;
        }
        
        if (atual->j == j){
            
            if (valor == 0){
                /*Se o valor for igual a zero, deletamos o noh*/
                
                
                if (anterior == NULL){
                    
                    matriz->linha[i] = atual->prox;
                
                }else{

                    anterior->prox = atual->prox;

                }
                
                free(atual);
                return 1;

            }else{
                
                atual->valor = valor;
                return 1;
                
            }

        }else{
            /*Se nao houver noh na lista devemos criar um*/
            No* nova_coluna = malloc (sizeof(No));
            No* auxiliar;
            
            nova_coluna->valor = valor;
            nova_coluna->j = j;

            if (valor == 0){
                /*Se o valor for igual a zero, nao fazemos nada*/
                
                printf("Valor zerado\n");
                free(nova_coluna);
                return 1;
            }

            /*Se for diferente de zero, conectamos o noh a lista*/
            if (anterior == NULL){
                
                anterior = nova_coluna;
                nova_coluna->prox = atual;
                matriz->linha[i] = nova_coluna;
                printf("Valor da nova coluna: %f\n", nova_coluna->valor);
                printf("Numero da nova coluna: %d\n", nova_coluna->j);
                
                return 1;
            }else{

                anterior->prox = nova_coluna;
                nova_coluna->prox = atual;
                
                return 1;
            }
        }
    }
    
    return 0;
};
















//Funcao que retorna um valor na posicao (i, j)
float retorna_valor (Matriz* matriz, int i, int j){

    /*Checando se os valores passados sao validos*/
    if (i >= matriz->n_linhas || j >= matriz->n_colunas || i < 0 || j < 0){
        return 0;
    }
        
    //Selecionamos a linha correspondente
    No* aux;
    aux = matriz->linha[i];
    
    
    
    //Podemos percorrer a lista da linha i com o aux
    if (aux != NULL){
        
        while (aux->prox != NULL){
            
            if (aux->j > j || aux->j == j){
                break;
            }

            aux = aux->prox;
        }

        if (aux->j == j){/*Selecionamos a coluna que queremos*/
            return aux->valor;
        }
        
       return 0;
    
    }
    
    return 0;
}












//Funcao que remove um valor na posicao (i, j)
void remove_valor(Matriz* matriz, int i, int j){
    /*Utilizamos a funcao insere, que jah possui implementacao
    para remover noh se for zero o valor do parametro "valor"*/
    insere_valor(matriz, i, j, 0);
}













//Funcao que printa a matriz
int matriz_print(Matriz * matriz){

    int linhas = matriz->n_linhas;
    int colunas = matriz->n_colunas;

    int l;
    int c;
    float zero = 0;

    if (matriz_vazia(matriz)){
        for (l = 0; l < linhas; l++){
            printf("\n");

            for (c = 0; c < colunas; c++){
                printf ("%.2f ", zero);
            }
        }
        printf("\n");
        return 1;
    }

    for(l = 0; l < linhas; l++){
        
        printf("\n");

        for(c = 0; c < colunas; c++){
           
           printf("%0.2f ", retorna_valor(matriz, l, c));

        }
    }

    printf("\n");

    return 1;
};












//Funcoes auxiliares para a matriz

int matriz_vazia(Matriz* matriz){    
    /*Funcao que checa se todos 
    os elementos da matriz sao zero, 
    ou seja, se os ponteiros tem valor NULL*/

    int l;
    for (l = 0; l < matriz->n_linhas; l++){
        if (matriz->linha[l] != NULL){
            
            return 0; //A matriz nao estah vazia
        }
    }
    
    return 1;
}

int matriz_teste(Matriz* matriz, int i){

    if (matriz->linha[i] == NULL){
        printf("NAO TEM NADA AQUI\n");
    }else
    {
        printf("Tem algo aqui\n");
    }
    

}


