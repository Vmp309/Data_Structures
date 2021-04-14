#ifndef _HASH_DINAMICO_H
#define _HASH_DINAMICO_H


/*Definimos as estruturas*/
typedef struct pessoa Pessoa;

typedef struct  hash Hash;



/*funcao cria_pessoa*/
Pessoa* cria_pessoa(char* nome_completo, unsigned long int cpf);


/*funcao que retorna cpf da pessoa*/
unsigned long int get_cpf(Pessoa* pessoa);


/*Criamos a tabela hash vazia*/
Hash* cria_tabela();


/*Criamos a funcao hashing para dispersao dos elementos*/
unsigned long int hashing(Hash* ha, unsigned long int cpf);


/*Criamos uma segunda funcao hashing para o tratamento de coisões*/
unsigned long int hashing2(Hash* ha, unsigned long int cpf);



/*Inserimos um elemento na tabela 
(utilizando método da double hashing
para o tratamento de colisoes)*/
int insere_hash (Hash* hash, Pessoa* person);





/*Retirando elementos do hash*/
int retira_hash(Hash* hash, unsigned long int cpf);



/*Procurando por elementos na tabela de dispersao pelo cpf*/
char* search_table(Hash* hash, unsigned long int cpf);

/*Printa os itens da tabela*/
void print_table(Hash* hash);

/*Exclui a tabela hashing completamente*/
void free_hash(Hash* hash);






#endif