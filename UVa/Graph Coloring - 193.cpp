									/*ba yade oo */

/*
AC Code

Problem : UVA - 193 - Graph Coloring
Category : Graph Coloring - BT
Complexity : exp!
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
#define MAX 103

typedef vector<int> vi;

int col[MAX],ans[MAX];
int N,maxi;
bool g[MAX][MAX];

bool isOK(int x)
{
	if (col[x]==0)return true;//color is white

	for (int i=1;i<x;i++)
		if (g[i][x] && col[i]==1)
			return false;

	return true;
}

void BT(int k,int sum)
{
	if (isOK(k-1)==false)return;

	if (k==N+1)
	{
		if (sum>maxi)
		{
			maxi=sum;
			for (int i=1;i<=N;i++)
				ans[i]=col[i];
			
		}
		return;
	}

	col[k]=1;
	BT(k+1,sum+1);
	col[k]=0;
	BT(k+1,sum);

}


int main ()
{
	int tc,v1,v2;
	cin>>tc;
	int M;
	while (tc--)
	{
		cin>>N>>M;
		memset(g,false,sizeof(g));
		memset(col,0,sizeof(col));

		for (int i=0;i<M;i++)
		{
			cin>>v1>>v2;
			g[v1][v2]=g[v2][v1]=true;
		}

		maxi=0;
		BT(1,0);
		cout<<maxi<<endl;
		int cnt=0,lastInd=0;
		for (int i=1;i<=N;i++)
		{
			if (ans[i]==1)
			{
				cnt++;
				if (cnt==maxi)
				{
					lastInd=i;
					break;
					
				}
				printf("%d ",i);
			}
		}
		cout<<lastInd<<endl;

	}
	return 0;
}