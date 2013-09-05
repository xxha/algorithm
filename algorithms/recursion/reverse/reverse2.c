#include <stdio.h>

void reverse(char a[], int s, int sc);

void reverse(char a[], int s, int sc)
{
	if((sc - s) < (s -1))	{
		a[sc - s] ^= a[s - 1];
		a[s - 1]  ^= a[sc - s];
		a[sc -s]  ^= a [s - 1];
		reverse(a, s - 1, sc);
	}
}

void main()
{
	int size;
	char a[] = "abcdefghijklmn";

	printf("old a[] = %s\n", a);

	size = sizeof(a)/sizeof(char) - 1;
	printf("size = %d\n", size);


	reverse(a, size, size);

	printf("new a[] = %s\n", a);
}
