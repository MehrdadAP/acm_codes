									/*ba yade oo */
//AC Code
//Classic DP
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
#define MAX 20
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

lli memo[MAX][MAX];
int X[MAX],Y[MAX],par[MAX][MAX];

lli solve(int i,int j)
{

	if (j-i==1) {par[i][j]=i;return (lli)(X[i]*Y[i]*Y[j]);}
	if (i==j)return 0;

	if (memo[i][j]!=-1) return memo[i][j];

	int ansInd;
	lli ret=2000000000;
	for (int k=i;k<j;k++){
		lli x=solve(i,k)+solve(k+1,j)+X[i]*Y[k]*Y[j];
		if (x<ret){
			ret=x;
			ansInd=k;
		}
	}

	par[i][j]=ansInd;
	return memo[i][j]=ret;

}

void printSol(int i,int j)
{
	if (i==j) {cout<<"A"<<i;return;}

	cout << "(";
	printSol(i,par[i][j]);
	cout<<" x ";
	printSol(par[i][j]+1,j);
	cout<<")";
}

int main ()
{


	int N,TC=0;
	while (cin>>N,N){
		for (int i=1;i<=N;i++) cin>> X[i] >> Y[i];

		memset(memo,-1,sizeof memo);
		memset(par,-1,sizeof par);

		solve(1,N);
		printf("Case %d: ",++TC);
		printSol(1,N);
		cout<<endl;
	}
	

	return 0;
}
