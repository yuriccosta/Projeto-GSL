#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <gsl/gsl_rng.h>

int main(int argc, char const *argv[]){
    int lin = 1000, col = 1000;

    for (int c = 1; c < argc; c++){
        if (strcmp(argv[c], "-s") == 0 || strcmp(argv[c], "-size") == 0){
            if (c + 2 < argc){
                lin = atoi(argv[c + 1]);
                col = atoi(argv[c + 2]);
            } else{
                printf("Digite os parâmetros da linha e coluna corretamente\n");
            }
        }
    }
    
    
    printf("Lin: %d, Col: %d\n", lin, col);

    //Definindo tipo do gerador T
    const gsl_rng_type * T = gsl_rng_random_glibc2;

    // Gerando instancia r do gerador T
    gsl_rng * r = gsl_rng_alloc(T);

    //Inicializando o gerador e passando a semente
    gsl_rng_set(r, 10);

    srand(10);

    //Note que o gsl_rng_random_glibc2 produz o mesmo valor que rand(), é o mesmo algoritmo!!
    for (int c = 0; c < 10; c++){
        printf("\nGerador rand padrão: %ld\n", rand());
        printf("Gerador rand gsl: %ld\n", gsl_rng_get(r));
    }
    
    //Liberando memória do gerador
    gsl_rng_free(r);
    
    return 0;
}
