									/*ba yade oo */

/*
AC Code
Simple do BFS ;)

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
#define MAX 120
#define inRange(x,y) (x<N && x>=0 && y<M && y>=0)

typedef vector<int> vi;
typedef pair<int,int> pii;

char g[MAX][MAX];
bool visited[MAX][MAX];
int dis[MAX][MAX],N,M;

int dx[]={-2,-2,+2,+2,-1,-1,+1,+1};
int dy[]={-1,+1,-1,+1,-2,+2,-2,+2};

int dxKing[]={-1,-1,-1,0,0,+1,+1,+1};
int dyKing[]={-1,0,+1,-1,+1,-1,0,+1};

void fillHorseSquares(int x,int y)
{
	for (int i=0;i<8;i++)
	{
		int x1=x+dx[i],y1=y+dy[i];

		if (inRange(x1,y1) && g[x1][y1]!='Z' && g[x1][y1]!='A' && g[x1][y1]!='B')
			g[x1][y1]='#';
	}
}

int BFS(int sx,int sy,int ex,int ey)
{
	memset(visited,false,sizeof visited);
	memset(dis,0,sizeof(dis));
	queue<pii> q;
	q.push(pii(sx,sy));
	visited[sx][sy]=true;
	dis[sx][sy]=0;

	while (q.empty()==false)
	{
		int xx=q.front().first;
		int yy=q.front().second;
		q.pop();
		if (xx==ex && yy==ey)return dis[xx][yy];

		for (int i=0;i<8;i++)
		{
			int x1=xx+dxKing[i];
			int y1=yy+dyKing[i];
			if (inRange(x1,y1) && g[x1][y1]!='Z' && g[x1][y1]!='#' && visited[x1][y1]==false)
			{
				visited[x1][y1]=true;
				dis[x1][y1]=dis[xx][yy]+1;
				q.push(pii(x1,y1));
			}
		}
	}

	return -1;

}


int main ()
{

	
	int tc;
	cin>>tc;
	int sx,sy,ex,ey;//start and end poses



	while (tc--)
	{
		cin>>N>>M;
		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++)
				cin>>g[i][j];

		for (int i=0;i<N;i++)
			for (int j=0;j<M;j++){
				if (g[i][j]=='A'){
					sx=i;
					sy=j;
				}
				else if (g[i][j]=='B'){
					ex=i;
					ey=j;
				}
				else if (g[i][j]=='Z'){
					fillHorseSquares(i,j);
				}

			}
		int ans=BFS(sx,sy,ex,ey);
		if (ans==-1)
			puts("King Peter, you can't go now!");
		else
			printf("Minimal possible length of a trip is %d\n",ans);

	}

	return 0;
}