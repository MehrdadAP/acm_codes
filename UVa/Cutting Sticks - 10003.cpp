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
#define MAX 70

typedef vector<int> vi;

int t[MAX][MAX];
int a[MAX];
int main ()
{

	int L,N,tmp;
	while (cin>>L, L!=0)
	{
		cin>>N;
		a[0]=0;
		for (int i=1;i<=N;i++)
			cin>>a[i];
		a[N+1]=L;

		sort(a+1,a+N+1);
		memset(t,0,sizeof(t));

		for (int k=2;k<=N+1;k++)
			for (int i=0;i<=N;i++)
			{
				t[i][i+k]=a[i+k]-a[i];
				tmp=INF;
				for (int s=i+1;s<i+k;s++)
					tmp=min(tmp,t[i][s]+t[s][i+k]);
				t[i][i+k]+=tmp;
			}

		printf("The minimum cutting is %d.\n",t[0][N+1]);

	}

	return 0;
}