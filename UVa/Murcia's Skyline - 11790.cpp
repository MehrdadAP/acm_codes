									/*ba yade oo */
//AC Code
/*
DP
IMPORTANT:
in this problem normal Topdown approache doesn't work
eg: {1,2,3,5} --> LIS[4] doesnt call previous index

so in some problems we must use bottom up method other than topdown



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
#define INF 100000000
#define MAX 10000
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int lis[MAX],lds[MAX],N;
int h[MAX],w[MAX];
int ans1,ans2;


//this recc method sucks !

int solve(int i,int flag)
{
	if (i==0)return 0;
	if (flag && lis[i]!=-1)return lis[i];
	else if (!flag && lds[i]!=-1)return lds[i];


	lis[i]=lds[i]=w[i];
	for (int k=i-1;k>=1;k--){
		if (h[i]>h[k])lis[i]=max(lis[i],solve(k,true)+w[i]);
		else if (h[i]<h[k])lds[i]=max(lds[i],solve(k,false)+w[i]);

	}

	ans1=max(ans1,lis[i]);
	ans2=max(ans2,lds[i]);
	if (flag)return lis[i];
	else return lds[i];

}



int main ()
{
	int tc;
	cin>>tc;
	int TC=0;
	while (tc--){
		cin>>N;
		for (int i=1;i<=N;i++)cin>>h[i];
		for (int i=1;i<=N;i++)cin>>w[i];
		
		memset(lis,-1,sizeof lis);
		memset(lds,-1,sizeof lds);

		//ans1=ans2=*max_element(w+1,w+N+1);
		//solve(N,true);

		//bottom-up
		lis[0]=lds[0]=0;
		ans1=ans2=0;
		for (int i=1;i<=N;i++){
			lis[i]=lds[i]=w[i];
			for (int k=1;k<i;k++){
				if (h[i]>h[k])lis[i]=max(lis[i],lis[k]+w[i]);
				if (h[i]<h[k])lds[i]=max(lds[i],lds[k]+w[i]);	
			}

			ans1=max(ans1,lis[i]);
			ans2=max(ans2,lds[i]);
		}
		
		if (ans1>=ans2)
			printf("Case %d. Increasing (%d). Decreasing (%d).\n",++TC,ans1,ans2);
		else printf("Case %d. Decreasing (%d). Increasing (%d).\n",++TC,ans2,ans1);
	}
	

	return 0;
}
