#include <iostream>
#define MAX 10100
using namespace std;

int sum[MAX];

int main ()
{
	int n,q,du,query;
	while (cin>>n)
	{
		for (int i=1;i<=n;i++)
			sum[i]=0;
		sum[0]=0;
		cin>>q;
		for (int i=1;i<=n;i++)
		{
			cin>>du;
			sum[i]=sum[i-1]+du;
		}
		for (int i=1;i<=q;i++)
		{
			cin>>query;
			int k;
			for (k=1;query>=sum[k];k++);
			printf("%d\n",k);

		}
	}
	return 0;

}