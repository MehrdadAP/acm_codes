									/*ba yade oo */
//AC Code
//DP+bitmask (my first code :D)
//Congratulation Mehrdad :D


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


pii p[MAX];
vi ans,tmpAns;
int N,N2;
double mini;

double dist(int i,int j)
{
	double ret= ((p[i].first-p[j].first)*(p[i].first-p[j].first)) + ( (p[i].second-p[j].second)*(p[i].second-p[j].second) );
	ret=sqrt(ret);
	return ret;

}

double memo[300][10];
int nxt[300][10];

double solve(int pos,int bitmask)
{

	if ( bitmask==(int)pow(2.0,(double)N) )
	{nxt[bitmask][pos]=-1;return 0.0;}
	if (memo[bitmask][pos]!=-1.0) return memo[bitmask][pos];

	double ret=INF;
	int ansInd=-1;
	for (int i=0;i<N;i++)
		if ( (bitmask & (1<<i) ) == 0){
			//ret=min(ret,solve(i, (bitmask | (1<<i)) ) + dist(pos,i) );
			double x=solve(i, ( bitmask | (1<<i)))+dist(pos,i);
			if (x<ret)
			{ret=x;ansInd=i;}
		}
	if (ret==INF){ret=0;nxt[bitmask][pos]=-1;}
	nxt[bitmask][pos]=ansInd;
	return memo[bitmask][pos]=ret;

}



int main ()
{
	int TC=0;
	while (cin>>N,N){

		for (int i=0;i<N;i++)
			cin>>p[i].first>>p[i].second;

		double mini=INF;
		int ansInd=0;
		//memset(memo,-1.0,sizeof memo)

		for (int i=0;i<300;i++)for (int j=0;j<N;j++){memo[i][j]=-1.0;nxt[i][j]=-1;}

		for (int i=0;i<N;i++){

			//ans=min(ans,solve(i,0));
			double x=solve(i,1<<i);
			if (x<mini){
				mini=x;
				ansInd=i;
			}
		}		

		int k=ansInd,val=(1<<ansInd);
		ans.clear();
		ans.push_back(ansInd);
		
		while (ans.size()<N){
			k=nxt[val][k];
			ans.push_back(k);
			val=(val | (1<<k));
		}

		puts("**********************************************************");
		printf("Network #%d\n",++TC);

		double x,sum=0;
		for (int i=0;i<N-1;i++){
			x=dist(ans[i],ans[i+1])+16.0;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",p[ans[i]].first,p[ans[i]].second
												,p[ans[i+1]].first,p[ans[i+1]].second,x);
			sum+=x;
		}

		printf("Number of feet of cable required is %.2lf.\n",sum);
	}


	return 0;
}
