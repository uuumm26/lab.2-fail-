#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

 int bubble_sort(long int* a, int N)
{
	int i, j, temp;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int insert_sort(long int* mas, int n)
{
	int tmp = 0;
	for (int i = 1; i < n; i++)
	{
		tmp = mas[i];
		for (int j = i - 1; j > 0; j--)
		{
			if (mas[j] > tmp)
			{
				mas[j + 1] = mas[j];
				mas[j] = tmp;
			}
		}
	}
}
int quick_sort(long int* a, int left, int right)
{
	int i, j;
	int temp, pivot;
	i = left;
	j = right;
	pivot = a[(left + (right - left) / 2)];
	do {
		while (a[i] < pivot) {
			i++;
		}
		while (a[j] > pivot) {
			j--;
		}
		if (i <= j) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
			i++;
			if (j > 0) {
				j--;
			}
		}
	} while (i <= j);

	if (i < right) {
		quick_sort(a, i, right);
	}
	if (j > left) {
		quick_sort(a, left, j);
	}
}
int main()
{
	setlocale(LC_ALL, "RUS");
	long int* arr;
	int i;
	int min, max, N;
	double start, stop, t;
	int alt, sort;
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	FILE* file = 0;
	fopen_s(&file, "D:\\REW.txt", "r");
	fscanf_s(file, "n = %d\n", &N);
	arr = malloc(N * sizeof(long int));
	for (i = 0; i < N; i++)
	{
		fscanf_s(file, "%d\n", &(arr[i]));
	}
	fclose(file);
	do
	{
		printf("1)Распечатать числа\n2)Выбор сортировки\n3)Свернуть\n4)Выход\n");
		do
		{
			scanf_s("%d", &alt);
			if (alt > 4 || alt <= 0)
			{
				printf("!!!ERROR!!!");
				return 0;
			}
		} while (alt > 4 || alt <= 0);
		if (alt == 1)
		{
			for (i = 0; i < N; i++)
			{
				printf("mas[%d] = %d\n", i, arr[i]);
			}
			printf(N);
			
		}
		if (alt == 2)
		{
			printf("\n1)Пузырьком\n2)Вставками\n3)Быстрая\n");
			do
			{
				scanf_s("%d", &sort);
				if (sort > 3 || sort <= 0)
				{
					printf("!!!EROR!!!");
					return 0;
				}
			} while (sort > 3 || sort <= 0);
			if (sort == 1)
			{
				printf("Соритровка завершена\n");
				start = clock();
				bubble_sort(arr, N - 1);
				stop = clock();
				t = ((double)(stop - start)) / CLK_TCK;
				printf("Время выполнения %f\n\n", t);
			}
			else if (sort == 2)
			{
				printf("Соритровка завершена\n");
				start = clock();
				insert_sort(arr, N);
				stop = clock();
				t = ((double)(stop - start)) / CLK_TCK;
				printf("Время выполнения %f\n\n", t);
			}
			else if (sort == 3)
			{
				printf("Соритровка завершена\n");
				start = clock();
				quick_sort(arr, 0, N - 1);
				stop = clock();
				t = ((double)(stop - start)) / CLK_TCK;
				printf("Время выполнения %f\n\n", t);
			}
		}
		if (alt == 3)
		{
			printf("Сортировка сброшена\n");
			system("cls");
			return main();
		}
		if (alt == 4)
		{
			printf("Програма завершена\n");
			return 0;
		}
	} while (alt == 1 || alt == 2 || alt == 3 || alt == 4);
	free(arr);
	return 0;
}