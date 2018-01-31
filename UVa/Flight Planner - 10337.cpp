									/*ba yade oo */
//AC Code
//just DP ;)

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
#define MAX 1010
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int memo[12][MAX],mat[12][MAX],par[12][MAX];

int calcAltDis(int i,int j)
{
	if (j-i==0)return 30;
	else if (j>i)return (j-i)*20;
	else return (i-j)*60;
}

int solve(int alt,int pos)
{
	if (pos==1){
		return calcAltDis(alt,0)-mat[0][0]-mat[alt][pos];
	}

	if (memo[alt][pos]!=-1) return  memo[alt][pos];

	int ret=INF,ansInd;
	for (int i=1;i<10;i++){
		ret=min(ret , solve(i,pos-1)-mat[alt][pos] + calcAltDis(alt,i) );
	}
	return memo[alt][pos]=ret;
}




int main ()
{

	int tc,N,P;
	cin>>tc;
	
	while (tc--){
		cin>>N;

		P=N/100;
		for (int i=9;i>=0;i--){
			for (int j=0;j<P;j++)
				cin>>mat[i][j];
		}
		mat[0][P]=0;
		memset(memo,-1,sizeof memo);

		cout<<solve(0,P)<<endl<<endl;
	}

	return 0;
}
