/*
	reverse string by recursion
*/
#include <iostream>

using namespace std; 

void reverse(char *s)     //用递归算法
{
	if(*(++s) != '\0')  //recursion run inside first. so the output should last first.
		reverse(s);
	cout<<(*(s-1));
}

int main()
{
	char str[20];

	cout<<"please input a string:";
	cin>>str;
	reverse(str);
	cout<<endl;
	return 0;
}
