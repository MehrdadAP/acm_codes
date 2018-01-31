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
#define MAX 5700

typedef vector<int> vi;

int t[MAX],tol[MAX],w[MAX],s[MAX];

bool comp(int x,int y)
{
	return x>y;
}

int main ()
{
	int w1,s1;
	int k=1;
	while (cin>>w1>>s1)
	{
		w[k]=w1;
		s[k]=s1-w1;
		k++;
	}
	int N=k-1;
	sort(s+1,s+N+1,comp);

	t[1]=1;
	tol[1]=s[1];
	int ans=0;
	for (int i=2;i<=N;i++)
	{
		t[i]=1;tol[i]=s[i];
		for (int j=1;j<i;j++)
			if (w[i]<=tol[j] && t[j]+1>t[i])
			{
				t[i]=t[j]+1;
				tol[i]=min(tol[j]-w[i],tol[i]);
			}
		ans=max(ans,t[i]);
	}

	cout<<ans<<endl;
	//cin>>N;//for stop to see
	return 0;
}