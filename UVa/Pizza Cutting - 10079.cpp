#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main ()
{
	int n;
	unsigned long long int ans1,ans2,ans3;
	unsigned long long int temp;
	//cout<<sizeof(temp);
	while (cin>>n,n>=0)
	{
		ans1=0;
		ans2=0;
		if (n%2==0)
		{
			ans1=n/2;
			ans2=n+1;
			ans3=ans1*ans2;
		}

		else
		{
			ans1=(n+1)/2;
			ans2=n;
			ans3=ans1*ans2;
		}
		cout<<ans3+1<<endl;
	}

	return 0;

}