#include <stdio.h>
#include <gsl/gsl_rng.h>
#define lin 10
#define col 10
#define n 50

void printMD(double m[][col]){
    printf("Matriz Double:\n");
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%lf ", m[i][j]);
        }
        printf("\n");
    }
}

void printMUL(unsigned long int m[][col]){
    printf("\nMatriz Unsigned Long Int:\n");
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%ld", m[i][j]);
            if (m[i][j] / 10 == 0){
                printf("  ");
            } else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main (void){
    // 1° gsl_rng_type é o tipo do nosso gerador
    const gsl_rng_type * tipo_gerador = gsl_rng_random_glibc2; 
    //const gsl_rng_type * tipo_gerador = gsl_rng_ranlxs2; // Um dos geradores mais fortes
    
    // gsl_rng descreve a instancia de um gerador criado pelo gsl_rng_type
    gsl_rng * gerador;

    // Alocando memória para a instância:
    gerador = gsl_rng_alloc(tipo_gerador);

    // Alimentando o gerador de números aleatórios
    gsl_rng_set(gerador, 30);

    // Esse tipo de gerador é o mesmo da biblioteca padrão C
    srand(30);
    printf("Rand padrão: %d\n", rand());
    printf("Rand Gsl: %ld\n\n", gsl_rng_get(gerador));

    // Matrizes que vão receber os números
    double Dmatriz[lin][col];
    unsigned long int Imatriz[lin][col];

    // 2° Gerando os números (funções)

    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            // Função que retorna um double [0,1)
            Dmatriz[i][j] = gsl_rng_uniform(gerador);
            // Função que retorna um inteiro entre a base e n - 1
            Imatriz[i][j] = gsl_rng_uniform_int(gerador, n);
        }
    }

    // Printando matriz Double
    printMD(Dmatriz);
    // Printando matriz Unsigned Long Int
    printMUL(Imatriz);
    
    // 3° Funções auxiliares

    //Tipo do gerador
    printf("\nTipo do gerador: %s\n", gsl_rng_name(gerador));

    //Maior valor que o gerador consegue retornar:
    printf("Maior valor: %ld\n", gsl_rng_max(gerador));

    //Menor valor que o gerador consegue retornar:
    printf("Menor valor : %ld\n", gsl_rng_min(gerador));

    // 4° Copiando o estado dos geradores

    gsl_rng * copia1_gerador = gsl_rng_alloc(tipo_gerador);
    gsl_rng_memcpy(copia1_gerador, gerador);

    gsl_rng * copia2_gerador = gsl_rng_clone(gerador);

    printf("\nGerador original: %lf\n", gsl_rng_uniform(gerador));
    printf("Cópia 1 do gerador: %lf\n", gsl_rng_uniform(copia1_gerador));
    
    // Salvando cópia 2 em um arquivo
    FILE * copy = fopen("output/copiagerador.bin", "wb");
    if(copy == NULL){
        printf("Não foi possível abrir o arquivo");
        return 0;
    }

    // Escrevendo o estado do gerador no arquivo e liberando a copia 2
    gsl_rng_fwrite(copy, copia2_gerador);
    gsl_rng_free(copia2_gerador);

    // Fechando arquivo
    if(fclose(copy)){
        printf("Ocorreu um erro na hora de fechar o arquivo");
        return 0;
    }

    // Lendo e salvando o estado do gerador do arquivo no gerador original
    copy = fopen("output/copiagerador.bin", "rb");
    gsl_rng_fread(copy, gerador);

    printf("\nGerador original: %lf\n", gsl_rng_uniform(gerador));
    printf("Cópia 1 do gerador (O gerador original teria o mesmo valor): %lf\n", gsl_rng_uniform(copia1_gerador));

    // Fechando arquivo    
    if(fclose(copy)){
        printf("Ocorreu um erro na hora de fechar o arquivo");
        return 0;
    }

    // Liberando memória dos geradores
    gsl_rng_free(gerador);
    gsl_rng_free(copia1_gerador);

    return 0;
}