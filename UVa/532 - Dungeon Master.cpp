									/*ba yade oo */

/*
AC Code
Problem : UVA - 532 - Dungeon Master
Category : Simple BFS
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
#define MAX  35
#define inRange(x,y,z) (x<R && x>=0 && y<C && y>=0 && z<L && z>=0)

typedef vector<int> vi;

bool g[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int L,R,C;

struct POINT
{
	int x,y,z,dis;
	POINT(int X,int Y,int Z,int Dis)
	{
		x=X;y=Y;z=Z;
		dis=Dis;
	}

	bool operator == (const POINT &b)const 
	{
		return (x==b.x && y==b.y && z==b.z);
	}

	POINT(){dis=0;};
};


int BFS(POINT start,POINT end)
{
	
	queue<POINT> q;
	memset(visited,false,sizeof(visited));

	visited[start.x][start.y][start.z]=true;
	q.push(start);
	while (!q.empty())
	{

		POINT curr=q.front();//current POINT for check neighbours
		q.pop();

		if (curr==end)return curr.dis;

		int xx=curr.x,yy=curr.y,zz=curr.z;


		//north
		if (inRange(xx-1,yy,zz) && visited[xx-1][yy][zz]==false && g[xx-1][yy][zz])
		{
			q.push(POINT(xx-1,yy,zz,curr.dis+1));
			visited[xx-1][yy][zz]=true;
		}
		
		//right
		if (inRange(xx,yy+1,zz) && visited[xx][yy+1][zz]==false && g[xx][yy+1][zz])
		{
			q.push(POINT(xx,yy+1,zz,curr.dis+1));
			visited[xx][yy+1][zz]=true;
		}

		//south
		if (inRange(xx+1,yy,zz) && visited[xx+1][yy][zz]==false && g[xx+1][yy][zz])
		{
			q.push(POINT(xx+1,yy,zz,curr.dis+1));
			visited[xx+1][yy][zz]=true;
		}
		
		//left
		if (inRange(xx,yy-1,zz) && visited[xx][yy-1][zz]==false && g[xx][yy-1][zz])
		{
			q.push(POINT(xx,yy-1,zz,curr.dis+1));
			visited[xx][yy-1][zz]=true;
		}
		//up
		if (inRange(xx,yy,zz-1) && visited[xx][yy][zz-1]==false && g[xx][yy][zz-1])
		{
			q.push(POINT(xx,yy,zz-1,curr.dis+1));
			visited[xx][yy][zz-1]=true;
		}
		
		//down
		if (inRange(xx,yy,zz+1) && visited[xx][yy][zz+1]==false && g[xx][yy][zz+1])
		{
			q.push(POINT(xx,yy,zz+1,curr.dis+1));
			visited[xx][yy][zz+1]=true;
		}

	}
	return -1;
}

int main ()
{
	POINT start,end;

	while (cin>>L>>R>>C , L && R && C)
	{
		for (int k=0;k<L;k++)
			for (int i=0;i<R;i++)
				for (int j=0;j<C;j++)
				{
					char ch;
					cin>>ch;
					if (ch=='.')g[i][j][k]=1;
					else if (ch=='#')g[i][j][k]=0;
					else if (ch=='S'){g[i][j][k]=1;start=POINT(i,j,k,0);}
					else if (ch=='E'){g[i][j][k]=1;end=POINT(i,j,k,0);}
				}

		int ans=BFS(start,end);
		if (ans==-1)
			puts("Trapped!");
		else
			printf("Escaped in %d minute(s).\n",ans);

	}

	return 0;
}