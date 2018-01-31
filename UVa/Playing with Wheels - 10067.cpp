//Playing with Wheels
//BFS
//it can be solved By Dijkstra ,i think
//O(n)
//Impl By Manual Queue


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
#define MAX 10007
#define MAXD 11

#define push(x) q[last++]=x
#define pop(x) x=q[first++]


struct node
{
	short int x1,x2,x3,x4;
	int dis;
	bool operator==(const node b)
	{
		return (x1==b.x1 && x2==b.x2 && x3==b.x3 && x4==b.x4);
	}
};
node q[MAX];
bool isForbidden[MAX];
int first,last;

bool visited[MAXD][MAXD][MAXD][MAXD];
int n;

/*
bool isForbidden(node a)
{
	for (int i=0;i<n;i++)
		if (forbid[i]==a)
			return true;
	return false;
}
*/
int toInt(node temp)
{
	return (temp.x1*1000+temp.x2*100+temp.x3*10+temp.x4);
}
int BFS(node init,node des)
{
	for (int i=0;i<MAXD;i++)
		for (int j=0;j<MAXD;j++)
			for (int k=0;k<MAXD;k++)
				for (int s=0;s<MAXD;s++)
					visited[i][j][k][s]=false;

	first=last=0;
	visited[init.x1][init.x2][init.x3][init.x4]=true;
	init.dis=0;
	push(init);
	node fr;
	short int x1,x2,x3,x4;
	node temp;
	while (first<last)
	{
		pop(fr);
		if (fr==des)
			return fr.dis;
		x1=fr.x1;x2=fr.x2;
		x3=fr.x3;x4=fr.x4;

		temp=fr;
		for (int i=-1;i<=1;i++)
		{
			x1=(fr.x1+i+10)%10;
			temp.x1=x1;
			if (visited[temp.x1][temp.x2][temp.x3][temp.x4]==false && isForbidden[toInt(temp)]==false)
			{
				temp.dis=fr.dis+1;
				push(temp);
				visited[temp.x1][temp.x2][temp.x3][temp.x4]=true;
			}
		}

		temp=fr;
		for (int i=-1;i<=1;i++)
		{
			x2=(fr.x2+i+10)%10;
			temp.x2=x2;
			if (visited[temp.x1][temp.x2][temp.x3][temp.x4]==false && isForbidden[toInt(temp)]==false)
			{
				temp.dis=fr.dis+1;
				push(temp);
				visited[temp.x1][temp.x2][temp.x3][temp.x4]=true;
			}
		}

		temp=fr;
		for (int i=-1;i<=1;i++)
		{
			x3=(fr.x3+i+10)%10;
			temp.x3=x3;
			if (visited[temp.x1][temp.x2][temp.x3][temp.x4]==false && isForbidden[toInt(temp)]==false)
			{
				temp.dis=fr.dis+1;
				push(temp);
				visited[temp.x1][temp.x2][temp.x3][temp.x4]=true;
			}
		}

		temp=fr;
		for (int i=-1;i<=1;i++)
		{
			x4=(fr.x4+i+10)%10;
			temp.x4=x4;
			if (visited[temp.x1][temp.x2][temp.x3][temp.x4]==false && isForbidden[toInt(temp)]==false)
			{
				temp.dis=fr.dis+1;
				push(temp);
				visited[temp.x1][temp.x2][temp.x3][temp.x4]=true;
			}
		}
	}
	return -1;
}

int main ()
{
	int tc;
	node init,des;
	int f[4];
	int integer;
	cin>>tc;
	while (tc--)
	{
		for (int i=0;i<MAX;i++)
			isForbidden[i]=false;
		scanf("%d %d %d %d",&init.x1,&init.x2,&init.x3,&init.x4);
		scanf("%d %d %d %d",&des.x1,&des.x2,&des.x3,&des.x4);
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		{
			integer=0;
			for (int i=0;i<4;i++)
			{
				scanf("%d",&f[i]);
				integer=integer*10+f[i];
			}
			isForbidden[integer]=true;
		}
		printf("%d\n",BFS(init,des));
	}
	return 0;
}
