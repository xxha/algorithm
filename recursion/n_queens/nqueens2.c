#include<stdio.h>   
#define N 15   
  
int n;   
int sum = 0;   
int x[N];   
  
int place(int k)   
{   
	int i;   
	for(i=1;i<k;i++)   
		if(abs(k-i)==abs(x[k]-x[i]) || x[k] == x[i])   
		return 0;   
	return 1;   
}   
  
int queen()   
{   
	x[1] = 0;   
	int t=1;   
	while(t>0)   
	{   
		x[t]+=1;   
		while(x[t]<=n && !place(t))   
			x[t]++;   
		if(x[t]<=n) { 
			if(t == n)   
				sum++;   
			else  
				x[++t] = 0;
		} else  
			t--;   
	}   
	return sum;   
}   
  
int main()   
{   
	int t;   
	scanf("%d",&n);   
	t = queen();   
	printf("%d",t);   
	return 0;   
}  
