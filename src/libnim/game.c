#include <libnim/game.h>
#include <libnim/gameFuncs.h>

#include <stdlib.h>
#include <time.h>

void game()
{
    srand(time(0));
    int array[3];
    array[0] = rand() % 10 + 10;
    array[1] = rand() % 10 + 10;
    array[2] = rand() % 10 + 10;

    while (array[0] || array[1] || array[2])
        step(array);
}
