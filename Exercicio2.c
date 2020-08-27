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

// _mm256_load_pd
// _mm256_store_pd

int main() {
    double a = [6.0, 6.0, 6.0, 6.0];
    double b = [2.0, 2.0, 2.0, 2.0];

    __m256d veca = _mm256_load_pd(veca);
    __m256d vecb = _mm256_load_pd(vecb);

    __m256d vecc = _mm256_add_pd(veca, vecb);

    double c = _mm256_store_pd(vecc);


	printf("%.2f %.2f %.2f %.2f\n",
		   c[0], c[1], c[2], c[3]);

    return 0;
}
