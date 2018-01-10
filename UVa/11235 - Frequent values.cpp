									/*ba yade oo */

/*
AC Code

Problem : UVA - 11235 - Frequent Value
Cateory : Segment Tree - RMQ
Complexity : O(n*logn) Preprocess and 
			 O(logn) for each query

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
#define MAX 100002

typedef vector<int> vi;

int End[MAX],start[MAX],frq[MAX],segment[4*MAX+10];
int a[MAX];

void buildTree(int x,int b,int e)
{
	if (b==e)
	{
		segment[x]=b;
		return;
	}

	int leftInd=2*x+1;
	int rightInd=2*x;

	buildTree(leftInd,b,(b+e)/2);
	buildTree(rightInd,(b+e)/2+1,e);

	int p1=segment[leftInd];
	int p2=segment[rightInd];

	segment[x]=(frq[p1]>=frq[p2])? p1 :p2;
}


int query(int x,int i,int j,int b,int e)
{

	if (i>e || j<b)return -1;
	if (i<=b && j>=e) return segment[x];

	int p1=query(2*x+1,i,j,b,(b+e)/2);
	int p2=query(2*x,i,j,(b+e)/2+1,e);

	if (p1==-1)return p2;
	if (p2==-1)return p1;

	return (frq[p1]>=frq[p2]) ? p1:p2;
}

int main ()
{
	
	int N,Q;
	while (scanf("%d",&N),N!=0)
	{
		cin>>Q;

		for (int i=1;i<=N;i++)
			scanf("%d",&a[i]);

		//set start positions
		start[1]=1;
		for (int i=2;i<=N;i++)
		{
			if (a[i]==a[i-1])start[i]=start[i-1];
			else start[i]=i;
		}
		 
		//set end position
		End[N]=N;
		for (int i=N-1;i>=1;i--)
		{
			if (a[i]==a[i+1])End[i]=End[i+1];
			else End[i]=i;
		}

		//set frq array
		for (int i=1;i<=N;i++)
			frq[i]=End[i]-start[i]+1;

		memset(segment,0,sizeof(segment));
		buildTree(1,1,N);

		int x,y,ans;
		while (Q--)
		{
			scanf("%d %d",&x,&y);
			if (a[x]==a[y])ans=y-x+1;//Handle tricky state !
			else
			{
				ans=max(End[x]-x+1,y-start[y]+1);
				ans=max(ans,frq[query(1,End[x]+1,start[y]-1,1,N)]);
			}

			printf("%d\n",ans);

		}
	}

	return 0;
}