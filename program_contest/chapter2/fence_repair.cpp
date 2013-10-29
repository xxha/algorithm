#include <iostream>

using namespace std;

#define  MAX 	3;
int N = 4;
int Length[4] = {8, 5, 8, 5}; 

void swap(int a, int b)
{
	int i;

	i = a;
	a = b;
	b = i;
}

int main()
{
	long long ans = 0;
	int i;

	while (N > 1) {
		int mii1 = 0, mii2 = 1;

		if (Length[mii1] > Length[mii2])
			swap(mii1, mii2);

		for (i=2; i<N; i++) { /* move the minix 2 numbers to the array tail */
			if (Length[i] < Length[mii1]) {
				mii2 = mii1;
				mii1 = i;
			} else if (Length[i] < Length[mii2]) {
				mii2 = i;
			}
		}

		int t = Length[mii2] + Length[mii1];
		cout<<t<<endl;
		ans += t;

		if (mii1 == N - 1)
			swap(mii1, mii2);

		Length[mii1] = t;
		Length[mii2] = Length[N-1];

		N--;
	}
//	printf("%lld\n", ans);
	cout<<ans<<endl;
	return 0;
}

