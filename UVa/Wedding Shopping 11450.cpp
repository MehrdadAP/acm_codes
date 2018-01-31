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
#include <map>



using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 0x7FFFFFFF
#define MAXC 220
#define MAXK 22

typedef vector<int> vi;

int t[MAXC][MAXK][MAXK];
int a[MAXK][MAXK];

int main ()
{
	int tc,M,C,K;
	cin>>tc;
	while (tc--)
	{
		cin>>M>>C;
		for (int i=1;i<=C;i++)
		{
			cin>>K;
			a[i][0]=K;
			for (int j=1;j<=K;j++)
				cin>>a[i][j];
		}

		memset(t,-1,sizeof(t));
		for (int i=0;i<22;i++)
			t[i][0][0]=0;
		
		int ans=0;
		for (int i=1;i<=M;i++)
			for (int j=1;j<=C;j++)
			{
				for (int k=1;k<=a[j][0];k++)
				{
					if (i-a[j][k]>=0)
					{
						int tmp=0;
						for (int s=1;s<=a[j-1][0];s++)
							tmp=max(tmp,t[i-a[j][k]][j-1][s]);
						if (tmp!=0 || j==1)
							t[i][j][k]=tmp+a[j][k];
						
					}

					if (j==C)
						ans=max(t[i][j][k],ans);
				}
			}

		if (ans)
			cout<<ans<<endl;
		else
			cout<<"no solution\n";

	}

	return 0;
}