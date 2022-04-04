#include <libnim/checks.h>

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

void checkExit(char* str)
{
    if (str[0] == 'q') exit(1);
}
