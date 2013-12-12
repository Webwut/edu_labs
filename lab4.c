#include <stdio.h>

/*
	i - строки
	j - столбцы
*/

/*
void ShowArray(int a[][7], int size1); // Заголовок нашей функции
*/

int main()
{
	int arr1[7][7], i, j;

	/* Вводим значения в массив / выводим сам массив */
	printf("Original array:\n\n");
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 7; j++)
		{
			arr1[i][j] = (i+1) + (j+1) * ( (i-1) * j); // Впадлу руками сейчас вводить, пускай пока будет так
			printf("%4i", arr1[i][j]); // Вывод элементов массива в виде матрицы
		}
		printf("\n"); // Переход на след. строку после заполнения каждой строки
	}

	/* Изменение элементов массива */
	for(i = 0; i < 7; i++)
	{
		for(j = 0; j < 7; j++)
		{
			/*	
				Меняем только элементы, начиная с 3его столбца, т.к. в нашей формуле идет обращение 
				к элементу j-2, которого не существует до третьего столбца 
			*/
			if(j >= 2)
				arr1[i][j] = arr1[i][j-1] + arr1[i][j-2];
		}
	}

	/* Вывод нового массива */
	printf("\n\nThe modified array:\n\n");
	for (i = 0; i < 7; i++) 
	{
		for (j = 0; j < 7; j++) 
			printf("%4i", arr1[i][j]);
		printf("\n");
	}

	return 0;
}

/*
Быдло-функция для вывода массива
void ShowArray(int a[][7], int size1) 
{
	for (int i = 0; i < size1; i++) 
	{
		for (int j = 0; j < 7; j++) 
			printf("%4i", a[i][j]);
		printf("\n");
	}
}
*/

