									/*ba yade oo */
/*
AC Code

Problem : UVA - 11341 - Term Strategy 
Category : DP
Complexity : O(N*M^3)
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
#define EPS 1e-9
#define INF 0x7FFFFFFF
#define MAXN 14
#define MAXM 120

typedef vector<int> vi;

int t[MAXM][MAXN][MAXM];
int a[MAXN][MAXM];

int main ()
{
	int tc,M,C,K,N;
	cin>>tc;
	while (tc--)
	{
		cin>>N>>M;
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=M;j++)
				cin>>a[i][j];
		}

		memset(t,-1,sizeof(t));
	
		int ans=0;
		for (int i=1;i<=M;i++)
			for (int j=1;j<=N;j++)
			{
				for (int k=1;k<=M;k++)
				{
					int tmp=0;
					if (a[j][k]<5)continue;

					if (j==1)
					{
						t[i][j][k]=(i-k>=0)? a[j][k]:-1;
					}
					else
					{
						for (int s=1;s<=M;s++)
						{
							if (i-k>0)
								tmp=max(tmp,t[i-k][j-1][s]);
						}
						if (tmp!=0)t[i][j][k]=(tmp+a[j][k]);
					}

					if (j==N)
						ans=max(ans,t[i][j][k]);
				}

			}

		if (ans)
			printf("Maximal possible average mark - %.2lf.\n",(ans/(double)N)+EPS);
		else
			printf("Peter, you shouldn't have played billiard that much.\n");

	}

	return 0;
}