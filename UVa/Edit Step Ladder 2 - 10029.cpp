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
int list[MAX];
int height[MAX];
int c[20][20];
int endList;
int n;
int ansMax;
int LCS(char* x,char* y)
{
	int m,n;
	m=strlen(x);
	n=strlen(y);

	for (int j=0;j<=n;j++)
		c[0][j]=0;

	for (int i=1;i<=m;i++)
	{
		c[i][0]=0;
		for (int j=1;j<=n;j++)
			if (x[i-1]==y[j-1])
				c[i][j]=c[i-1][j-1]+1;
			else
				c[i][j]=max(c[i-1][j],c[i][j-1]);
	}
	return c[m][n];
}

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
		if (LCS(w1,w2)==minLen)
			return true;
		else
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


void topol(int v)
{
	visited[v]=true;
	for (int i=1;i<=g[v][0];i++)
	{
		int curr=g[v][i];
		if (visited[curr]==false)
			topol(curr);
	}
	list[endList--]=v;
}


int main ()
{
	/*char w1[20],w2[20];
	while (cin>>w1>>w2)
	{
		printf("%d\n",LCS(w1,w2));
	}*/
	char word[MAX][20];
	n=0;
	int ans=-1;
	while (cin>>word[n])
	{
		n++;
	}

	g=new int* [n+10];
	for (int i=0;i<n+10;i++)
	{
		g[i]=new int [n+10];
		g[i][0]=0;
	}

	//make graph
	for (int i=0;i<n-1;i++)
	{	
		visited[i]=false;
		height[i]=1;
		for (int j=i+1;j<n;j++)
		{
			if (isStep(word[i],word[j]))
				//g[i][j]=true;
				g[i][++g[i][0]]=j;
		}
	}

	visited[n-1]=false;
	height[n-1]=1;

	endList=n-1;
	for (int i=0;i<n;i++)
		if (visited[i]==false)
			topol(i);
	int ansMax=-1;
	for (int i=n-1;i>=0;i--)
	{
		int curri=list[i];
		for (int j=1;j<=g[curri][0];j++)
		{
			int currj=g[curri][j];
			height[curri]=max(height[curri],height[currj]+1);
		}
		if (height[curri]>ansMax)
			ansMax=height[curri];
	}
	printf("%d\n",ansMax);

	system("pause");
	return 0;

}
