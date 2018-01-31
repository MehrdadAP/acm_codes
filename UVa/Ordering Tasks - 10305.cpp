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
#define INF 0x7FFFFFFF
#define MAX 110

int g[MAX][MAX],list[MAX];
int endList;
bool visited[MAX];

void topol(int v)
{
	
	visited[v]=true;
	for (int i=1;i<=g[v][0];i++)
	{
		int curr=g[v][i];
		if (visited[curr]==false)
			topol(curr);
	}
	list[endList--]=v;

}
int main ()
{
	int V,E,v1,v2;
	while (scanf("%d %d",&V,&E),V!=0 || E!=0)
	{
		for (int i=1;i<=V;i++)
		{
			visited[i]=false;
			g[i][0]=0;
		}
		endList=V;
		for (int i=1;i<=E;i++)
		{
			scanf("%d %d",&v1,&v2);
			g[v1][++g[v1][0]]=v2;
		}
		for (int i=1;i<=V;i++)
			if (visited[i]==false)
				topol(i);
		
		for (int i=1;i<=V;i++)
			printf("%d ",list[i]);
		//printf("%d\n",list[V]);
		printf("\n");

	}


	return 0;

}