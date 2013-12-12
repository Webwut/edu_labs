#include <windows.h>
#include <stdio.h>

int main()
{
	float x, y, a1, a2, b, bufA;
	int bVar = 0;
	char workType = '!';
	/*
		x, y - координаты точки
		a1, a2 - параболы
		b - прямая для ограничения области
		bufA - переменная-буффер, чтобы поменять местами прямые
		workType - символ для задачи разных режимов работы: a - смена области, p - смена информации о точках, n - вся информация
		bVar - переменная для проверки результата ф-ции scanf
	*/
	do
	{
		system("cls");

		/* Вводим данные об области */
		if ((workType == 'A') || (workType == 'a') || (workType == 'N') || (workType == 'n') || (workType == '!'))
		{
			printf("[!] Enter information about area.\n");
			while (bVar != 1)
			{
				printf("Enter a1:"); // Парабола 1
				fflush(stdin);
				bVar = scanf("%f", &a1);
			}
			bVar = 0;

			while (bVar != 1)
			{
				printf("Enter a2:"); // Парабола 2
				fflush(stdin);
				bVar = scanf("%f", &a2);
			}
			bVar = 0;

			while (bVar != 1)
			{
				printf("Enter b:");
				fflush(stdin);
				bVar = scanf("%f", &b);
			}
			bVar = 0;

			/* Меняем параболы местами если a2 > a1 */
			if (a2 > a1)
			{
				bufA = a1;
				a1 = a2;
				a2 = bufA;
			}
		}
		/* Если прямая выше нижней параболы */
		if (b > a2)
		{
			/* Вводим данные о точке */
			if ((workType == 'P') || (workType == 'p') || (workType == 'N') || (workType == 'n') || (workType == '!'))
			{
				printf("\n[!] Enter information about points.\n");

				/* ......Y...... */
				while (bVar != 1)
				{
					printf("Enter y:");
					fflush(stdin);
					bVar = scanf("%f", &y);
				}

				if (y > a2)
				{
					/* ......X...... */
					bVar = 0;
					while (bVar != 1)
					{
						printf("Enter x:");
						fflush(stdin);
						bVar = scanf("%f", &x);
					}
					/* Проверка принадлежности точек к нашей области */
					if ( (y >= x*x + a2) && (y <= x*x + a1) && (y <= b) )
						printf("[+] Points belong to the area");
					else
						printf("[Error] The points doesn't belong to the area.");
				}
				else
				{
					printf("[Error] Y - This is point doesn't belong to the area.\n");
				}
			}
			bVar = 0;

			/* Менюшка */
		}
		else
			printf("[Error] The line below the parabola.");
		puts("\n\n\n.......Menu.......\n[A] - Change information about Area\n[P] - Change information about Points\n[N] - Change information about point and area");
		printf("Your choice: ");
		fflush(stdin);
		scanf("%c", &workType);
	} while ((workType == 'A') || (workType == 'a') || (workType == 'P') || (workType == 'p') || (workType == 'N') || (workType == 'n'));

	return 0;
}