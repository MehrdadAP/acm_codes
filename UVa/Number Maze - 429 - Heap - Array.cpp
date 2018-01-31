//Implementation By min-Heap


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
#define MAX 1002

int **a,**dis;
int M,N;

#define inRange(x,y)((x)>=0 && (y)>=0 && (x)<(N) && (y)<(M))


struct point
{
	int i,j;
	int value;
	point()
	{}
};

bool comp(point x,point y)
{
	if (x.value>y.value)
		return true;
	else
		return false;
}

void relax(int i1,int j1,int i2,int j2)
{
	if (a[i2][j2]+dis[i1][j1]<dis[i2][j2])
		dis[i2][j2]=dis[i1][j1]+a[i2][j2];
}

void Dijkstar(int is,int js)//is:istart js:jstart
{
	point *list;
	list=new point[MAX*MAX];
	int endList=0;
	point temp;
	//int map[MAX];
	bool visited[MAX][MAX];
	for (int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			dis[i][j]=INF;
			visited[i][j]=false;
		}
	dis[is][js]=a[0][0];
	temp.i=0;temp.j=0;
	temp.value=dis[0][0];
	list[endList++]=temp;
	make_heap(list,list+endList,comp);
	//cout<<v.front().value;
	bool flag;
	int minI,minJ;
	int min;
	while(endList!=0)
	{
		flag=false;
		pop_heap(list,list+endList,comp);
		temp=list[--endList];
		//if (!flag) break;
		if (temp.i==N-1 && temp.j==M-1)
			break;
		//North
		minI=temp.i;minJ=temp.j;
		//printf("%d %d\n",minI,minJ);
		visited[minI][minJ]=true;
		if (inRange(minI-1,minJ) && !visited[minI-1][minJ])
		{
			relax(minI,minJ,minI-1,minJ);
			temp.i=minI-1;temp.j=minJ;
			temp.value=dis[minI-1][minJ];
			list[endList++]=temp;push_heap(list,list+endList,comp);
		}
		//Left
		if (inRange(minI,minJ+1) && !visited[minI][minJ+1])
		{
			relax(minI,minJ,minI,minJ+1);
			temp.i=minI;temp.j=minJ+1;
			temp.value=dis[minI][minJ+1];
			list[endList++]=temp;push_heap(list,list+endList,comp);	
		}
		//Right
		if (inRange(minI,minJ-1) && !visited[minI][minJ-1])
		{
			relax(minI,minJ,minI,minJ-1);
			temp.i=minI;temp.j=minJ-1;
			temp.value=dis[minI][minJ-1];
			list[endList++]=temp;push_heap(list,list+endList,comp);
		}
		//South
		if (inRange(minI+1,minJ) && !visited[minI+1][minJ])
		{
			relax(minI,minJ,minI+1,minJ);
			temp.i=minI+1;temp.j=minJ;
			temp.value=dis[minI+1][minJ];
			list[endList++]=temp;push_heap(list,list+endList,comp);
		}

	}
}

int main ()
{
	a=new int*[MAX];
	for (int i=0;i<MAX;i++)
		a[i]=new int[MAX];

	dis=new int*[MAX];
	for (int i=0;i<MAX;i++)
		dis[i]=new int[MAX];

	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		scanf("%d %d",&N,&M);
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++)
				scanf("%d",&a[i][j]);

		Dijkstar(0,0);
		printf("%d\n",dis[N-1][M-1]);
	}
	return 0;

}

/*
10
4
5
1 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
3 0 0 0 0 5
*/