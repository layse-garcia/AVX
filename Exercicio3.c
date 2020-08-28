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

// Método que realiza a soma
void soma() {
    /* 32 elementos:
    98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98 98
    85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85 85
    */
    __m256i vecA, vecB, vecC;

    int vecD[32];

    printf("Digite 2 vetores de inteiros com 32 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 32; i++) {
            scanf("%d",&vecD[i]);
        }
        if (j == 0) {
            vecA = _mm256_setr_epi8(
                vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7],
                vecD[8], vecD[9], vecD[10], vecD[11], vecD[12], vecD[13], vecD[14], vecD[15],
                vecD[16], vecD[17], vecD[18], vecD[19], vecD[20], vecD[21], vecD[22], vecD[23],
                vecD[24], vecD[25], vecD[26], vecD[27], vecD[28], vecD[29], vecD[30], vecD[31]
            );
        }
        else {
            vecB = _mm256_setr_epi8(
                vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7],
                vecD[8], vecD[9], vecD[10], vecD[11], vecD[12], vecD[13], vecD[14], vecD[15],
                vecD[16], vecD[17], vecD[18], vecD[19], vecD[20], vecD[21], vecD[22], vecD[23],
                vecD[24], vecD[25], vecD[26], vecD[27], vecD[28], vecD[29], vecD[30], vecD[31]
            );
        }
    }
    vecC = _mm256_add_epi8(vecA, vecB);

    char *i = (char*)&vecC;
    printf("Sem saturacao: ");
    for (int x = 0; x < 32; x++) {
        printf("%d ", i[x]);
    }
    printf("\n");
}

// Método que realiza a subtração
void subtracao() {
    /* 16 elementos:
    -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000 -18000
    19000 19000 19000 19000 19000 19000 19000 19000 19000 19000 19000 19000 19000 19000 19000 19000
    */
    __m256i vecA, vecB, vecC;

    int vecD[16];

    printf("Digite 2 vetores de inteiros com 16 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 16; i++) {
            scanf("%d",&vecD[i]);
        }
        if (j == 0) {
            vecA = _mm256_set_epi16(
                vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7],
                vecD[8], vecD[9], vecD[10], vecD[11], vecD[12], vecD[13], vecD[14], vecD[15]
            );
        }
        else {
            vecB = _mm256_set_epi16(
                vecD[0], vecD[1], vecD[2], vecD[3], vecD[4], vecD[5], vecD[6], vecD[7],
                vecD[8], vecD[9], vecD[10], vecD[11], vecD[12], vecD[13], vecD[14], vecD[15]
            );
        }
    }
    vecC = _mm256_subs_epi16(vecA, vecB);

    signed short int * j = (signed short int*)&vecC;
    printf("Com saturacao: ");
    for (int x = 0; x < 16; x++) {
        printf("%d ", j[x]);
    }
    printf("\n");
}

// Função Principal
int main() {
    soma();
    subtracao();

    return 0;
}
