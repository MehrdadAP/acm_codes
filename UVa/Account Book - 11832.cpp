									/*ba yade oo */
//AC Code
/*
so important and nice problem for me :)

it's my first pure TDP code and thinking :)
SHIFT trick was also so new and good , like it ;)

it's refere to progressive !

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
#define MAX 16000*2+100
#define MODE 1000000007
#define SHIFT 16000

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int memo[MAX][50];
int state[MAX],val[MAX];

bool solve(int sum,int i)
{
	if (sum+SHIFT>16000*2) return false;
	if (sum+SHIFT<0) return false;
	if (i<0) return (sum==0);

	if (memo[sum+SHIFT][i]!=-1) return memo[sum+SHIFT][i];

	bool t1=solve(sum-val[i],i-1);
	bool t2=solve(sum+val[i],i-1);

	if (t1 && (state[i]==-1 || state[i]==0))state[i]=0;
	else if (t1) state[i]=1;

	if (t2 && (state[i]==1 || state[i]==0))state[i]=0;
	else if (t2) state[i]=-1;

	return memo[sum+SHIFT][i]=(t1 || t2);
}

inline char whichState(int i)
{
	if (state[i]==0)return '?';
	if (state[i]==1)return '+';
	if (state[i]==-1)return '-';
}

int main ()
{

	int N,F;
	while (cin>>N>>F, N || F){

		for (int i=0;i<N;i++) cin>>val[i];

		memset(state,-10,sizeof state);
		memset(memo,-1,sizeof memo);

		if (solve(F,N-1)==false){cout<<"*\n";continue;}

		for (int i=0;i<N;i++)
			printf("%c",whichState(i));
		cout<<endl;
	}

	return 0;
}
