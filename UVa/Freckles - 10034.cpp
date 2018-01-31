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
#define eps 1e-8
#define MAX 102
#define dis(x1,y1,x2,y2) (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)))
double node[MAX][2];

struct EDGE
{
	int u,v;
	double w;
	bool operator <(const EDGE &b)const
	{
		return (w<b.w);
	}

};
EDGE edge[MAX*MAX];

int k;
int parent[MAX];

void computeEdge(int n)
{
	k=0;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
		{
			edge[k].w=dis(node[i][0],node[i][1],node[j][0],node[j][1]);
			edge[k].u=i;
			edge[k].v=j;
			k++;
		}
}

int findParent(int x)
{
	if (parent[x]==x)
		return x;
	return (findParent(parent[x]));
}

double MSTKruskal(int n)
{
	int edgenum=0;
	double sum=0;
	for (int i=0;i<n;i++)
		parent[i]=i;

	sort(edge,edge+k);
	for (int i=0;i<k && edgenum<n-1;i++)
	{
		int u=findParent(edge[i].u);
		int v=findParent(edge[i].v);
		if (u==v) continue;
		parent[v]=u;
		sum+=edge[i].w;
		edgenum++;
	}
	return sum;
}
int main ()
{
	//cout<<eps<<endl;
	int tc,n;
	scanf("%d",&tc);
	//cin>>tc;
	while(tc--)
	{
		//scanf("%*s");
		scanf("%d",&n);
		//cin>>n;
		for (int i=0;i<n;i++)
			scanf("%lf %lf",&node[i][0],&node[i][1]);
			//cin>>node[i][0]>>node[i][1];
		computeEdge(n);
		printf("%.02lf\n",MSTKruskal(n));
		if (tc!=0)
			printf("\n");
	}
	return 0;

}
