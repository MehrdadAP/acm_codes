#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <queue>

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 1e8
#define MAX 10003
#define max3(a,b,c) (max(a,max(b,c)))

int a[MAX][MAX];
int w[MAX][MAX];
bool visited[MAX];
int ans;

int DFS(int v)
{
	int maximum,value;
	maximum=0;
	visited[v]=true;
	for (int i=1;i<=a[v][0];i++)
	{
		int curr=a[v][i];
		if (visited[curr]==false)
		{
			value=DFS(curr)+w[v][curr];
			ans=max(ans,value+maximum);
			if (value>maximum)
				maximum=value;
		}
	}
	return maximum;
}
int main ()
{
	int v1,v2,w1,n,E;
	char line[20];
	//while (gets(line))
	bool flag=true;
	while (flag)
	{
		if (gets(line)==NULL)
			break;
		n=0;
		if (strcmp(line,"")==0)
		{
			puts("0");
			continue;
		}
		for (int i=0;i<=MAX;i++)
		{
			visited[i]=false;
			a[i][0]=0;
		}
		while (1)
		{
			if (strcmp(line,"")==0) break;
			sscanf(line,"%d %d %d",&v1,&v2,&w1);
			a[v1][++a[v1][0]]=v2;
			a[v2][++a[v2][0]]=v1;
			w[v1][v2]=w1;
			w[v2][v1]=w1;
			n=max3(v1,v2,n);
			if (gets(line)==NULL)
			{
				flag=false;
				break;
			}
		}
		ans=0;
		DFS(1);
		printf("%d\n",ans);
	}

	return 0;

}
