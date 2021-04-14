#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H


/*Define estruturas noh e arvore*/
typedef struct arvno ArvNo;

typedef struct arv Arv;


/*QUESTAO 1*/
/*FUNCAO QUE CONTA QUANTOS NUMEROS PARES HAH NA ARVORE*/
int pares(Arv* a);
int busca_par(ArvNo* no, int *contador_numpares);




/*Cria noh de arvore*/
ArvNo* arv_criano (int numero, ArvNo* esq , ArvNo* dir);


/*Cria arvore*/
Arv* arv_cria (ArvNo* r);





/*Imprimir conteudo da arvore*/
static void imprime (ArvNo* r);


void arv_imprime (Arv* a);





/*Libera memoria*/
static void libera (ArvNo* r);

void arv_libera (Arv* a);

/*Busca elemento na arvore*/
static ArvNo* busca(ArvNo* r, int numero);
ArvNo* arv_busca (Arv* a, int numero);


#endif