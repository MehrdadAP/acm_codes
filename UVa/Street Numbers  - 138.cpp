#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

#define MAX 100000000

int main ()
{

	long long int sum,sq;
	int cnt=0;
	for (long long int i=2;i<MAX && cnt!=10;i++)
	{
		sum=(i*(i+1))/2;
		sq=sqrt((long double)sum);
		
		if (sq*sq==sum)
		{
			cnt++;
			printf("%10ld",sq);
			printf("%10d\n",i);
		}
	}
	//system("pause");
	return 0;

}