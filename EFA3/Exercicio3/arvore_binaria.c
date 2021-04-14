#ifndef ARVORE_BINARIA_C
#define ARVORE_BINARIA_C

#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

struct arvno{
    int info;
    ArvNo* esq;
    ArvNo* dir;
};

struct arv {
    ArvNo* raiz;
};

/*QUESTAO 1*/
/*FUNCAO QUE CONTA QUANTOS NUMEROS PARES EXISTEM NA ARVORE*/
/*Chama recursivamente busca_par*/
int pares (Arv* a){
    int contador_numpares = 0;
    
    busca_par(a->raiz, &contador_numpares);
    
    return contador_numpares;
}


/*Faz a busca pelos numeros pares nos noh*/
int busca_par(ArvNo *no, int *contador_numpares){

    if (no == NULL) return 0;
    
    int aux = no->info % 2;
    
    if(aux == 0){
        *contador_numpares = *contador_numpares + 1;
    }
        
    busca_par(no->esq, contador_numpares);
    busca_par(no->dir, contador_numpares);

    return 1; 
}



/*QUESTAO 2*/
/*FUNCAO QUE CONTA QUANTAS FOLHAS TEM NA ARVORE*/
/*Chama recursivamente conta_folhas*/
int folhas (Arv* a){
    int contador_folhas = 0;

    busca_folhas(a->raiz, &contador_folhas);
    
    return contador_folhas;
}

/*Busca folhas*/
int busca_folhas(ArvNo* no, int *contador_folhas){

    if (no == NULL) return 0;
    
    /*Compara para checar se o noh tem filhos*/
    if (no->esq == NULL && no->dir == NULL){
        *contador_folhas = *contador_folhas + 1;
    }

    busca_folhas(no->esq, contador_folhas);
    busca_folhas(no->dir, contador_folhas);

    return 1;
}

/*QUESTAO 3*/
/*FUNCAO QUE CONTA QUANTOS NOHS TEM APENAS UM FILHO*/
/*Chama recursivamente conta_filho*/
int um_filho(Arv* a){
    int contador_folhas = 0;
    busca_filho(a->raiz, &contador_folhas);
};


int busca_filho(ArvNo* no, int *contador_folhas){
    
    if (no == NULL) return 0;

    /*Nos dois ifs abaixo eh checado se o 
    noh possui apenas um filho*/
    if (no->dir == NULL && no->esq != NULL){
        *contador_folhas = *contador_folhas + 1;
    
    }else if(no->dir != NULL && no->esq == NULL){
        *contador_folhas = *contador_folhas + 1;
    }

    busca_filho(no->dir, contador_folhas);
    busca_filho(no->esq, contador_folhas);

    return 1;
};



/*Cria noh de arvore*/
ArvNo* arv_criano (int numero, ArvNo* esq , ArvNo* dir){
ArvNo* p = (ArvNo*) malloc(sizeof (ArvNo ));
    p->info = numero;
    p->esq = esq;
    p->dir = dir;

    return p;
}



/*Cria arvore*/
Arv* arv_cria (ArvNo* r){
    Arv* a = (Arv*) malloc(sizeof (Arv));
    a->raiz = r;
    return a;
}



static void imprime (ArvNo* r){
    if (r != NULL ){
        printf("%d", r->info); /*mostra informacao*/
        imprime(r->esq); /*imprime sae*/
        imprime(r->dir); /*imprime sad*/  
    }
}


void arv_imprime (Arv* a){
    imprime(a->raiz); /*imprime recursivamente a partir da raiz*/  
}


static void libera (ArvNo* r){

    if (r != NULL) {
        libera(r->esq); /*libera  a sae*/
        libera(r->dir); /*libera a sad*/
        free(r); /*libera o noh raiz */
    }
}


void arv_libera (Arv* a){
    libera(a->raiz);/* libera hierarquia de nós */ 
    free(a); /* libera raiz */
}

static ArvNo* busca(ArvNo* r, int numero){

    if (r == NULL)
        return NULL; /* árvore vazia: não encontrou*/

    else if (numero == r->info)
        return r;

    else{

        ArvNo* p = busca(r->esq , numero);/* busca na sae */ 

        if (p != NULL)
            return p; /* encontrou na sae */

        else
          return busca(r->dir, numero); /*busca na sad */

    }

}


ArvNo* arv_busca(Arv* a, int numero){

    return busca(a->raiz , numero);
}

#endif