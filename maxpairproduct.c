#include <stdio.h>

#define RANGE_ERROR 1
#define WAY_2 1
int main(void)
{
	long long maxPairProduct = 0; // holds the maximum pairwise product so far
	
	long n = 0;	// number of elements
	scanf("%ld", &n); // reads the `n` from stdin

	// range check for n: 0 <= n <= 20000
	if (n > 200000 || n < 0) {
		printf("%ld is out-of-range\n0 <= n <= 200000\n", n);
		return RANGE_ERROR;
	}

	long a[n]; // array for holding elements

	long i = 0; // main counter

	// read numbers into array
	for (i = 0; i < n; i++) {
		scanf("%ld", &a[i]);

		// range check for array element: 0 <= a <= 100000
		/*
		if (a[i] > 100000 || a[i] < 0) {
			printf("%ld is out-of-range\n0 <= a <= 100000\n", a[i]);
			return RANGE_ERROR;
		}
		*/
	}

// if WAY_1 defined compile this method.
#ifdef WAY_1

	/* Way One to solve the problem
	 * perform every available pair-wise multiplications for the array elements
	 * and determine the largest of them.
	 * This Way, there are (n(n -1)) / 2 multiplications to be performed.
	 * this will be exhaustive, when n is a big number
	 */

	long j = 0; // secondary counter
	long long product = 0; // temporarily holds the product of 2 elements
	// travese the array, find the maxPairProduct 
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			product = (long long) a[i] * (long long) a[j];

			if (product > maxPairProduct)
				maxPairProduct = product;
		}
	}

#endif

// if WAY_2 defined compile this method.
#ifdef WAY_2

	/* Way Two to solve the problem
	 * This way program will look for the two biggest numbers in the array.
	 * because It's assumed that maximum pair-wise product can be obtained by
	 * multiplying the the biggest and the second-biggest number.
	 * This way there is only one multiplication to be performed,
	 * i.e: firstMax * secondMax
	 * This should be faster than Way One
	 * And LONG INT j is not used in this way. only one counter needed.
	 */ 

	long firstMax = 0, // Maximum Integer in `a`
		 secondMax = 0; // Second maximum Integer in `a`

	// this travesal loop will find the 2 biggest numbers in the array
	for (i = 0; i < n; i++) {
		if (a[i] > firstMax) {
			secondMax = firstMax;
			firstMax = a[i];
		} else if (a[i] > secondMax)
			secondMax = a[i];
	}

	// maximum parwise product is the product of 2 largest numbers.
	maxPairProduct = (long long) firstMax *  secondMax;

#endif

	// print the maxPairProduct
	printf("%lli", maxPairProduct);

}
