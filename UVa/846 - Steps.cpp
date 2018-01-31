#include <iostream>
#include <stdio.h>

using namespace std;

int main ()
{
	int a,b,tc;
	cin>>tc;
	while (tc--)
	{
		cin>>a>>b;
		int cnt=0;
		if (a==b )
		{
			printf("0\n");
			continue;
		}
		int dec=1;//for decreasing
		while (1)
		{
			a=a+dec;
			cnt++;
			if (a>=b)
				break;
			
			b=b-dec;
			cnt++;  
			if (a>=b)				
				break;
			dec++;
		}
		printf("%d\n",cnt);

	}
	return 0;
}