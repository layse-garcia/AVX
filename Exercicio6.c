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

// Printa o vetor de float
void printFloat(float f[]) {
    printf(
        "%f %f %f %f %f %f %f %f\n",
        f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]
    );
}

// Printa o vetor de __m256
void print_m256(__m256 vec) {
    float *f = (float*)&vec;
    printFloat(f);
}

// Método que recebe os valores dos vetores de FLOAT
void pegaFloat() {
    __m256 vecA, vecB, vecC;

    float vec[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    printFloat(vec);

    vecA = _mm256_setr_ps(vec[0], vec[1], vec[2], vec[3], vec[4], vec[5], vec[6], vec[7]);
    vecB = _mm256_setr_ps(vec[0], vec[1], vec[2], vec[3], vec[4], vec[5], vec[6], vec[7]);

    /*
    1 0 0 0 0 1 1 1 0 0 1 0 0 1 1 1

    ctrl - 10 00 01 11 | 00 10 01 01

    vec -- 1  2  3  4  | 5  6  7  8

    res -- 3  1  2  4  | 5  7  6  6
    */
    
    printf("Controle para a primeira metade do vetor: 10 00 01 11\n");
    printf("Controle para a segunda metade do vetor: 00 10 01 01\n");

    vecA = _mm256_permute_ps(vecA, _MM_SHUFFLE(3, 1, 0, 2));
    vecB = _mm256_permute_ps(vecB, _MM_SHUFFLE(1, 1, 2, 0));

    float *a = (float*)&vecA;
    float *b = (float*)&vecB;

    vecC = _mm256_setr_ps(a[0], a[1], a[2], a[3], b[4], b[5], b[6], b[7]);

    printf("Resultado da operação de permutação: \n");
    print_m256(vecC);

    printf("\n");
}

// Função Principal
int main() {
    pegaFloat();

    return 0;
}
