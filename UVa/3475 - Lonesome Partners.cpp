#include <iostream>
#define MAX 600
using namespace std;

int dis(int x1,int y1,int x2,int y2)
{
	return (((x1-x2)*(x1-x2)))+((y1-y2)*(y1-y2));
}
int a[MAX][2];
int main ()
{
	int n;
	
	while (cin>>n)
	{
		int max=0;
		for (int i=0;i<n;i++)
			cin>>a[i][0]>>a[i][1];
		int ii,jj;
		for (int i=0;i<n-1;i++)
			for (int j=i+1;j<n;j++)
			{
					int distance=dis(a[i][0],a[i][1],a[j][0],a[j][1]);
					if (distance>max)
					{
						ii=i+1;
						jj=j+1;
						max=distance;
					}
			}

		printf("%d %d\n",ii,jj);
	}

	return 0;
}