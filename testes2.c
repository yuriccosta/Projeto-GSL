#include <stdio.h>
#include <gsl/gsl_rng.h>

gsl_rng * r;  /* global generator */



int
main (void)
{
  const gsl_rng_type * T;
    extern const gsl_rng_type *gsl_rng_default;
    extern unsigned long int gsl_rng_default_seed;
  gsl_rng_env_setup();

  T = gsl_rng_default;
  r = gsl_rng_alloc (T);

  printf ("generator type: %s\n", gsl_rng_name (r));
  printf ("seed = %lu\n", gsl_rng_default_seed);
  printf ("first value = %lu\n", gsl_rng_get (r));

  gsl_rng_free (r);
  return 0;
}