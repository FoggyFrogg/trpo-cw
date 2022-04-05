#include <libnim/checks.h>

#include <ctest.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(suite_checks, check_n)
{
	int n, exp;
	
	n = 0;
	exp = 1;
	ASSERT_EQUAL(exp, check_n(n));

	n = 1;
	exp = 1;
	ASSERT_EQUAL(exp, check_n(n));

	n = 2;
	exp = 1;
	ASSERT_EQUAL(exp, check_n(n));

	n = 3;
	exp = 0;
	ASSERT_EQUAL(exp, check_n(n));

	n = -1;
	exp = 0;
	ASSERT_EQUAL(exp, check_n(n));
}

CTEST(suite_checks, check_count)
{
	int count, exp;
	
	count = -1;
	exp = 0;
	ASSERT_EQUAL(exp, check_count(count));

	count = 0;
	exp = 0;
	ASSERT_EQUAL(exp, check_count(count));

	count = 10;
	exp = 1;
	ASSERT_EQUAL(exp, check_count(count));
}

CTEST(suite_checks, check_numbers)
{
	int n, count, exp;
	int arr[3] = { 1, 2, 3 };

	n = 0;
	count = 1;
	exp = 1;
	ASSERT_EQUAL(exp, check_numbers(n, count, arr));

	n = 0;
	count = 2;
	exp = 0;
	ASSERT_EQUAL(exp, check_numbers(n, count, arr));

	n = 1;
	count = 3;
	exp = 0;
	ASSERT_EQUAL(exp, check_numbers(n, count, arr));

	n = 2;
	count = 3;
	exp = 1;
	ASSERT_EQUAL(exp, check_numbers(n, count, arr));
}

CTEST(suite_checks, isWin)
{
	int arr[3] = { 0, 0, 0 };
	int exp = 1;
	ASSERT_EQUAL(exp, isWin(arr));

	int arr2[3] = { 0, 1, 0 };
	int exp2 = 0;
	ASSERT_EQUAL(exp2, isWin(arr2));
}
