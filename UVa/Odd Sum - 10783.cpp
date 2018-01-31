#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main ()
{
	int tc,a,b;
	cin>>tc;
	int TC=tc;
	while (tc--)
	{
		cin>>a>>b;
		int ans=0;
		for (int i=a;i<=b;i++)
			if (i%2!=0)
				ans+=i;
		printf("Case %d: %d\n",TC-tc,ans);

	}

	return 0;

}

