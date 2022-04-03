#include <stdio.h>
#include <stdlib.h>

int check_n(int n)
{
	if (n >= 0 && n <= 2)
		return 1;
	return 0;
}

int check_count(int count)
{
	if (count >= 1)
		return 1;
	return 0;
}

int check_numbers(int n, int count, int* array)
{
	if (array[n] >= count)
		return 1;
	return 0;
}

int getNumbers(int* n, int* count, int* array)
{
	int again = 1;
	while (again)
	{
		char str[50];
		fgets(str, 50, stdin);
		if (str[0] == 'q') exit(1);
		int code = sscanf(str, "%d %d", n, count);
		if (code == 1) {
			fgets(str, 50, stdin);
			if (str[0] == 'q') exit(1);
			code = sscanf(str, "%d", count);
			if (code == 1)
				again = 0;
		}
		else if (code == 2)
			again = 0;
		if (again == 0) {
			if (check_n(*n) == 0) {
				again = 1;
			} else {
				if (check_count(*count) == 0)
				{
					again = 1;
				} else {
					if (check_numbers(*n, *count, array) == 0)
					{
						again = 1;
					}
				}
			}
		}
		if (again)
			printf("Введите правильные значения! (например: 1 12)\n");
	}
	return 0;
}

void step(int* array)
{
	printf("\n*****\n");
	printf("\nТри кучки:\n");
	printf("%-10d %-10d %-10d\n", array[0], array[1], array[2]);

	int n, count;
	printf("Введите номер кучки и количество спичек:\n");
	getNumbers(&n, &count, array);
	printf("Вы ввели: %d %d\n", n, count);

	array[n] -= count;
	printf("\nРезультат:\n");
	printf("%-10d %-10d %-10d\n", array[0], array[1], array[2]);
}

void game()
{
	int array[3];
	array[0] = 10;
	array[1] = 15;
	array[2] = 11;
	
	while (array[0] || array[1] || array[2])
		step(array);
}

int main() {
	system("clear");
	printf("Игра 'Ним' (три кучки)\n");
	printf("Нажмите q чтобы выйти.\n");
	game();
	return 0;
}

