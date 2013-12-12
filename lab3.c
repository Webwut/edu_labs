#include <stdio.h>

/* Быдло функция для подсчета степени числа - pow*/
float doDegree(int number, int count)
{
	float S = 1;
	for(int i = 0; i < count; i++)
		S = S * number;
	return S;
}

/* Модуль - abs */
int doMod(int x)
{
	return x < 0 ? x*-1 : x;
}

/* Фунция для подсчета F */
float FindFuncElement(int x, int i)
{
	float F = ( (x+i) * (x+(i+1)) ) / doDegree(x, i+2);
	return F;
}

int main()
{
	float x;
	int i = 1;
	float CurrentF;

	printf("Enter x:");
	scanf("%f", &x);

	while(i < 30)
	{
		if(i == 1)
			CurrentF = FindFuncElement(x, i); // Получаем F1
		else
		{
			if(i % 2 == 0)
				CurrentF = CurrentF - FindFuncElement(x, i);
			else
				CurrentF = CurrentF + FindFuncElement(x, i);
		}
		printf("F%i = %f\n", i, CurrentF);
		//printf("OLOLO:%f\n", doDegree(x, i));
		i++;

		/* Если достигнуто макс. кол-во возможных операций */
		if(i == 5)
			printf("[-] Limit has been reached.\n");
	}

	return 0;
}