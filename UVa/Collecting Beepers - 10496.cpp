									/*ba yade oo */
//AC Code
//DP + Bitmask , TSP
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

pii p[15];
int memo[15][2000];
int N,N2;

int dist(int i,int j)
{
	return absol((p[i].first-p[j].first)) + absol((p[i].second-p[j].second));
}


int solve(int pos,int bitmask)
{
	if (bitmask==N2)return dist(pos,0); // N2= 0011..11
	
	if(memo[pos][bitmask]!=-1)return memo[pos][bitmask];

	int ret=INF;
	for (int i=1;i<=N;i++)
		if ( ( bitmask & (1<<i) ) == 0 )
			ret=min(ret, solve(i,bitmask | (1<<i)) + dist(pos,i) );

	return memo[pos][bitmask]=ret;
}



int main ()
{

	int tc,X,Y;
	cin>>tc;
	while (tc--){
		cin>>X>>Y;
		cin>>p[0].first>>p[0].second;

		cin>>N;
		N2=2;
		for (int i=1;i<=N;i++){
			cin>>p[i].first>>p[i].second;
			N2*=2;
		}
		N2--;

		memset(memo,-1,sizeof memo);
		printf("The shortest path has length %d\n",solve(0,1));


	}

	return 0;
}
