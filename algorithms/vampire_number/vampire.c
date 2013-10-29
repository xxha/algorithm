/*
	Vampire Number description:

	The number 1827 is an interesting number, because 1827=21*87, and all of the same digits appear on both sides of the ‘=’. 
	The number 136948 has the same property: 136948=146*938.
	Such numbers are called Vampire Numbers. 

	More precisely, a number v is a Vampire Number if it has a pair of factors, a and b, where a*b=v, and together, 
	a and b have exactly the same digits, in exactly the same quantities, as v. 
	None of the numbers v, a or b can have leading zeros. 

	The mathematical definition says that v should have an even number of digits and that a and b should have the same number of digits, 
	but for the purposes of this problem, we’ll relax that requirement, and allow a and b to have differing numbers of digits, 
	and v to have any number of digits. 

	Here are some more examples:
		126 = 6 * 21
		10251 = 51 * 201
		702189 = 9 * 78021
		29632 = 32 * 926

	Given a number X, find the smallest Vampire Number which is greater than or equal to X.

	Input:
	There will be several test cases in the input. 
	Each test case will consist of a single line containing a single integer X (10 ≤ X ≤ 1,000,000). 
	The input will end with a line with a single 0.	

	Output:
	For each test case, output a single integer on its own line, which is the smallest Vampire Number which is greater than or equal to X. 
	Output no extra spaces, and do not separate answers with blank lines.

	Input example:
	10
	126
	127
	5000
	0

	Output example:
	126
	126
	153
	6880
*/

#include <stdio.h>

int main()
{
	int num;
	int a[4];
	int i, j, k, z;
	int b[2];
	int outcome;

	printf("Vampire Number: \n");

	for (num=1000; num<10000; num++) {
		a[0] = num/1000;
		a[1] = (num % 1000) / 100;
		a[2] = (num % 100) /10;
		a[3] = num % 10;

		for (i=0; i<4; i++) 
			for (j=0;j<4; j++)
				for (k=0; k<4; k++) 
					for (z=0; z<4; z++){
						if (i != j && j != k && k != z && i != k && j != z && a[i]!=a[j] && a[j] != a[k] && a[k] !=a[z] && a[i] != a[k] && a[j] != a[z] && a[i] != a[z]) {
							b[0] = a[i] * 10 + a[j];
							b[1] = a[k] * 10 + a[z];
							outcome = b[0] * b[1];			
							if (outcome == num) {
								//printf("i = %d, j = %d, k = %d, z = %d\n", i, j, k, z);
								//printf("a[0] = %d, a[1] = %d, a[2] = %d, a[3] = %d\n", a[0], a[1], a[2], a[3]);
								printf("num = %d, b[0] = %d, b[1] = %d\n", num, b[0], b[1]);
							}
						}
					}		
	}
	return 0;
}



