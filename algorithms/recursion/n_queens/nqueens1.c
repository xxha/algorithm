#include<stdio.h>   
#define N 15   
  
int n; //queuen number   
int sum = 0; // solution number
int x[N]; // queen column
  
  
int place(int k) //try to put new queen k on x[k].
{   
	int i;   
	for(i=1;i<k;i++)
		if(abs(k-i)==abs(x[k]-x[i]) || x[k] == x[i])   
			return 0;   
	return 1;   
}   
  
  
int queen(int t)   
{  
	int j; 

	if(t>n && n>0) //when t > n, solution + 1
		sum++;   
	else  
		for(j=1;j<=n;j++) {   
			x[t] = j;   //queen t on j column
			if(place(t))  //if return true, place another queen.
				queen(t+1);	
		}   
	return sum;   
}   
  
int main()   
{   
	int t;   

	scanf("%d",&n);   
	t = queen(1);   
	if(n == 0)                    //if n = 0, solution = 0.
		t = 0;   
	printf("%d\n",t);   

	return 0;   
}  
