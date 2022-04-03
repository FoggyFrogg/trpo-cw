#include <stdio.h>
#include <stdlib.h>

void step(int* array)
{
	printf("\n*****\n");
	printf("\nТри кучки:\n");
	printf("%-10d %-10d %-10d\n", array[0], array[1], array[2]);

	int n, count;
	printf("Введите номер кучки и количество спичек:\n");
	scanf("%d %d", &n, &count);
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
	
	step(array);
	step(array);
	step(array);
}

int main() {
	system("clear");
	printf("Игра 'Ним' (три кучки)\n");
	game();
	return 0;
}

