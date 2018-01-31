									/*ba yade oo */
/*
AC Code

Problem : UVA - 459 - Graph Connectivity
Category : Disjonint Set - DFS
Author : Mehrdad AP

*/
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
#define MAX 100

int p[MAX],h[MAX];//p array for parents and h array for ranks

int findRoot(int x)
{
	if (p[x]==x)return x;

	int px=findRoot(p[x]);
	
	//path compression
	p[x]=px;
	return px;
}

void uni(int x,int y)
{
	if (h[x]<h[y])p[x]=y;
	else if (h[y]<h[x])p[y]=x;
	else 
	{
		p[x]=y;
		h[y]++;
	}
}

bool visited[MAX];

int main ()
{

	int tc,N,x,y,px,py;
	scanf("%d",&tc);
	char line[10];
	gets(line);
	gets(line);
	while (tc--)
	{
		gets(line);
		N=(int)(line[0]-'A');
		for (int i=0;i<=N;i++)
		{
			p[i]=i;
			h[i]=1;
		}


		while (gets(line))
		{
			if (line[0]=='\0')break;

			int x=findRoot(line[0]-'A');
			int y=findRoot(line[1]-'A');

			if (x!=y)uni(x,y);

		}
		int ans=0;
		
		//init visited to false
		memset(visited,false,sizeof(visited));

		for (int i=0;i<=N;i++)
		{
			int root=findRoot(i);
			if (visited[root]==false)
			{
				ans++;
				visited[root]=true;
			}
		}

		printf("%d\n",ans);
		if (tc!=0)puts("");

	}
	return 0;
}