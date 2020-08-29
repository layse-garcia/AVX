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

void printFloat(__m256 vec) {
    float *f = (float*)&vec;

    printf(
        "%f %f %f %f %f %f %f %f\n",
        f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]
    );
}

void shuffle() {
    __m256 vecA = _mm256_setr_ps(0.0, 2.0, 4.0, 6.0, 8.0, 10.0, 12.0, 14.0);
    __m256 vecB = _mm256_setr_ps(1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0, 15.0);

    __m256 vecC = _mm256_shuffle_ps(vecA, vecB, _MM_SHUFFLE(1, 3, 1, 0));

    printFloat(vecA);
    
    printFloat(vecB);

    printFloat(vecC);
}

// Função Principal
int main() {
    shuffle();

    return 0;
}
