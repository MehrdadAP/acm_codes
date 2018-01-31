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
#define MAX 200009
#define MAXV 1002

struct EDGE
{
	int u,v,w;
	bool operator <(const EDGE &b)const
	{
		return (w<b.w);
	}
};

EDGE edge[MAX];
int parent[MAX];

int findRoot(int x)
{
	if (parent[x]==x)
		return x;
	return (findRoot(parent[x]));
}
int MSTKruskal (int V,int E)
{
	
	for (int i=0;i<V;i++)
		parent[i]=i;

	sort(edge,edge+E);
	int edNum=0;
	int pu,pv,total;
	total=0;
	for (int i=0;edNum<V-1 && i<E ;i++)
	{
		pu=findRoot(edge[i].u);
		pv=findRoot(edge[i].v);
		if (pu==pv)
			continue;
		parent[pv]=pu;
		edNum++;
		total+=edge[i].w;
	}
	return total;
}
int main ()
{
	int V,E,v1,v2,w1,cnt,sumW;
	bool flag;
	while (scanf("%d %d",&V,&E),E!=0 || V!=0)
	{
		sumW=0;
		for (int i=0;i<E;i++)
		{
			scanf("%d %d %d",&v1,&v2,&w1);
			edge[i].u=v1;edge[i].v=v2;
			edge[i].w=w1;
			sumW+=w1;
		}
		printf("%d\n",sumW-MSTKruskal(V,E));
		
	}
	return 0;

}