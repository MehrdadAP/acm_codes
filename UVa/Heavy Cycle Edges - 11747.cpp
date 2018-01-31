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
#define MAX 2600
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
int parent[MAXV];
bool visited[MAX];
int list[MAX];

int findRoot(int x)
{
	if (parent[x]==x)
		return x;
	return (findRoot(parent[x]));
}
void MSTKruskal (int V,int E)
{
	
	for (int i=0;i<E;i++)
		visited[i]=false;
	for (int i=0;i<V;i++)
		parent[i]=i;

	sort(edge,edge+E);
	int edNum=0;
	int pu,pv;
	for (int i=0;edNum<V-1 && i<E ;i++)
	{
		pu=findRoot(edge[i].u);
		pv=findRoot(edge[i].v);
		if (pu==pv)
			continue;
		parent[pv]=pu;
		edNum++;
		visited[i]=true;
	}
}
int main ()
{
	int V,E,v1,v2,w1,cnt;
	bool flag;
	while (scanf("%d %d",&V,&E),E!=0 || V!=0)
	{
		for (int i=0;i<E;i++)
		{
			scanf("%d %d %d",&v1,&v2,&w1);
			edge[i].u=v1;edge[i].v=v2;
			edge[i].w=w1;
		}
		MSTKruskal(V,E);
		cnt=0;
		for (int i=0;i<E;i++)
			if (visited[i]==false)
				list[cnt++]=edge[i].w;
		if (cnt==0)
		{
			puts("forest");
			continue;
		}

		sort(list,list+cnt);
		for (int i=0;i<cnt-1;i++)
			printf("%d ",list[i]);
		printf("%d\n",list[cnt-1]);
	}
	return 0;

}