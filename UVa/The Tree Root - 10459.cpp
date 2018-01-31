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
#define INF 10000
#define MAX 5003

int g[MAX][MAX],height[MAX],minList[MAX],maxList[MAX];
int maxi,mini;

bool visited[MAX];

int DFS(int v)
{
	visited[v]=true;
	int ret=0;
	for (int i=1;i<=g[v][0];i++)
	{
		int curr=g[v][i];
		if (visited[curr]==false)
		{
			int temp=DFS(curr)+1;
			if (temp>ret)
				ret=temp;
		}

	}
	return ret;
}


int main ()
{
	int V,v1;
	while (scanf("%d",&V)!=EOF)
	{
		//Read Iput
		for (int i=1;i<=V;i++)
		{
			scanf("%d",&g[i][0]);
			for (int k=1;k<=g[i][0];k++)
				scanf("%d",&g[i][k]);
		}
		mini=INF+10;
		maxi=0;
		//Run DFS for each vertice O(V^2)
		
		for (int i=1;i<=V;i++)
		{
			for (int i=1;i<=V;i++)
				visited[i]=false;
			height[i]=DFS(i);
			if (height[i]>maxi)
				maxi=height[i];
			if (height[i]<mini)
				mini=height[i];
		}
		DFS(1);
		int que;
		//while (cin>>que)
			//printf("%d\n",height[que]);
		//seperate worst & best
		int Nmin=0;
		int Nmax=0;
		for (int i=1;i<=V;i++)
		{
			if (height[i]==mini)
				minList[Nmin++]=i;
			if (height[i]==maxi)
				maxList[Nmax++]=i;
		}

		//Printing Separatly
		printf("Best Roots  : ");
		for (int i=0;i<Nmin-1;i++)
			printf("%d ",minList[i]);
		printf("%d\n",minList[Nmin-1]);

		printf("Worst Roots : ");
		for (int i=0;i<Nmax-1;i++)
			printf("%d ",maxList[i]);
		printf("%d\n",maxList[Nmax-1]);
	}
	return 0;
}
