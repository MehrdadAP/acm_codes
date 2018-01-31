#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define MAX 21

double a[MAX][MAX][MAX];
int parent[MAX][MAX][MAX];
int path[MAX];
int s;

int floyd4(int n)
{
	for (s=1;s<n;s++)
		for (int k=0;k<n;k++)
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
				{
					if (a[s][i][j]<a[s-1][i][k]*a[0][k][j])
					{
						a[s][i][j]=a[s-1][i][k]*a[0][k][j];
						parent[s][i][j]=k;
					}
					if (i==j)
						if (a[s][i][j]>1.01)
							return i;
				}
	return -1;
}


void reset(int n)
{
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			for (int k=0;k<n;k++)
				a[i][j][k]=0;
	
}
int main ()
{
	int n;
	while (scanf("%d",&n)==1)
	{
		reset(n);
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				if (i==j)
					a[0][i][j]=1.0;
				else
					scanf("%lf",&a[0][i][j]);
				parent[0][i][j]=i;
			}
		int start=floyd4(n);
		int current=start;
		int pathLength=0;
		if (start==-1)
			puts("no arbitrage sequence exists");
		else
		{
			path[pathLength++]=start;
			for (int i=s;i>=0;i--)
			{
				current=parent[i][start][current];
				path[pathLength++]=current;
			}
			for (int i=pathLength-1;i>0;i--)
				printf("%d ",path[i]+1);
			printf("%d\n",path[0]+1);
		}
	}

	return 0;

}
