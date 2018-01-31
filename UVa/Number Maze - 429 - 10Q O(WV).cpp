//After many attempts & thinking finally ,Accepted 
//related to CLRS Excersise 24.3.6 
//but with remarkable better Implementation
//in CLRS sol suggest to use O(WV) memory 
//but This Impl. uses only O(W) Memory

//using 10 Priority_queue 
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
#define INF 2147483639
#define MAX 1000
#define inRange(x,y)((x)>=0 && (y)>=0 && (x)<(N) && (y)<(M))

int N,M;
int a[MAX][MAX],dis[MAX][MAX];
bool visited[MAX][MAX];

struct POINT
{

	int x;int y;int dis;
	bool operator<(const POINT &b)const
	{
		return (dis<b.dis);
	}
};

bool relax(int i1,int j1,int i2,int j2)
{
	bool flag=false;
	if (a[i2][j2]+dis[i1][j1]<dis[i2][j2])
	{
		dis[i2][j2]=dis[i1][j1]+a[i2][j2];
		flag=true;
	}
	return flag;
}


int  Dijkstra ()
{
	POINT temp,fr;
	int ind;
	priority_queue<POINT> pq[10];
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
		{
			visited[i][j]=false;
			dis[i][j]=INF;
		}
	dis[0][0]=a[0][0];
	temp.x=0;temp.y=0;temp.dis=a[0][0];

	pq[a[0][0]].push(temp);
	ind=a[0][0];
	while (1)
	{
		if (!pq[ind].empty())
		{
			fr=pq[ind].top();
			pq[ind].pop();
		}
		else
		{
			while (pq[ind].empty()==true)
			{
				ind++;
				if (ind==10)
					ind=0;
			}
			fr=pq[ind].top();
			pq[ind].pop();
		}
		visited[fr.x][fr.y]=true;
		if (fr.x==N-1 && fr.y==M-1)
			return fr.dis;
		int minI=fr.x;
		int minJ=fr.y;
		//North
		if (inRange(minI-1,minJ) && !visited[minI-1][minJ])
		{
			if (relax(minI,minJ,minI-1,minJ)==true)
			{
				temp.x=minI-1;temp.y=minJ;
				temp.dis=dis[minI-1][minJ];
				int currInd=(a[minI-1][minJ]+fr.dis)%10;
				pq[currInd].push(temp);
			}
		}

		//Left
		if (inRange(minI,minJ+1) && !visited[minI][minJ+1])
		{
			if (relax(minI,minJ,minI,minJ+1)==true)
			{
				temp.x=minI;temp.y=minJ+1;
				temp.dis=dis[minI][minJ+1];
				int currInd=(a[minI][minJ+1]+fr.dis)%10;
				pq[currInd].push(temp);
			}
		}

		//Right
		if (inRange(minI,minJ-1) && !visited[minI][minJ-1])
		{
			if (relax(minI,minJ,minI,minJ-1)==true)
			{
				temp.x=minI;temp.y=minJ-1;
				temp.dis=dis[minI][minJ-1];
				int currInd=(a[minI][minJ-1]+fr.dis)%10;
				pq[currInd].push(temp);
			}
		}

		//South
		if (inRange(minI+1,minJ) && !visited[minI+1][minJ])
		{
			if (relax(minI,minJ,minI+1,minJ)==true)
			{
				temp.x=minI+1;temp.y=minJ;
				temp.dis=dis[minI+1][minJ];
				int currInd=(a[minI+1][minJ]+fr.dis)%10;
				pq[currInd].push(temp);
			}
		}

	}
}

int main ()
{
/*
	a=new int*[MAX];
	for (int i=0;i<MAX;i++)
		a[i]=new int[MAX];

	dis=new int*[MAX];
	for (int i=0;i<MAX;i++)
		dis[i]=new int[MAX];

		*/

	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&N,&M);
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++)
				scanf("%d",&a[i][j]);

		Dijkstra();
		printf("%d\n",dis[N-1][M-1]);
	}
	return 0;

}
