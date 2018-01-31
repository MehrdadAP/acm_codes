#include <iostream>
using namespace std;

int main ()
{
	int a,b;
	int tc;
	cin>>tc;
	int cnt,k;
	while (tc--)
	{
		cnt=0;
		cin>>a>>b;
		if (a!=b)
			cnt++;
		if (b-a>1)
			cnt++;
		b--;
		a++;
		k=2;
		while ((b-a)>0)
		{
			a+=k;
			k++;
			cnt++;
		}
		printf("%d\n",cnt);


	}

	return 0;
}