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
#include <stdint.h>

//
int converteParaInteiro(int bits) {
    int saida, mult[bits], entrada[bits];

    saida = 0;
    scanf("%d", &entrada[0]);
    mult[0] = 1;

    for (int i = 1; i < bits; i++) {
        scanf("%d", &entrada[i]);
        mult[i] = mult[i - 1] * 2;
    }

    for (int i = 0; i < bits; i++) {
        saida = saida + entrada[i] * mult[bits - 1 - i];
    }

    return saida;
}
/*
__m256 func(__m256 vecA, const int imm8) {
    return _mm256_permute_ps(vecA, (0b)imm8);
}*/

// Método que recebe os valores dos vetores de FLOAT
void pegaFloat() {
    __m256 vecA, vecB;

    float vecD[8];

    printf("Digite 8 elementos.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int i = 0; i < 8; i++) {
        scanf("%f",&vecD[i]);
    }
    vecA = _mm256_setr_ps(vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7]);
    /*
    1 0 0 0 0 1 1 1 0 0 1 0 0 1 1 1

    ctrl - 10 00 01 11 | 00 10 01 11

    vec -- 1  2  3  4  | 5  6  7  8

    res -- 3  1  2  4  | 5  7  6  8
    */

    //int imm8 = converteParaInteiro(8);
    uint8_t imm8 = 0b01110100;
    // int imm8 = 0b01110100;
    //imm imm8 = 0b01110100;
    // _MM_SHUFFLE(2, 2, 2, 2)
    //vecB = func(vecA, imm8);
    vecB = _mm256_permute_ps(vecA, _MM_SHUFFLE(3, 1, 0, 2));

    printf("Resultado da operação de floats: \n");
    float* f = (float*)&vecB;
    printf("%f %f %f %f %f %f %f %f\n",
      f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);

    printf("\n");
}

// Função Principal
int main() {
    pegaFloat();

    return 0;
}
