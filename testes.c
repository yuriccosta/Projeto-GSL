#include <stdio.h>
#include <gsl/gsl_rng.h>

int  main (void)
{   
    // Definindo o tipo do gerador
    const gsl_rng_type * T = gsl_rng_taus;
    // Alocando memória e passando a instância para o ponteiro r
    gsl_rng  * r = gsl_rng_alloc(T);

    


    void * state = gsl_rng_state(r);
    size_t n = gsl_rng_size(r);
    printf("%p\n", state);
    gsl_rng_free (r);

    return 0;
}
