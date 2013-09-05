#include <stdio.h>


void reverse(int *array, int size)
{
	int i, tmp;
	for(i = 0; i < size/2; i++) {
		tmp = array[i];
		array[i] = array[size-i-1];
		array[size-i-1] = tmp;
	}
}

void main()
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int i, size;

	printf("old a[] = ");
	for(i=0; i<6; i++ )
		printf("%d ", a[i]);
	printf("\n");

	size = sizeof(a)/sizeof(int);
	printf("size = %d\n", size);

	reverse(a, size);

	printf("new a[] = ");
	for(i=0; i<6; i++ )
		printf("%d ", a[i]);
	printf("\n");
	
}
