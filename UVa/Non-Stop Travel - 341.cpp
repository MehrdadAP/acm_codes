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
#define INF 1e8
#define MAX 12

int a[MAX][MAX],parent[MAX],dis[MAX];

void relax(int u,int v)
{
	if (dis[u]+a[u][v]<dis[v])
	{
		dis[v]=dis[u]+a[u][v];
		parent[v]=u;
	}
}

void Dijkstra(int n,int start)
{
	bool visited[MAX];
	for (int i=0;i<=n;i++)
	{
		dis[i]=INF;
		visited[i]=false;
		
	}
	dis[start]=0;
	parent[start]=-1;
	bool flag=true;
	int min,minIndex;
	for (int i=1;i<=n;i++)
	{
		flag=false;
		min=INF;
		for (int j=1;j<=n;j++)
		{
			if (!visited[j] && dis[j]<min)
			{
				min=dis[j];
				minIndex=j;
				flag=true;
			}
		}

		if (!flag) break;
		visited[minIndex]=true;

		for (int j=1;j<=n;j++)
		{
			if (a[minIndex][j]!=INF && visited[j]==false)
				relax(minIndex,j);
		}
	}
}

void printPath(int i)
{
	if (parent[i]==-1)
	{
		printf("%d",i);
		return ;
	}
	printPath(parent[i]);
	printf(" %d",i);

}
int main ()
{
	int n,e,v1,start,end;
	int tc=0;
	while (cin>>n,n!=0)
	{
		tc++;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				a[i][j]=INF;
		for (int i=1;i<=n;i++)
		{
			//Adjacancy Matrix
			cin>>e;
			for (int j=1;j<=e;j++)
			{
				cin>>v1;
				cin>>a[i][v1];
			}
		}

		cin>>start>>end;
		Dijkstra(n,start);
		printf("Case %d: Path = ",tc);
		printPath(end);
		printf("; %d second delay\n",dis[end]);
	}

	return 0;

}