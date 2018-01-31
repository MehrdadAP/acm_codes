									/*ba yade oo */

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>



using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 0x7FFFFFFF
#define MAX1 600
#define MAX2 130000

typedef vector<int> vi;


int minDis(int a,int b)
{
	if (a>b)
		swap(a,b);

	int dis1=b-a;
	int dis2=(10-b)+(a);

	return min(dis1,dis2);
}


struct EDGE
{
	int u,v,w;
}edge[MAX2];


int N,edgeNum,p[MAX1];
string keys[MAX1];
void buildEdges()
{
	edgeNum=0;

	for (int i=1;i<=N;i++)
		for (int j=i+1;j<=N;j++)
		{
			int w=0;
			for (int k=0;k<4;k++)
				w+=minDis(keys[i][k]-'0',keys[j][k]-'0');
			edge[edgeNum].u=i;
			edge[edgeNum].v=j;
			edge[edgeNum++].w=w;
		}

}

int comp(const EDGE &a,const EDGE &b)
{
	return (a.w<b.w);
}

int root(int x)
{
	if (x==p[x])
		return x;
	p[x]=root(p[x]);
	return p[x];
}

int MST()
{
	int u,v,total,ednum;
	int i;


	//Handle the first step
	keys[0]="0000";
	int ed0=100;
	for (int i=1;i<=N;i++)
	{
		int tmp=0;
		for (int k=0;k<4;k++)
			tmp+=minDis(keys[0][k]-'0',keys[i][k]-'0');
		ed0=min(ed0,tmp);
	}
	total=ed0;
	for (int i=1;i<=N;i++)
		p[i]=i;

	sort(edge,edge+edgeNum,comp);
	for (int i=0,ednum=0;i<edgeNum;i++)
	{
		u=root(edge[i].u);
		v=root(edge[i].v);
		if (v==u) continue;
		p[v]=u;
		total+=edge[i].w;
		ednum++;
	}
	return total;
}


int main ()
{
	int tc;
	cin>>tc;
	while (tc--)
	{

		cin>>N;
		for (int i=1;i<=N;i++)
			cin>>keys[i];

		buildEdges();
		cout<<MST()<<endl;
	}
	return 0;
}