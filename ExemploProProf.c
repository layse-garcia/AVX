/*
--------------------------------------------------------------------------------
      Trabalho Prático - Arquitetura de Computadores II - GCC123 - 2020/01
--------------------- Grupo 1 - Programação em AVX/AVX2 ------------------------
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
	__m256 veca = _mm256_setr_ps(6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0, 6.0);
	__m256 vecb = _mm256_setr_ps(2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0);
	__m256 vecc = _mm256_setr_ps(7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0, 7.0);

	__m256 result = _mm256_fmadd_ps(veca, vecb, vecc);

	float *f = (float *)&result;
	printf("%f %f %f %f %f %f %f %f\n",
		   f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

// 4 doubles
void doubles4() {
	__m256d veca = _mm256_setr_pd(6.0, 6.0, 6.0, 6.0);
	__m256d vecb = _mm256_setr_pd(2.0, 2.0, 2.0, 2.0);
	__m256d vecc = _mm256_setr_pd(7.0, 7.0, 7.0, 7.0);

	__m256d result = _mm256_fmadd_pd(veca, vecb, vecc);

	double *f = (double *)&result;
	printf("%.2f %.2f %.2f %.2f\n",
		   f[0], f[1], f[2], f[3]);
}

void imprime(__m256i a) {
	// __m256 b = (__m256)a;
	__m256 b = _mm256_castsi256_ps(a);

	float *f = (float *)&b;
	printf("> %f %f %f %f %f %f %f %f <\n",
		   f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);

	int *f2 = (int *)&a;
	printf("> %d %d %d %d %d %d %d %d <\n",
		   f2[0], f2[1], f2[2], f2[3], f2[4], f2[5], f2[6], f2[7]);
}

// 8 inteiros
void inteiros8() {
	__m256i veca = _mm256_set_epi32(6, 6, 6, 6, 6, 6, 6, 6);
	__m256i vecb = _mm256_set_epi32(2, 2, 2, 2, 2, 2, 2, 2);
	__m256i vecc = _mm256_set_epi32(7, 7, 7, 7, 7, 7, 7, 7);

	imprime(veca);
	imprime(vecb);
	imprime(vecc);

	__m256i result = (__m256i)_mm256_fmadd_ps((__m256)veca, (__m256)vecb, (__m256)vecc);

	int *f = (int *)&result;
	printf("%d %d %d %d %d %d %d %d\n",
		   f[0], f[1], f[2], f[3], f[4], f[5], f[6], f[7]);
}

int main() {
	floats8();
	doubles4();
	inteiros8();

	return 0;
}
