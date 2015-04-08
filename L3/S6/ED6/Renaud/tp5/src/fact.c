/**
 * Library for computing factorials.
 */


#include <stdio.h>
#include <stdlib.h>
#include "fact.h"

/**
 * @brief Computes factorial of @p n recursively.
 *
 * Warning: does not check integer overflow.
 *
 * @param n the argument of factorial
 * @return  0 if @p n <= 0 and @p n! otherwise
 */
long
fact_rec(long n)
{
	if (n < 0)
		return 0;
	if (n == 1 || n == 0)
		return 1;
	long            f = fact_rec(n - 1);
	return n * f;
}

/**
 * @brief Computes factorial of @p n iteratively.
 *
 * Warning: does not check integer overflow.
 *
 * @param n the argument of factorial
 * @return  0 if @p n <= 0 and @p n! otherwise
 */
long
fact_it(long n)
{
	if (n < 0)
		return 0;
	long            f = 1;
	long            i = 0;
	for (i = 2; i <= n; i++)
		f = f * i;
	return f;
}
