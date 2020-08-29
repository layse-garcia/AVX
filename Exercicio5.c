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

// Método que recebe 3 vetores de DOUBLE e realiza as operações
void doubles4(__m256d vecA, __m256d vecB, __m256d vecC) {
    __m256d result = _mm256_fmadd_pd(vecA, vecB, vecC);

    printf("Resultado da operação de double: \n");
    double* f = (double*)&result;
    printf("%lf %lf %lf %lf\n",
      f[0], f[1], f[2], f[3]);
}

// Método que recebe os valores dos vetores de DOUBLE
void pegaDouble() {
    __attribute__ ((aligned (32))) double a[4], b[4], c[4];

    printf("Digite 3 vetores double com 4 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 4; i++) {
            if (j == 0) {
                scanf("%lf",&a[i]);
            }
            else if (j == 1) {
                scanf("%lf",&b[i]);
            }
            else {
                scanf("%lf",&c[i]);
            }
        }
    }

    __m256d vecA = _mm256_load_pd(a);
    __m256d vecB = _mm256_load_pd(b);
    __m256d vecC = _mm256_load_pd(c);

    doubles4(vecA, vecB, vecC);
}

// Função Principal
int main() {
    pegaDouble();

    return 0;
}
