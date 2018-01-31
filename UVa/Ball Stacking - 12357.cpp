									/*ba yade oo */


/*
AC Code

Problem : UVA - 12357 - Ball Stacking
Category : DP
point : change your vision !!
Comlexity : O(N^2) //Number of balls
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
#define MAX 1002

typedef vector<int> vi;

int a[MAX][MAX],up[MAX][MAX],down[MAX][MAX];

void printup(int N)
{
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=i;j++)
			cout<<up[i][j]<<" ";
		cout<<endl;
	}
}

int main ()
{

	int N,ans;
	while (cin>>N,N!=0)
	{

		memset(up,0,sizeof(up));
		memset(down,0,sizeof(down));
		ans=0;

		for (int i=1;i<=N;i++)
			for (int j=1;j<=i;j++)
				cin>>a[i][j];

		//construct up aray
		
		for (int i=0;i<=N-1;i++)
			for (int j=1;j<=N-i;j++)
				up[j+i][j]=up[j+i-1][j-1]+a[j+i][j];

		//constructing down and find final answer
		for (int i=0;i<=N-1;i++)
			for (int j=N-i;j>=1;j--)
			{
				
				if (j+i+1>N || j+1>N)
					down[j+i][j]=(up[j+i][j]+down[j+i-1][j]);
				else
					down[j+i][j]=max(up[j+i][j]+down[j+i-1][j],down[j+i+1][j+1]);

				ans=max(ans,down[j+i][j]);
			}

		 cout<<ans<<endl;

	}

	return 0;
}