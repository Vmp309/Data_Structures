#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_dinamico.h"


int main (){

    /*Criando tabela hash*/
    Hash* tabela = cria_tabela();

    /*Criando uma struct de pessoa*/
    Pessoa* person1 = cria_pessoa("John Person Paraiba", 56454);

    Pessoa* person2 = cria_pessoa("Victoria Monteiro Pontes", 12345);

    Pessoa* person3 = cria_pessoa("Eu amo chocolate", 54321);

    /*Inserindo na tabela hash*/
    insere_hash(tabela, person1);

    insere_hash(tabela, person2);

    insere_hash(tabela, person3);
    
    print_table(tabela);
    
    /*Busca na tabela*/

    printf("%s\n", search_table(tabela, get_cpf(person1)));


    printf("%s\n", search_table(tabela, get_cpf(person2)));


    printf("%s\n", search_table(tabela, get_cpf(person3)));



    /*Retirando da tabela*/
    int teste;
    teste = retira_hash(tabela, get_cpf(person1));

    /*Confirmando que o item que foi retirado*/
    if(teste) printf("Item retirado");
    else printf("Item ainda estah na tabela");

    free_hash(tabela);






    return 0;
}