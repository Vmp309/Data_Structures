#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/*Para implementarmos uma matriz esparsa, devemos tratar cada linha da matriz como
uma lista encadeada de modo que possamos armazenar somente os valores que sao diferentes
de zero
*/


//Formato da estrutura
typedef struct no No;

typedef struct matriz Matriz;


//INICIO DA QUESTAO

//Funcao cria a matriz esparsa
Matriz* cria_matriz (int n_linhas, int n_colunas);


//Funcao remove a matriz esparsa
void exclui_matriz(Matriz* matriz);


//Funcao insere um valor na posicao (i, j)
int insere_valor(Matriz* matriz, int i, int j, float valor);


//Funcao retorna um valor na posicao (i, j)
float retorna_valor();


//Funcao remove um valor na posicao (i, j)
void remove_valor(Matriz* matriz, int i, int j);


//Funcao exibir na tela a matriz (com todos os seus zeros não armazenados)
int matriz_print(Matriz* matriz);

//FIM DA QUESTAO



//Funcoes auxiliares para a matriz
int matriz_vazia(Matriz* matriz);

//Funcao teste
int matriz_teste(Matriz* matriz, int i);


#endif
