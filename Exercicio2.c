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
    __attribute__ ((aligned (32))) double a[4], b[4], c[4];

    a[0] = 6.0;
    a[1] = 6.0;
    a[2] = 6.0;
    a[3] = 6.0;

    b[0] = 2.0;
    b[1] = 2.0;
    b[2] = 2.0;
    b[3] = 2.0;

    __m256d vecA = _mm256_load_pd(a);
    __m256d vecB = _mm256_load_pd(b);
    __m256d vecC = _mm256_add_pd(vecA, vecB);

    _mm256_store_pd(c, vecc);

	printf("%.2f %.2f %.2f %.2f\n",
		   c[0], c[1], c[2], c[3]);

    return 0;
}
