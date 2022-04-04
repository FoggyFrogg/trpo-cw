#include <libnim/game.h>
#include <libnim/gameFuncs.h>

void game()
{
    int array[3];
    array[0] = 10;
    array[1] = 15;
    array[2] = 11;

    while (array[0] || array[1] || array[2])
        step(array);
}
