#include <stdio.h>

int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n * factorial(n - 1);
}

int main()
{
	int n;

	scanf("%d", &n);

	printf("factorial of %d = %d\n", n, factorial(n));
}
