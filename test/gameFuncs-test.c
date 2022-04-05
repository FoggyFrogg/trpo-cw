#include <libnim/gameFuncs.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(suite_gameFuncs, stepComputer)
{
    int arr[3] = {0, 1, 0};

    stepComputer(arr);
    ASSERT_EQUAL(0, arr[1]);
}
