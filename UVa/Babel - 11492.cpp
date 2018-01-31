#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <queue>
#include <map>

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 0x7FFFFFFF
#define MAX 2050

int g[MAX][MAX],d[MAX];
map<string,int> mp;
//char names[MAX*50][550];

void relax(int u,int v)
{
	if (d[u]+g[u][v]<d[v])
		d[v]=g[u][v]+d[u];

}

int Dijkstra(int src,int des,int N)
{
	bool visited[MAX];
	for (int i=0;i<N;i++)
	{
		d[i]=INF;
		visited[i]=false;
	}
	d[src]=0;
	int min,minInd;
	bool flag;
	for (int i=0;i<N;i++)
	{
		min=INF;
		flag=false;
		for (int j=0;j<N;j++)
			if (visited[j]==false && d[j]<min)
			{
				min=d[j];
				minInd=j;
				flag=true;
			}
		if (!flag) return -1;
		visited[minInd]=true;
		if (minInd==des)
			return d[minInd];
		for (int j=0;j<N;j++)
		{
			if (!visited[j] && g[minInd][j]!=INF)
				relax(minInd,j);
		}
	}
}
//
//int isExist(char *name,int N)
//{
//	for (int i=0;i<N;i++)
//		if (strcmp(names[i],name)==0)
//			return i;
//	return -1;
//}

int main ()
{
	int E;
	char name1[550],name2[550],weight[550];
	char start[550],end[550];
	
	int cnt,len,id1,id2,ans;
	
	while (scanf("%d",&E),E!=0)
	{
		mp.clear();
		cnt=0;
		scanf("%s %s",start,end);
		//Initialize wight array
		for (int i=0;i<MAX;i++)
			for (int j=0;j<MAX;j++)
				g[i][j]=INF;
		for (int i=0;i<E;i++)
		{

			scanf("%s %s %s",name1,name2,weight);
			if (mp.find(name1)==mp.end())
				mp[name1]=cnt++;

			if (mp.find(name2)==mp.end())
				mp[name2]=cnt++;

			len=strlen(weight);
			//len=strlen(weight);
			id1=mp[name1];id2=mp[name2];
			g[id1][id2]=g[id2][id1]=min(g[id1][id2],len);
		}
		

		/*id1=isExist(start,cnt);
		id2=isExist(end,cnt);
		if (id1==-1 || id2==-1)
			puts("impossivel");
		else
		{
			ans=Dijkstra(id1,id2,cnt);
			if (ans==-1)
				puts("impossivel");
			else
				printf("%d\n",ans);
		}*/

		if (mp.find(start)==mp.end())
			puts("impossivel");
		else if (mp.find(end)==mp.end())
			puts("impossivel");
		else
		{
			
			ans=Dijkstra(mp[start],mp[end],cnt);
			if (ans==-1)
				puts("impossivel");
			else
				printf("%d\n",ans);
		}
		
	}

	return 0;

}
