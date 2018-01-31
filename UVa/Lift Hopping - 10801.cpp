//Dijkstra on multiple graph
//i saved each graph seperatly and in relax function 
//check for each edge the best key for each node !!!
//Arabpour.M

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
#define INF 0x7FFFFFFF
#define MAX 102
#define ELEV 6

struct FLOOR
{
	int dis,eid,num;
	//eid= from which elevator comes
};

int t[ELEV],g[ELEV][MAX][MAX],station[ELEV][MAX],N;
FLOOR f[MAX];
bool visited[MAX];

//Adjacency Matrix
void makeGraph(int ind)
{
	int v1,v2;
	//add each node to adj list matrix
	for (int i=1;i<station[ind][0];i++)
	{
		v1=station[ind][i];
		for (int j=i+1;j<=station[ind][0];j++)
		{
			v2=station[ind][j];
			g[ind][v1][++g[ind][v1][0]]=v2;
			g[ind][v2][++g[ind][v2][0]]=v1;
		}
	}
	return;
}

void relax(int u)
{
	for (int ind=0;ind<N;ind++)
	{
		for (int j=1;j<=g[ind][u][0];j++)
		{
			int curr=g[ind][u][j];
			if (visited[curr]==true)continue;
			int temp=f[u].dis+absol((curr-u))*t[ind];
			if (f[u].eid!=ind && u!=0)
				temp+=60;
			if (temp<f[curr].dis)
			{
				f[curr].dis=temp;
				f[curr].eid=ind;
			}
		}
	}
}


int Dijkstra (int sourcId,int des)
{
	
	for (int i=0;i<MAX;i++)
	{
		visited[i]=false;
		f[i].dis=INF;
	}
	f[0].dis=0;
	f[0].eid=sourcId;
	int min,flag,minInd;
	for (int i=0;i<MAX;i++)
	{
		min=INF;
		flag=false;
		for (int j=0;j<MAX;j++)
			if (visited[j]==false && f[j].dis<min)
			{
				minInd=j;
				min=f[j].dis;
				flag=true;
			}
		if (flag==false) return -1;
		visited[minInd]=true;
		if (minInd==des)
			return f[minInd].dis;
		relax(minInd);
	}

}
int main ()
{
	
	int K,cnt;
	char line[10*MAX];
	istringstream iss;
	while (scanf("%d %d",&N,&K)!=EOF)
	{
		//Reading Input
		for (int i=0;i<N;i++)
			scanf("%d",&t[i]);
		gets(line);
		for (int i=0;i<N;i++)
		{
			iss.clear();
			gets(line);
			iss.str(line);
			int len=strlen(line);
			cnt=0;
			for (int i=0;i<len;i++)
				if (line[i]==' ')
					cnt++;
			cnt++;
			station[i][0]=cnt;
			for (int j=1;j<=cnt;j++)
				iss>>station[i][j];
		}
		
		//Sort Stations
		for (int i=0;i<N;i++)
			sort(station[i]+1,station[i]+station[i][0]);
		
		for (int i=0;i<N;i++)
			for (int j=0;j<MAX;j++)
				g[i][j][0]=0;
		//make Graph
		for (int i=0;i<N;i++)
			makeGraph(i);

		int mini=Dijkstra(0,K);
		if (mini==-1)
			puts("IMPOSSIBLE");
		else
			printf("%d\n",mini);
	}
	return 0;

}
