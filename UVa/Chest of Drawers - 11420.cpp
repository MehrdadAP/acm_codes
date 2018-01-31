									/*ba yade oo */
//AC Code
//DP
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
#define MAX 70
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;


lli memo[MAX][MAX][2];
int N,S;

lli solve(int i,int k,int prevLock)//prevLock==1 -> true O.W 0
{
	if (i==N-1){

		if (k==1) return 1;
		else if (k>1) return 0;
		else if (k==0) return (prevLock==1 ? 0 : 1);
		else return 1;
	}

	if (memo[i][k][prevLock]!=-1) return memo[i][k][prevLock];

	lli ret=0;

	if (k>=0) ret+=solve(i+1,k-1,1);

	if (prevLock==1) ret+=solve(i+1,k+1,0);
	else ret+=solve(i+1,k,0);


	return memo[i][k][prevLock]=ret;
}



int main ()
{

	while (cin>>N>>S){
		if (N<0 && S<0)break;
		//intead of memset !
		for (int i=0;i<MAX;i++)for (int j=0;j<MAX;j++) for (int k=0;k<2;k++)memo[i][j][k]=-1;
		if (N==1){
			if (S<=1) cout<<1<<endl;
			else cout<<0<<endl;
		}
		else
		cout<<solve(1,S,0)+solve(1,S-1,1)<<endl;
	}

	return 0;
}
