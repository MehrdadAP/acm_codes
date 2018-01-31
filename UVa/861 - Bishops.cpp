#include <iostream>
#include <string>
#include <algorithm>

#define MAX 8
using namespace std;

int n,k,ans;
int col[MAX];

bool promising (int x)
{
	for (int i=0;i<x;i++)
		if (x-i==abs(col[x]-col[i]))
			return false;

	return true;

}
void bishops(int x)
{
	if (promising(x))
	{
		if (x==k)
		{
			ans++;
			for (int i=0;i<n;i++)
			{
				for (int p=0;p<n;p++)
					if (col[p]
					printf("%d ",col[);
			}
			return ;
		}
		for (int i=0;i<n;i++)
		{
			col[x+1]=i;
			bishops(x+1);
		}

	}
}


int main ()
{
	
	while (cin>>n>>k,n!=0 && k!=0)
	{
		for (int i=0;i<n;i++)
			col[i]=0;
		ans=0;
		bishops(0);
		printf("%d\n",ans);

	}

	return 0;

}

