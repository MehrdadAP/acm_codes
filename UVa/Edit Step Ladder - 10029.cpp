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

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
//#define INF 0x7FFFFFFF
#define MAX 25100

int **g;
bool visited[MAX];
int level[MAX];

bool isStep(char* w1,char* w2)
{
	int len1=strlen(w1);
	int len2=strlen(w2);
	int dif=absol(len1-len2);
	int minLen=min(len1,len2);

	bool flag=true;

	if (dif>1)
		return false;
	if (dif==1)
	{
		for (int i=0;i<minLen;i++)
			if (w1[i]!=w2[i])
				return false;
	}

	for (int i=0;i<len1;i++)
	{
		if (w1[i]!=w2[i])
			if (flag==false)
				return false;
			else
				flag=false;		
	}
	return true;
}


int BFS(int src,int n)
{
	/*for (int i=0;i<n;i++)
		visited[i]=false;
*/
	level[src]=1;
	queue<int> q;
	q.push(src);
	visited[src]=true;
	int maxL=-1;
	while (!q.empty())
	{
		int fr=q.front();
		q.pop();
		for (int i=1;i<=g[fr][0];i++)
		{
			int curr=g[fr][i];
			if (visited[curr]==false)
			{
				level[curr]=level[fr]+1;
				if (level[curr]>maxL)
					maxL=level[curr];
				q.push(curr);
				visited[curr]=true;
			}
		}
	}
	return maxL;
}

int main ()
{
	
	char word[MAX][20];
	int n=0;
	int ans=-1;
	while (scanf("%s",word[n++])!=EOF);
	
	g=new int*[n+10];
	for (int i=0;i<n+10;i++)
		g[i]=new int [n+10];
	//make graph
	for (int i=0;i<n-1;i++)
	{
		g[i][0]=0;
		visited[i]=false;
		for (int j=i+1;j<n;j++)
		{
			if (isStep(word[i],word[j]))
				g[i][++g[i][0]]=j;
		}
	}

	for (int i=0;i<n;i++)
	{
		if (visited[i]==false)
			ans=max(BFS(i,n),ans);

	}
	printf("%d\n",ans);
	//system("pause");
	return 0;

}
