#ifndef _LINKED_LIST_C
#define _LINKED_LIST_C

#include <stdio.h>
#include <stdlib.h>
#include "questao2.h"


struct elemento
{
  int inteiro; //Inteiro que eh elemento do conjunto

  struct no* prox;  //Ponteiro que aponta para o proximo noh ou proximo elemento
};

//Funcao uniao dos conjuntos
No* conjunto_uniao(No* cabeca1, No* cabeca2){
    No* uniao;
    No* aux1 = diferenca(cabeca1, cabeca2); //Armazena a cabeca da lista que possui a diferenca (A-B)
    No* aux2 = diferenca(cabeca2, cabeca1); //Armazena a cabeca da lista que possui a diferenca (B-A)
    No* aux3 = interseccao(cabeca1, cabeca2); // Armazena a cabeca da lista que possui a interseccao de A e B
    
    uniao = aux1;

    while(aux1->prox != NULL){
        
        aux1 = aux1->prox;
    }
    
    conjunto_print(aux1, "aux1: ");

    aux1->prox = aux2;

    while(aux2->prox != NULL){
        aux2 = aux2->prox;
    }
    conjunto_print(aux1, "aux2: ");

    aux2->prox = aux3;

    conjunto_print(aux1, "aux2: ");

    return uniao;
    
}









//Funcao cria conjunto vazio
No* cria_conjunto_vazio () {
    No* ptr = (No*) malloc(sizeof(No*)); //Alocou espaço para um no mas esta vazio

    ptr->inteiro = NULL;
    ptr->prox = NULL;
    return ptr;
}






//Funcao insere: Esta funcao insere os elementos que ainda nao pertencem ao conjunto
int insere_elemento_inicio(No** cabeca, int inteiro){

    if (elemento_pertence_conjunto(*cabeca, inteiro)){
        printf("Jah pertence ao conjunto\n");
        return 0;
    }


    No* aux = cria_no(inteiro);
    
    if(aux != NULL)
    {
        //printf("Nao pertence entao insere\n");
        aux->prox = *cabeca;
        *cabeca = aux;
        return 1;
    }

    return 0;
}



















//Funcao remove (Varre a lista para achar todos os conteudos desejados e os remove)
int remove_elemento(No** cabeca, int inteiro){
      
    No* atual;
    No* anterior = NULL;
    No* auxiliar;
    atual = cabeca;
    int flag = 0; //Avisa se o item foi removido

    while (atual != NULL){
        if (atual->inteiro == inteiro){
            flag++;

            auxiliar = atual;

            anterior->prox = atual->prox;

            atual = auxiliar->prox;

            free(atual);

            break;

        }
        
        anterior = atual;
        atual = atual->prox;
    }

    printf("Flag: %d\n", flag);
    return flag;
}

















//Funcao Interseccao
No* interseccao(No* cabeca1, No* cabeca2){
    No* aux1;
    No* aux2;

    aux1 = cabeca1; //Auxiliares para não percorrer o noh com a cabeca
    aux2 = cabeca2;

    No* inicial = NULL; // Noh inicial que vai ser a cabeca da lista que representa a intersecacao dos conjuntos

    int flag = 0; //A flag avisa quando o elemento de um conjunto eh igual ao conjunto do outro

    while(aux1 != NULL){
        flag = 0;
        aux2 = cabeca2;

        while (aux2 != NULL){
            if (aux1->inteiro == aux2->inteiro){
                flag = 1;
                break;
            }

            aux2 = aux2->prox;
        }

        if (flag == 1){
            insere_elemento_inicio(&inicial, aux1->inteiro);
        }
        aux1 = aux1->prox;
    }

    return inicial;

}
















