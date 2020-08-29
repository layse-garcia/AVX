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

void printDouple(__m256d vec) {
    double *d = (double*)&vec;

    printf(
        "%lf %lf %lf %lf\n",
        d[0], d[1], d[2], d[3]
    );
}

__m256d pegaDouble() {
    double vec[4];

    for (int i = 0; i < 4; i++) {
        scanf("%lf", &vec[i]);
    }

    return _mm256_setr_pd(vec[0], vec[1], vec[2], vec[3]);
}

// Função Principal
int main() {
    __m256d vec1 = pegaDouble();
    __m256d vec2 = pegaDouble();
    __m256d neg = _mm256_setr_pd(1.0, -1.0, 1.0, -1.0);

    printDouple(neg);

    /* Step 1: Multiply vec1 and vec2 */
    __m256d vec3 = _mm256_mul_pd(vec1, vec2);

    printDouple(vec3);

    /* Step 2: Switch the real and imaginary elements of vec2 */
    vec2 = _mm256_permute_pd(vec2, 0x5);

    printDouple(vec2);

    /* Step 3: Negate the imaginary elements of vec2 */
    vec2 = _mm256_mul_pd(vec2, neg);

    printDouple(vec2);

    /* Step 4: Multiply vec1 and the modified vec2 */
    __m256d vec4 = _mm256_mul_pd(vec1, vec2);

    printDouple(vec4);

    /* Horizontally subtract the elements in vec3 and vec4 */
    vec1 = _mm256_hsub_pd(vec3, vec4);

    printDouple(vec1);

    /* Display the elements of the result vector */
    double* res = (double*)&vec1;
    printf("%lf %lf %lf %lf\n", res[0], res[1], res[2], res[3]);

    return 0;
}
