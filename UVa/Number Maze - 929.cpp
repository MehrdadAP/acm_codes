//Implementation By Array
//Time Limit Exceed !


#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 1e8
#define MAX 1001

int a[MAX][MAX],dis[MAX][MAX];
int M,N;

#define inRange(x,y)((x)>=0 && (y)>=0 && (x)<(N) && (y)<(M))

//bool inRange(int x,int y)
//{
//	bool ans=((x)>=0 && (y)>=0 && (x)<(N) && (y)<(M));
//	return ans;
//}
void relax(int i1,int j1,int i2,int j2)
{
	if (a[i1][j1]+dis[i1][j1]<dis[i2][j2])
	{
		dis[i2][j2]=dis[i1][j1]+a[i1][j1];
	}
}

void Dijkstar(int is,int js)//is:istart js:jstart
{
	bool visited[MAX][MAX];
	for (int i=0;i<N;i++)
		for(int j=0;j<M;j++)
		{
			dis[i][j]=INF;
			visited[i][j]=false;
		}
	dis[is][js]=a[0][0];
	bool flag;
	int min,minI,minJ;
	for (int k=0;k<M*N;k++)
	{
		flag=false;
		min=INF;
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++)
				if (!visited[i][j] && dis[i][j]<min)
				{
					min=dis[i][j];
					minI=i;
					minJ=j;
					flag=true;
				}
		if (!flag) break;
		visited[minI][minJ]=true;
		if (visited[N-1][M-1]==true)
			break;
		//North
		if (inRange(minI-1,minJ) && !visited[minI-1][minJ])
			relax(minI,minJ,minI-1,minJ);
		//Left
		if (inRange(minI,minJ+1) && !visited[minI][minJ+1])
			relax(minI,minJ,minI,minJ+1);
		//Right
		if (inRange(minI,minJ-1) && !visited[minI][minJ-1])
			relax(minI,minJ,minI,minJ-1);
		//South
		if (inRange(minI+1,minJ) && !visited[minI+1][minJ])
			relax(minI,minJ,minI+1,minJ);
	}
}

int main ()
{
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