// Funcao diferenca
No* diferenca(No* cabeca1, No* cabeca2){
    No* aux1;
    No* aux2;
    aux1 = cabeca1;
    aux2 = cabeca2;
    No* inicial = NULL; //Noh que vai iniciar a lista de elementos resultantes da diferenca entre conjuntos
    int flag = 0; //Avisa quando o elemento de cabeca1 tambem esta presente em cabeca2
    while(aux1 != NULL){
        flag = 0;
        aux2 = cabeca2;

        while(aux2 != NULL){
            
            if (aux1->inteiro == aux2->inteiro){
                break;
            }

            flag++;
            aux2 = aux2->prox;
        }

        if (flag == conjunto_tamanho(cabeca2)){

            insere_elemento_inicio(&inicial, aux1->inteiro);                
        }

        aux1 = aux1->prox;
    }
    
    return inicial;
}














//Funcao Testa se o numero pertence ao conjunto
int elemento_pertence_conjunto(No* cabeca, int inteiro){
    No* aux;
    aux = cabeca;
    while (aux != NULL){
        if (aux->inteiro == inteiro){
            //printf("Pertence sim\n");

            return 1;
        }
        aux = aux->prox;
    }
    
    //printf("Nao pertence\n");
    return 0;
}















//Funcao menor valor
int menor_valor(No* cabeca){
    No* aux;
    aux = cabeca;
    int menor = aux->inteiro;


    while (aux != NULL){

        if (aux->inteiro < menor){
            menor = aux->inteiro;
        }

        aux = aux->prox;
    }

    printf("%d\n", menor);
    return menor;
}












//Funcao maior valor
int maior_valor(No* cabeca){
    No* aux; 
    aux = cabeca;
    int maior = aux->inteiro;

    while (aux != NULL){
        if (aux->inteiro > maior){
            maior = aux->inteiro;
        }
        aux = aux->prox;
    }


    printf("%d\n", maior);
    return maior;
}










//Funcao Testa se os conjuntos sao iguais
int conjuntos_iguais(No* cabeca1, No* cabeca2){
    
    //Testa se o tamanho das listas eh diferente
    if (conjunto_tamanho(cabeca1) != conjunto_tamanho(cabeca2)){
        return 0;
    }
     
    int tamanho_cabeca = conjunto_tamanho(cabeca1);
    int contador = 0;
    No* aux1;
    No* aux2;
    aux1 = cabeca1;
    aux2 = cabeca2;
    

    while(aux1 != NULL){
    
        if (elemento_pertence_conjunto(cabeca2, aux1->inteiro)){
            contador++;
        }
          
        aux1 = aux1->prox;
    }

    if (contador == tamanho_cabeca){
        return 1;
    }else{
        return 0;
    }
}









//Funcao Retorna o tamanho do conjunto
int conjunto_tamanho (No* cabeca){
    int contador = 0;
    No* aux;
    aux = cabeca;
    while (aux != NULL){
        aux = aux->prox;
        contador++;
    }

    //printf("Tamanho do conjunto: %d\n", contador);
    return contador;
}











//Testa se o conjunto eh vazio
int conjunto_vazio (No* cabeca){
    printf("O conjunto é vazio? %d\n", (cabeca->prox == NULL) && (cabeca->inteiro == NULL));
    return(cabeca == NULL);
}








//Cria no
No * cria_no (int inteiro){
    No* no = (No *) malloc (sizeof(No));

    if (no != NULL){
        no->inteiro = inteiro;
        no->prox = NULL;

    }else{
        printf("OPS! ERRO DE ALOCACAO DE MEMORIA\n");
    }
    return no;
} 









int conjunto_existe(No* cabeca, int inteiro)
{
     if(conjunto_vazio(cabeca))
          return 0;
     
     while(cabeca != NULL)
     {
         if(cabeca->inteiro == inteiro)
             return 1;
         
         cabeca = cabeca->prox;
     }
     
     return 0;
}









void conjunto_print(No* cabeca, char* message)
{
    printf("%s ", message);
    while(cabeca != NULL)
    {
        printf("%d ", cabeca->inteiro);
        cabeca = cabeca->prox;
    }
    printf("\n");
}

void conjunto_exclui(No** cabeca)
{
    No* prox = NULL;
    No * aux = *cabeca;
    while(aux != NULL)
    {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
    
    *cabeca = NULL;
}








#endif