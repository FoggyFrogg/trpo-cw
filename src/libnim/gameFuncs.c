#include <libnim/checks.h>
#include <libnim/gameFuncs.h>

#include <stdio.h>
#include <stdlib.h>

int getNumbers(int* n, int* count, int* array)
{
    int again = 1;
    while (again) {
        char str[50];
        fgets(str, 50, stdin);
        checkExit(str);
        int code = sscanf(str, "%d %d", n, count);
        if (code == 1) {
            fgets(str, 50, stdin);
            checkExit(str);
            code = sscanf(str, "%d", count);
            if (code == 1)
                again = 0;
        } else if (code == 2)
            again = 0;
        if (again == 0) {
            *n = *n - 1;
            if (check_n(*n) == 0) {
                again = 1;
            } else {
                if (check_count(*count) == 0) {
                    again = 1;
                } else {
                    if (check_numbers(*n, *count, array) == 0) {
                        again = 1;
                    }
                }
            }
        }
        if (again)
            printf("Введите правильные значения! (например: '1 12')\n");
    }
    return 0;
}

void step(int* array)
{
    printf("\n______\n");
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
