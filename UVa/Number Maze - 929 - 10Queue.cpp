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
#define MAX 1000
#define inRange(x,y)((x)>=0 && (y)>=0 && (x)<(N) && (y)<(M))

int **a,**dis;
int M,N;
int heapSize;


#define Right(i) (2*i+1)
#define Left(i) (2*i)
#define Parent(i) ((int)(i/2))

struct point
{
	int i,j;
	int value;
	bool operator <(point &b)
	{
		return (value<b.value);
	}
};/*

point *list;

void MinHeapify(int i)
{
	int l=Left(i);
	int r=Right(i);
	int large;
	if (l<=heapSize && list[l]<list[i])
		large=l;
	else
		large=i;
	if (r<=heapSize && list[r]<list[large])
		large=r;
	if (large!=i)
	{
		swap(list[large],list[i]);
		MinHeapify(large);
	}
}

point ExtractMin()
{
	point temp=list[1];
	list[1]=list[heapSize];
	heapSize--;
	MinHeapify(1);
	return temp;
}

void HeapIncreasKey(int i,point key)
{
	list[i]=key;
	while (i>1 && list[i]<list[Parent(i)])
	{
		swap(list[i],list[Parent(i)]);
		i=Parent(i);
	}
}
void MinHeapInsert(point key)
{
	heapSize++;
	point temp;
	temp.value=INF;
	list[heapSize]=temp;
	HeapIncreasKey(heapSize,key);
	
}*/

#define MAX2 18000

void relax(int i1,int j1,int i2,int j2)
{
	if (a[i2][j2]+dis[i1][j1]<dis[i2][j2])
		dis[i2][j2]=dis[i1][j1]+a[i2][j2];
}

