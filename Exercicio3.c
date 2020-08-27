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

int main() {
    __m256i vecA = _mm256_setr_epi8(98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98, 98);
    __m256i vecB = _mm256_setr_epi8(85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85, 85);

    __m256i vecC = _mm256_add_epi8(vecA, vecB);

    char *i = (char*)&vecC;
    printf("Sem saturacao: ");
    for (int x = 0; x < 32; x++) {
        printf(" %d ", i[x]);
    }
    printf("\n");


    vecA = _mm256_set_epi16(-18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000, -18000);
    vecB = _mm256_set_epi16(19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000, 19000);

    vecC = _mm256_subs_epi16(vecA, vecB);

    signed short int * j = (signed short int*)&vecC;
    printf("Com saturacao: ");
    for (int x = 0; x < 16; x++) {
        printf(" %d ", j[x]);
    }
    printf("\n");

    return 0;
}
