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

// Método que recebe os valores dos vetores de DOUBLE
void somaHorizontal() {
    __m256d vecA, vecB, vecC;

    double vecD[4];

    printf("Digite 2 vetores double com 4 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 4; i++) {
            scanf("%Le",&vecD[i]);
        }
        if (j == 0) {
            vecA = _mm256_setr_pd(vecD[0], vecD[1], vecD[2], vecD[3]);
        }
        else {
            vecB = _mm256_setr_pd(vecD[0], vecD[1], vecD[2], vecD[3]);
        }
    }

    vecC = _mm256_hadd_pd(vecA, vecB);

    double* f = (double*)&vecC;
    
    printf("Resultado: \n");
    printf("%f %f %f %f\n",
      f[0], f[1], f[2], f[3]);

    printf("\n");
}

// Função Principal
int main() {
    somaHorizontal();
    return 0;
}
