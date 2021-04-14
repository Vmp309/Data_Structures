#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main (){

// cria a arvore
Arv* a = arv_cria(
    arv_criano(1,
            arv_criano(2, NULL ,
                    arv_criano(3, NULL , NULL)
            ),

        arv_criano(4,
            arv_criano(5, NULL , NULL), arv_criano(6, NULL , NULL)
        )

    )

);

/*Printa a quantidade de numeros pares*/
printf("Quantidade de numeros pares na arvore: %d\n",  pares(a));


/*Imprime os nohs da arvore*/
arv_imprime(a);


arv_libera(a);

return 0;
}