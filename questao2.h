#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

//Lembrando que cada lista eh um conjunto de inteiros e cada no eh um elemento do conjunto, logo:
typedef struct elemento No;

//INICIO DA QUESTAO

//Funcao uniao dos conjuntos
No* conjunto_uniao(No* cabeca1, No* cabeca2);


//Funcao cria conjunto vazio
No* cria_conjunto_vazio();


//Funcao insere
int insere_elemento_inicio(No ** cabeca, int inteiro);


//Funcao remove
int remove_elemento(No** cabeca, int inteiro);



//Funcao Interseccao
No* interseccao(No* cabeca1, No* cabeca2);




// Funcao diferenca
No* diferenca (No* cabeca1, No* cabeca2);




//Funcao Testa se o numero pertence ao conjunto
int elemento_pertence_conjunto(No* cabeca, int inteiro);




//Funcao menor valor
int menor_valor (No* cabeca);




//Funcao maior valor
int maior_valor (No* cabeca);





//Funcao Testa se os conjuntos sao iguais
int conjuntos_iguais(No* cabeca1, No* cabeca2);





//Funcao Retorna o tamanho do conjunto
int conjunto_tamanho(No* cabeca);





//Testa se o conjunto eh vazio
int conjunto_vazio(No* cabeca);





//FIM DA QUESTAO


// Funcoes que auxiliam na implementacao das funcoes pedidas na questao


//Cria no
No * cria_no(int inteiro);


int conjunto_existe(No* cabeca, int inteiro);

void conjunto_print(No* cabeca, char* message);

void conjunto_excluir(No** cabeca);



#endif