/*
--------------------------------------------------------------------------------
      Trabalho Prático - Arquitetura de Computadores II - GCC123 - 2020/01
---------------------------- Programação em AVX/AVX2 ---------------------------
    Integrantes:
        Caio de Oliveira (10A - 201820267),
        Ismael Martins Silva (10A - 201820281),
        Layse Cristina Silva Garcia (10A - 201811177),
        Luiz Felipe Montuani e Silva (10A - 201920253).
--------------------------------------------------------------------------------
*/

// Bibliotecas importadas
#include <immintrin.h>
#include <stdio.h>

// Printa o vetor de double
void printDouble(__m256d vec) {
    double *d = (double*)&vec;

    printf(
        "%lf %lf %lf %lf\n",
        d[0], d[1], d[2], d[3]
    );
}

// Método que recebe os valores dos vetores de DOUBLE
__m256d pegaDouble() {
    double vec[4];

    for (int i = 0; i < 4; i++) {
        scanf("%lf", &vec[i]);
    }

    return _mm256_setr_pd(vec[0], vec[1], vec[2], vec[3]);
}

// Função Principal
int main() {
    printf("Digite 2 vetores double com 4 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);
    __m256d vec1 = pegaDouble();
    __m256d vec2 = pegaDouble();
    __m256d neg = _mm256_setr_pd(1.0, -1.0, 1.0, -1.0);

    /* Passo 1: Multiplica o vetor 1 e o vetor 2 */
    __m256d vec3 = _mm256_mul_pd(vec1, vec2);
    printf("Após o primeiro passo:\n");
    printDouble(vec3);

    /* Passo 2: Troca os elementos reais e imaginários do vetor 2 */
    vec2 = _mm256_permute_pd(vec2, 0x5);
    printf("Após o segundo passo:\n");
    printDouble(vec2);

    /* Passo 3: Nega os elementos imaginários do vetor 2 */
    vec2 = _mm256_mul_pd(vec2, neg);
    printf("Após o terceiro passo:\n");
    printDouble(vec2);

    /* Passo 4: Multiplica vetor 1 e o vetor 2 modificado */
    __m256d vec4 = _mm256_mul_pd(vec1, vec2);
    printf("Após o quarto passo:\n");
    printDouble(vec4);

    /* Subtrai horizontalmente os elementos dos vetores 3 e 4 */
    vec1 = _mm256_hsub_pd(vec3, vec4);

    /* Exibe os elementos do vetor resultado */
    printf("Resultado final:\n");
    printDouble(vec1);

    return 0;
}
