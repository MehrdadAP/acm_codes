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


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 0x7FFFFFFF
#define MAX 110
#define isNum(x) ((x)>='0' && (x)<='9')
#define inRange(x,y) (x>=1 && y>=1 && x<=N && y<=M)

char g[MAX][MAX];
bool visited[MAX][MAX];

int N,M;
int dr[] = {1,1,0,-1,-1,-1, 0, 1};// S,SE,E,NE,N,NW,W,SW
int dc[] = {0,1,1, 1, 0,-1,-1,-1}; // neighbor



int DFS(int x,int y)
{
	visited[x][y]=true;

	int ret=1;
	for (int i=0;i<8;i++)
	{
		if (inRange(x+dr[i],y+dc[i]) && visited[x+dr[i]][y+dc[i]]==false && g[x+dr[i]][y+dc[i]]=='W')
			ret+=DFS(x+dr[i],y+dc[i]);
	}

	return ret;
}

int main ()
{
	char s[110];
	int tc,x,y,Q;

	gets(s);
	sscanf(s,"%d",&tc);
	gets(s);//blank line
	while (tc--)
	{
		
		
		gets(s);
		N=strlen(s);
		M=0;
		while (isNum(s[0])==false)
		{
			M++;
			for (int i=1;i<=N;i++)
				g[M][i]=s[i-1];
			gets(s);

		}
		
		while (s!='\0' && isNum(s[0])==true )
		{
			sscanf(s,"%d %d",&x,&y);
			memset(visited,false,sizeof(visited));
			if (g[x][y]!='W')
				puts("0");
			else
				printf("%d\n",DFS(x,y));
			cin.getline(s,1000);
		}
		if (tc!=0)
			printf("\n");//Blank line between tow consecutive test case
			
	}

	return 0;

}