void Dijkstar(int is,int js)//is:istart js:jstart
{
	queue<point> qu[MAX];
	point temp;
	//int map[MAX];
	bool **visited;
	visited=new bool*[MAX];
	for (int i=0;i<MAX;i++)
		visited[i]=new bool[MAX];

	for (int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			dis[i][j]=INF;
			visited[i][j]=false;
		}

	dis[is][js]=a[0][0];
	temp.i=0;temp.j=0;
	temp.value=dis[0][0];
	qu[dis[0][0]].push(temp);
	//list[1]=temp;
	//heapSize++;
	//cout<<v.front().value;
	bool flag;
	int minI,minJ;
	int min=0;
	while(1)
	{
		flag=false;		
		for (int i=min;i<MAX2;i++)
		{
			if (!qu[i].empty())
			{
				temp=qu[i].front();
				qu[i].pop();
				min=i;
				break;
			}
		}
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
			qu[temp.value].push(temp);
		}
		//Left
		if (inRange(minI,minJ+1) && !visited[minI][minJ+1])
		{
			relax(minI,minJ,minI,minJ+1);
			temp.i=minI;temp.j=minJ+1;
			temp.value=dis[minI][minJ+1];
			qu[temp.value].push(temp);
		}
		//Right
		if (inRange(minI,minJ-1) && !visited[minI][minJ-1])
		{
			relax(minI,minJ,minI,minJ-1);
			temp.i=minI;temp.j=minJ-1;
			temp.value=dis[minI][minJ-1];
			qu[temp.value].push(temp);
		}
		//South
		if (inRange(minI+1,minJ) && !visited[minI+1][minJ])
		{
			relax(minI,minJ,minI+1,minJ);
			temp.i=minI+1;temp.j=minJ;
			temp.value=dis[minI+1][minJ];
			qu[temp.value].push(temp);
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
4
1 1
9
2 2
0 0
0 0
20 20
1 4 5 7 8 9 7 5 3 4 6 7 4 3 6 8 4 3 5 9
2 4 0 9 7 5 4 6 7 8 4 3 1 4 6 7 8 9 6 5
1 2 3 4 6 6 8 9 9 0 0 0 0 0 3 4 5 4 3 1
1 4 5 7 8 9 7 5 3 4 6 7 4 3 6 8 4 3 5 9
2 4 0 9 7 5 4 6 7 8 4 3 1 4 6 7 8 9 6 5
1 2 3 4 5 6 7 8 9 9 0 6 4 3 2 4 5 6 7 8
8 5 9 2 4 5 6 7 8 9 2 1 2 3 4 5 6 8 9 0
9 9 9 0 0 0 0 0 1 2 3 4 6 7 8 9 0 5 4 3
1 2 3 4 5 6 7 8 9 9 0 6 4 3 2 4 5 6 7 8
1 4 5 7 8 9 7 5 3 4 6 7 4 3 6 8 4 3 5 9
1 3 5 7 8 9 2 2 2 2 3 4 4 4 4 5 6 7 8 9
0 9 9 8 7 6 9 9 9 9 9 9 9 0 0 0 0 0 9 9
1 2 3 4 5 6 7 8 9 9 0 6 4 3 2 4 5 6 7 8
8 5 9 2 4 5 6 7 8 9 2 1 2 3 4 5 6 8 9 0
1 2 3 4 6 6 8 9 9 0 0 0 0 0 3 4 5 4 3 1
1 4 5 7 8 9 7 5 3 4 6 7 4 3 6 8 4 3 5 9
1 2 3 4 5 6 7 8 9 5 3 2 4 5 6 7 8 9 9 6
1 2 3 4 5 6 7 8 9 9 0 6 4 3 2 4 5 6 7 8
0 0 0 0 0 0 1 1 1 1 2 3 3 3 3 3 4 4 4 4
3 3 3 1 1 1 1 1 3 4 5 6 7 8 9 0 5 4 3 1
22 20
1 4 5 7 8 9 7 5 3 4 6 7 4 3 6 8 4 3 5 9
2 4 0 9 7 5 4 6 7 8 4 3 1 4 6 7 8 9 6 5
1 2 3 4 6 6 8 9 9 0 0 0 0 0 3 4 5 4 3 1
1 4 5 7 8 9 7 5 3 4 6 7 4 3 6 8 4 3 5 9
2 4 0 9 7 5 4 6 7 8 4 2 2 2 2 2 8 9 6 5
1 2 3 4 5 6 7 8 9 9 0 6 4 3 2 4 0 6 7 8
1 5 9 2 4 5 6 7 8 9 2 1 2 3 4 5 6 8 9 0
9 9 9 0 0 0 0 0 1 2 3 4 6 7 8 9 0 5 4 3
1 2 3 4 5 6 7 8 9 9 0 6 4 0 0 0 5 6 7 8
1 4 5 7 8 9 7 5 3 4 6 7 4 0 0 0 4 3 5 9
1 3 5 7 8 9 2 2 0 2 3 4 4 0 0 0 6 4 8 9
0 9 9 8 7 6 9 9 9 9 9 9 9 0 0 0 2 0 9 9
1 2 3 4 5 6 7 8 9 9 0 6 4 3 2 4 5 6 7 8
8 5 9 2 4 5 6 7 8 9 2 1 2 3 4 5 6 8 9 0
1 2 3 4 6 6 8 9 0 0 0 0 0 0 3 4 5 4 3 1
1 4 5 7 8 9 7 5 3 4 6 7 4 3 6 8 4 3 5 9
1 2 3 4 5 6 7 8 9 5 3 2 4 5 6 7 8 9 9 6
1 2 3 4 5 6 7 8 9 9 0 6 4 3 2 4 5 6 7 8
0 0 0 0 0 0 1 1 1 1 2 3 3 3 3 3 4 4 4 4
3 3 3 1 1 1 1 1 3 4 5 6 7 8 9 0 5 4 3 1
8 5 9 2 4 5 6 7 8 9 2 1 2 3 4 5 6 8 9 0
1 2 3 4 6 6 8 9 9 0 0 0 0 0 3 4 5 4 3 1

Ans:
9
0
75
67
----
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