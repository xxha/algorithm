/*
	Josephus Problem:

	n perple create a circle, count from 1 to m, the one who counts m will be kicked out.
	then count again from the next one, until left only the last one.
	output the number of last one.
*/

#include <stdio.h>

int josephus(int n, int m)
{
	int i, r = 0;

	for (i=2; i<n; i++)
		r = (r + m) % i;

	return r + 1;

}

int main(int argc, char **argv)
{
	int i = 2, j = 3;
	printf("josephus(2, 3) = %d\n", josephus(2, 3));

	i = 3;
	j = 3;
	printf("josephus(3, 3) = %d\n", josephus(3, 3));

	i = 4;
	j = 3;
	printf("josephus(4, 3) = %d\n", josephus(4, 3));

	i = 5;
	j = 3;
	printf("josephus(5, 3) = %d\n", josephus(5, 3));

	i = 40;
	j = 3;
	printf("josephus(40, 3) = %d\n", josephus(40, 3));
	return 0;
}


