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
void executaLoad_Soma_Store() {
    __attribute__ ((aligned (32))) double a[4], b[4], c[4];

    printf("Digite 2 vetores double com 4 elementos cada.\nCada elemento deve ser separado por um espaço em branco e cada vetor por uma quebra de linha.\n");
    fflush(stdout);

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < 4; i++) {
            if (j == 0) {
                scanf("%lf",&a[i]);
            }
            else {
                scanf("%lf",&b[i]);
            }
        }
    }

    __m256d vecA = _mm256_load_pd(a);
    __m256d vecB = _mm256_load_pd(b);
    __m256d vecC = _mm256_add_pd(vecA, vecB);

    _mm256_store_pd(c, vecC);

    printf("Resultado: \n");
    printf("%lf %lf %lf %lf\n",
           c[0], c[1], c[2], c[3]);
}

// Função Principal
int main() {
    executaLoad_Soma_Store();

    return 0;
}
