#include "questao2.h"
#include <stdio.h>
#include <stdlib.h>



int main (){

No* conjuntoA = NULL;

No* conjuntoB = NULL;



//Testando criar conjunto vazio
No* conjunto_que_eh_vazio;
conjunto_que_eh_vazio = cria_conjunto_vazio();
conjunto_vazio(conjunto_que_eh_vazio);






//Testando funcao inserir

insere_elemento_inicio(&conjuntoA, 1);

insere_elemento_inicio(&conjuntoA, 2);

insere_elemento_inicio(&conjuntoA, 3);

insere_elemento_inicio(&conjuntoA, 4);

insere_elemento_inicio(&conjuntoA, 5);

insere_elemento_inicio(&conjuntoA, 5);// A funcao insere elemento dirah que esse elemento ja pertence ao conjuntoA

conjunto_print(conjuntoA, "Conjunto A:");

 


insere_elemento_inicio(&conjuntoB, 9);

insere_elemento_inicio(&conjuntoB, 7);

insere_elemento_inicio(&conjuntoB, 6);

insere_elemento_inicio(&conjuntoB, 8);

insere_elemento_inicio(&conjuntoB, 3);

conjunto_print(conjuntoB, "Conjunto B:");





//Testando Uniao
No* conjunto_uniaoAB = conjunto_uniao(conjuntoA, conjuntoB);
conjunto_print(conjunto_uniaoAB, "Conjunto (A U B):");




//Testando funcao remover
printf("Teste de remocao:\n");
remove_elemento(conjuntoA, 1);
conjunto_print(conjuntoA, "Conjunto A:");








//Testando funcao interseccao

No* conjunto_interseccao;
conjunto_interseccao = interseccao(conjuntoA, conjuntoB);
conjunto_print(conjunto_interseccao, "Conjunto A interseccao B:");





//Testando funcao diferenca

No* conjunto_diferencaAB = NULL; 

No* conjunto_diferencaBA = NULL; 


conjunto_diferencaAB = diferenca(conjuntoA, conjuntoB);

conjunto_print(conjunto_diferencaAB, "Conjunto diferenca (A - B):");

conjunto_diferencaBA = diferenca(conjuntoB, conjuntoA);

conjunto_print(conjunto_diferencaBA, "Conjunto diferenca(B - A): ");








//Testando funcao "Elemento pertence ao conjunto?"
elemento_pertence_conjunto(conjuntoA, 1);
elemento_pertence_conjunto(conjuntoA, -50);








//Testando funcao menor valor
printf("Menor valor do Conjunto A: ");
menor_valor(conjuntoA);

printf("Menor valor do Conjunto B: ");
menor_valor(conjuntoB);






//Testando funcao maior valor
printf("Maior valor do Conjunto A: ");
maior_valor(conjuntoA);

printf("Maior valor do Conjunto B: ");
maior_valor(conjuntoB);






//Testando funcao "Conjuntos iguais?"
printf("Teste da funcao conjuntos_iguais:\n");
No* conjuntoX = NULL;
No* conjuntoY = NULL;
No* conjuntoD = NULL;
No* conjuntoT = NULL;
int resposta;

insere_elemento_inicio(&conjuntoX, 1);
insere_elemento_inicio(&conjuntoX, 2);
insere_elemento_inicio(&conjuntoY, 1);
insere_elemento_inicio(&conjuntoY, 2);
insere_elemento_inicio(&conjuntoD, 2);
insere_elemento_inicio(&conjuntoT, 5);
insere_elemento_inicio(&conjuntoT, 7);



resposta = conjuntos_iguais(conjuntoX, conjuntoY);
printf("Os conjuntos X e Y sao iguais? %d\n", resposta);

resposta = conjuntos_iguais(conjuntoX, conjuntoD);
printf("Os conjuntos X e D sao iguais? %d\n", resposta);

resposta = conjuntos_iguais(conjuntoX, conjuntoT);
printf("Os conjuntos X e T sao iguais? %d\n", resposta);






//Testando funcao tamanho do conjunto
int x;
x = conjunto_tamanho(conjuntoB);
printf("Tamanho do conjunto B: %d\n", x);





//Testando funcao "conjunto vazio"?
conjunto_vazio(conjuntoB);

return 0;

}
