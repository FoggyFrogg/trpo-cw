#include <stdio.h>

int main() {
	printf("Игра 'Ним' (три кучки)\n");
	printf("\n*****\n");
	printf("\nТри кучки:\n");
	printf("%-10d %-10d %-10d\n", 10, 15, 11);

	int n, count;
	printf("Введите номер кучки и количество спичек:\n");
	scanf("%d %d", &n, &count);
	printf("Вы ввели: %d %d\n", n, count);

	printf("\n*****\n");
	printf("\nТри кучки:\n");
	printf("%-10d %-10d %-10d\n", 10, 15, 11);

	printf("Введите номер кучки и количество спичек:\n");
	scanf("%d %d", &n, &count);
	printf("Вы ввели: %d %d\n", n, count);
	return 0;
}

