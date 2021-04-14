#ifndef _HASH_DINAMICO_C
#define _HASH_DINAMICO_C

#define N 1001

#include <stdio.h>
#include <stdlib.h>
#include "hash_dinamico.h"

struct pessoa
{
    char* nome;/*Nome da pessoa*/
    unsigned long int cpf;// Apenas os cinco ultimos numeros
};

struct hash
{
    Pessoa** lista; /*vetor de ponteiros para pessoas*/
    int tamanho; /*Capacidade do vetor*/
    int n_pessoas;/*quantidade de pessoas dentro do vetor*/
};



/*funcao cria_pessoa*/
Pessoa* cria_pessoa(char* nome_completo, unsigned long int cpf){
    Pessoa* p = (Pessoa*) malloc (sizeof(Pessoa));

    p->nome = nome_completo;
    p->cpf = cpf;
    return p;
};



/*funcao que retorna cpf da pessoa*/
unsigned long int get_cpf(Pessoa* pessoa){
    return pessoa->cpf;
};






/*Criamos a tabela hash vazia*/
Hash* cria_tabela(){
    int i;
    
    /*Alocamos memoria inicial para a estrutura*/
    Hash* h = (Hash*) malloc (sizeof(Hash));

    /*Alocamos memoria inicial para o vetor de ponteiros*/
    h->lista = (Pessoa*) malloc (sizeof(Pessoa)*N);

    /*Deixamos todos os ponteiros do vetor nulos*/
    for (i = 0; i < N; i++){
        h->lista[i] = NULL;
    }

    h->n_pessoas = 0;
    h->tamanho = N;

    return h;

};



/*Criamos a funcao hashing para dispersao dos elementos*/
unsigned long int hashing(Hash* ha, unsigned long int cpf){
    return cpf % (ha->tamanho);
};




/*Inserimos um elemento na tabela 
(utilizando método da primeira posicao 
livre para tratamento de colisoes)*/
int insere_hash (Hash* hash, Pessoa* person){
    int index = hashing(hash, person->cpf);

    /*Se o numero de elementos for 75% da capacidade do vetor
    realocamos mais espaco */
    int aux = 3 * hash->tamanho/4;

    if (hash->n_pessoas > aux){
        
        hash->tamanho *=2;
        printf("Foi utilizada a realocacao de memoria\n");
        hash->lista = (Pessoa*) realloc (hash->lista, sizeof(Pessoa)* hash->tamanho);
         
    }

    
    
    if (hash->lista[index] == NULL){
        hash->lista[index] = person;
        printf("Foi inserido na tebela hash\n");
        
    
    }else{
        printf("Teve que passar por tratamento de colisao na insercao");
        /*Tratando colisoes*/
        int i;
        int aux2;
        for(i = 0; i < hash->tamanho; i++){
            aux2 = (i + index) % hash->tamanho;
            
            if(hash->lista[aux2] == NULL){
                hash->lista[aux2] = person;
                break;
            }
        }
    }

    hash->n_pessoas++;
    
    return 1;
};






/*Retirando elementos do hash*/
int retira_hash(Hash* hash, unsigned long int cpf){
    unsigned long int index = hashing(hash, cpf);
    int aux;

    if(hash->lista[index]->cpf == cpf){
        free(hash->lista[index]);
        return 1;
    
    }else{
        for(int i = 0; i < hash->tamanho; i++){
            aux = (i + index) % hash->tamanho;

            if (hash->lista[aux]->cpf == cpf){
                free(hash->lista[aux]);
                return 1;
            }
        }
    }


    return 0;
};







/*Procurando por elementos na tabela de dispersao pelo cpf*/
char* search_table(Hash* hash, unsigned long int cpf){
    /*variavel que armazena o indice do vetor que queremos*/
    unsigned long int index = hashing(hash, cpf);
    int i;
    int auxiliar;
    char* nome;
    int flag = 0; /*Checa se foi encontrado*/

    if(hash->lista[index]->cpf == cpf){
        nome = hash->lista[index]->nome;
        flag++;
    }else{
        printf("Tratando colisoes na procura pelo meliante\n");
        /*Tratando colisoes*/
        for (i = 0; i < hash->tamanho; i++){
            auxiliar = (i + index) % hash->tamanho;        
            
            if(hash->lista[auxiliar]->cpf == cpf){
                nome = hash->lista[auxiliar]->nome;
                flag++;
                break;
            }
        }  
    }
    
    if (flag == 0){
        return "0"; /*Item nao encontrado*/
    }
    
    return nome;
};



/*Printando os itens da tabela*/
void print_table(Hash* hash){
    int i;
    for (i = 0; i < hash->tamanho; i++){
        if(hash->lista[i] != NULL){
            printf("Nome: %s, CPF: %d\n", hash->lista[i]->nome, hash->lista[i]->cpf);
        }
    };
};



/*Exclui a tabela hashing completamente*/
void free_hash(Hash* hash){
    int i;
    for (i = 0; i < hash->tamanho; i++){
        free(hash->lista[i]);
    }

    free(hash);
};




#endif