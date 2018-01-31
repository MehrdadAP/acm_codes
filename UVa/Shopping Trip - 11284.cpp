									/*ba yade oo */
//AC Code
/*
Floyd + TSP

note:
when having double values in problem, and specially double comparison
MUST use EPS, i have lots of time on this problem and just for use EPS :D


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
#define MAX 60
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

double g[MAX][MAX],val[15];
int store[15];
int N,M,P;
double memo[15][8200];

double solve(int pos,int bitmask)
{
	
	if (memo[pos][bitmask]!=-1.0) return memo[pos][bitmask];


	double ret=g[ store[pos] ][0];

	for (int i=1;i<=P;i++){
		int x=store[pos];//real num of store	

		if ( (bitmask & (1<<i)) == 0 )
			ret=min( ret , solve( i,bitmask | (1<<i) ) + g[x][store[i]] + val[i]);

	}

	return memo[pos][bitmask]=ret;

}



int main ()
{

	int tc,v1,v2;
	double c1;

	cin>>tc;

	while (tc--){
		cin>>N>>M;
		for (int i=0;i<=N;i++)for (int j=0;j<=N;j++)g[i][j]=1000000000.0;

		for (int i=0;i<M;i++){
			cin>>v1>>v2>>c1;
			g[v1][v2]=min(c1,g[v1][v2]);
			g[v2][v1]=min(c1,g[v2][v1]);
		}

		cin>>P;
		store[0]=val[0]=0;
		for (int i=1;i<=P;i++){
			cin>>v1>>c1;
			val[i]=-c1;
			store[i]=v1;
		}
		
		for (int i=0;i<=N;i++)g[i][i]=0.0;
		
		//floyd
		for (int k=0;k<=N;k++)
			for (int i=0;i<=N;i++)
				for (int j=0;j<=N;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);


		for (int i=0;i<15;i++)for (int j=0;j<8200;j++)memo[i][j]=-1.0;

		double ans=-1.0*solve(0,1);
		if (ans>EPS) printf("Daniel can save $%.2lf\n",ans);
		else puts("Don't leave the house");
		

	}

	return 0;
}

