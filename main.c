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
    
    const gsl_rng_type **t, **t0;

    t0 = gsl_rng_types_setup ();

    printf ("Available generators:\n");

    for (t = t0; *t != 0; t++)
    {
        printf ("%s\n", (*t)->name);
    }
    printf("Lin: %d, Col: %d\n", lin, col);

    gsl_rng * random = gsl_rng_alloc(gsl_rng_taus);


    printf("oi\n");
    
    
    return 0;
}
