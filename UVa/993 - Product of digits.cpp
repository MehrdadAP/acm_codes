#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main ()
{
	
	int tc,n;
	int c[10];
	cin>>tc;
	while (tc--)
	{
		cin>>n;
		if (n==1)
		{
			printf("1\n");
			continue;
		}
		
		if (n==0)
		{
			printf("0\n");
			continue;
		}

		for(int i=0;i<10;i++)
		{
			c[i]=0;
		}
		for(int i=9;i>=2;i--)
			while(n%i==0)
			{
				n=n/i;
				c[i]++;
			}
		if (n!=1)
		{
			printf("-1\n");
			continue;
		}
		for(int i=2;i<=9;i++)
			for(int j=0;j<c[i];j++)
				cout<<i;
		cout<<endl;

	}

	return 0;

}

