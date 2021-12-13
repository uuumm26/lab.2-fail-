#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "Rus");
	int i = 0, N = 0;
	long int min = 0, max = 0;
	long int* mas;
	FILE* fnumbers = 0;

	printf_s("Введите N: \n");
	scanf_s("%d", &N);
	printf_s("Введите Min: \n");
	scanf_s("%ld", &min);
	printf_s("Введите Max: \n");
	scanf_s("%ld", &max);
	if (N <= 0)
	{
		printf_s("Error N<= 0! \t");
		return 0;
	}
	mas = (long int*)malloc(N * sizeof(long int));
	if (mas == 0)
	{
		printf_s("Минимальное 1! \t");
		return 0;
	}

	if (min > max)
	{
		printf_s("Error min>max \t");
		return 0;
	}
	fnumbers = fopen("D:\\REW.txt", "w");
	for (int i = 0; i < N; i++)
	{
		mas[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;
		
	}
	fprintf(fnumbers,"n = %d\n", N);
	for (int i = 0; i < N; i++)
	{
		fprintf(fnumbers, "%ld\n", mas[i]);
	}
	fclose(fnumbers);
	free(mas);
	return 0;
}