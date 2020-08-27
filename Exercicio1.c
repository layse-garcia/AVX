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

// _mm256_fmadd_

// 8 floats
void floats8() {
    __m256 vecA = _mm256_setr_ps(6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0);
    __m256 vecB = _mm256_setr_ps(2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0);
    __m256 vecC = _mm256_setr_ps(7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0);

    __m256 result = _mm256_fmadd_ps(vecA, vecB, vecC);

    float* f = (float*)&result;
    printf("%f %f %f %f %f %f %f %f\n",
      f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

// 4 doubles
void doubles4() {
    __m256d vecA = _mm256_setr_pd(6.0, 6.0, 6.0, 6.0);
    __m256d vecB = _mm256_setr_pd(2.0, 2.0, 2.0, 2.0);
    __m256d vecC = _mm256_setr_pd(7.0, 7.0, 7.0, 7.0);

    __m256d result = _mm256_fmadd_pd(vecA, vecB, vecC);

    double* f = (double*)&result;
    printf("%.2f %.2f %.2f %.2f\n",
      f[0], f[1], f[2], f[3]);
}

// 8 inteiros
void inteiros8() {
    __m256 vecA = _mm256_setr_ps(6, 6, 6, 6, 6, 6, 6, 6);
    __m256 vecB = _mm256_setr_ps(2, 2, 2, 2, 2, 2, 2, 2);
    __m256 vecC = _mm256_setr_ps(7, 7, 7, 7, 7, 7, 7, 7);

    __m256 result = _mm256_fmadd_ps(vecA, vecB, vecC);

    float* f = (float*)&result;
    printf("%.0f %.0f %.0f %.0f %.0f %.0f %.0f %.0f\n",
      f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

int main() {
    floats8();
    doubles4();
    inteiros8();

    return 0;
}
