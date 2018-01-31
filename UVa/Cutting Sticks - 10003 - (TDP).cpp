									/*ba yade oo */
//AC Code
//Top Down Approches

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
#define MAX 60
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int t[MAX][MAX],pos[MAX];


int solve(int s,int e)
{
	if (s+1==e)return 0;
	if (t[s][e]!=-1)return t[s][e];
	int ans=INF;
	for (int i=s+1;i<e;i++){
		ans=min(ans,solve(s,i)+solve(i,e)+pos[e]-pos[s]);
	}

	return t[s][e]=ans;
}


int main ()
{
	
	int L,N;
	
	while (cin>>L,L){
		memset(t,-1,sizeof t);
		cin>>N;
		pos[0]=0;
		for (int i=1;i<=N;i++)
			cin>>pos[i];
		pos[N+1]=L;

		printf("The minimum cutting is %d.\n",solve(0,N+1));

	}
	

	return 0;
}
