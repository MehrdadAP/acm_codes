									/*ba yade oo */

/*
AC Code

Problem : UVA - 11456 - Trainsorting 
Category : DP
Hint : calc for each item LIS & LDS from its item upto end
Complexity : O(N)


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
#define MAX 2002

typedef vector<int> vi;

int LIS[MAX],LDS[MAX],a[MAX];

int main ()
{

	int tc,N,ans;
	scanf("%d",&tc);
	while (tc--)
	{
		scanf("%d",&N);
		for (int i=0;i<N;i++)scanf("%d",&a[i]);

		ans=0;

		for (int i=N-1;i>=0;i--)
		{
			LDS[i]=LIS[i]=1;
			for (int j=N-1;j>i;j--)
			{
				if (a[i]<a[j])
					LIS[i]=max(LIS[i],LIS[j]+1);
				else
					LDS[i]=max(LDS[i],LDS[j]+1);
			}
			ans=max(ans,LIS[i]+LDS[i]);
		}
		if (N!=0) printf("%d\n",ans-1);
		else puts("0");
	}

	return 0;
}