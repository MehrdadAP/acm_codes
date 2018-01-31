#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main ()
{
	int a,b,tc;
	cin>>tc;
	while (tc--)
	{
		cin>>a>>b;
		double d=b-a+1;
		int n=(int)(sqrt(d));
		//cout<<n<<"  ";
		//if (n*(n+1)==d || n*(n+1)<d+n)
		if(!(d>n))
			printf("%d\n",2*n);
		else
			printf("%d\n",2*n-1);
	}
	return 0;
}