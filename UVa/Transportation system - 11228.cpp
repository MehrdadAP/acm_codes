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
#define MAX 1009
//#define distance(x1,y1,x2,y2) ((int)(sqrt(double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))))
#define distance(x1,y1,x2,y2) (((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))

struct POINT
{
	int x,y;
};

POINT point[MAX]; 
int	g[MAX][MAX],key[MAX];
bool visited[MAX];
bool rail[MAX][MAX];
int rails,roads,r;

void MSTPrim (int V)
{
	for (int i=0;i<V;i++)
	{
		visited[i]=false;
		key[i]=INF;
	}
	key[0]=0;
	int min,minInd;
	rails=roads=0;
	for (int k=0;k<V;k++)
	{
		min=INF;
		for (int i=0;i<V;i++)
			if (visited[i]==false && key[i]<min)
			{
				min=key[i];
				minInd=i;
			}

		visited[minInd]=true;
		if (key[minInd]>r)
			rails+=key[minInd];
		else if (key[minInd]!=0)
			roads+=key[minInd];
		for (int i=0;i<=V;i++)
		{
			if (!visited[i] && g[minInd][i]<key[i])
				key[i]=g[minInd][i];
		}

	}

}
int main ()
{
	int tc,V,v1,v2,states,dis;
	scanf("%d",&tc);
	while (tc--)
	{
		states=0;
		scanf("%d %d",&V,&r);
		for (int i=0;i<V;i++)
			scanf("%d %d",&point[i].x,&point[i].y);

		//make graph
		for (int i=0;i<V-1;i++)
			for (int j=i+1;j<V;j++)
				if ((g[i][j]=sqrt((double)distance(point[i].x,point[i].y,point[j].x,point[j].y)) )>r)
				{
					states++;
					rail[i][j]=true;
				}
				else
					rail[i][j]=false;

		MSTPrim(V);
		printf("%d %d %d\n",states,roads,rails);
	}

	return 0;

}