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
    RESUMO: O código consiste em receber 3 entradas de vetores de acordo com o
            tipo exigido no enunciado. Como solicitado, os tipos FLOAT, DOUBLE e
            INTEIROS, possuem respectivamente 8, 4 e 8 posições.

*/

// Bibliotecas importadas
#include <immintrin.h>
#include <stdio.h>

// Método que recebe 3 vetores de FLOAT e realiza as operações
void floats8(__m256 vecA, __m256 vecB, __m256 vecC) {
    __m256 result = _mm256_fmadd_ps(vecA, vecB, vecC);

    printf("Resultado da operação de floats: \n");
    float* f = (float*)&result;
    printf("%f %f %f %f %f %f %f %f\n",
      f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

// Método que recebe 3 vetores de DOUBLE e realiza as operações
void doubles4(__m256d vecA, __m256d vecB, __m256d vecC) {
    __m256d result = _mm256_fmadd_pd(vecA, vecB, vecC);

    printf("Resultado da operação de double: \n");
    double* f = (double*)&result;
    printf("%lf %lf %lf %lf\n",
      f[0], f[1], f[2], f[3]);
}

// Método que recebe 3 vetores de INTEIROS e realiza as operações
void inteiros8(__m256i vecA, __m256i vecB, __m256i vecC) {
    __m256i result = _mm256_cvtps_epi32(_mm256_fmadd_ps(
        _mm256_cvtepi32_ps(vecA),
        _mm256_cvtepi32_ps(vecB),
        _mm256_cvtepi32_ps(vecC)
    ));

    printf("Resultado da operação de inteiros: \n");
    int* f = (int*)&result;
    printf("%d %d %d %d %d %d %d %d\n",
      f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

// Método que recebe os valores dos vetores de FLOAT
void pegaFloat() {
    __m256 vecA, vecB, vecC;

    float vecD[8];

    printf("Digite 3 vetores float com 8 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 8; i++) {
            scanf("%f",&vecD[i]);
        }
        if (j == 0) {
            vecA = _mm256_set_ps(vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7]);
        }
        else if (j == 1) {
            vecB = _mm256_set_ps(vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7]);
        }
        else {
            vecC = _mm256_set_ps(vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7]);
        }
    }
    floats8 (vecA, vecB, vecC);
    printf("\n");
}

// Método que recebe os valores dos vetores de DOUBLE
void pegaDouble() {
    __m256d vecA, vecB, vecC;

    double vecD[4];

    printf("Digite 3 vetores double com 4 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 4; i++) {
            scanf("%lf",&vecD[i]);
        }
        if (j == 0) {
            vecA = _mm256_set_pd(vecD[0], vecD[1], vecD[2], vecD[3]);
        }
        else if (j == 1) {
            vecB = _mm256_set_pd(vecD[0], vecD[1], vecD[2], vecD[3]);
        }
        else {
            vecC = _mm256_set_pd(vecD[0], vecD[1], vecD[2], vecD[3]);
        }
    }
    doubles4 (vecA, vecB, vecC);
    printf("\n");
}

// Método que recebe os valores dos vetores de INTEIROS
void pegaInt() {
    __m256i vecA, vecB, vecC;

    int vecD[8];

    printf("Digite 3 vetores de inteiros com 8 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < 8; i++) {
            scanf("%d",&vecD[i]);
        }
        if (j == 0) {
            vecA = _mm256_set_epi32(vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7]);
        }
        else if (j == 1) {
            vecB = _mm256_set_epi32(vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7]);
        }
        else {
            vecC = _mm256_set_epi32(vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7]);
        }
    }
    inteiros8 (vecA, vecB, vecC);
    printf("\n");
}

// Função Principal
int main() {
    pegaFloat();
    pegaDouble();
    pegaInt();

    return 0;
}
