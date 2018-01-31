									/*ba yade oo */
//AC Code
/*
Fantastic Problem 

i can just solve this by TDP
very nice solution too:D

also it's have a nice testcase by Adrian Kuegel:
1900 3
2000 5
1950 1
101 1

ans = 2

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
#define MAX 10000+290
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;


int memo[MAX][110],t[MAX][110],g[MAX][110];
int p[110],f[110];
int M,N,M2;

int solve(int m,int i)
{
	if (m<0)return -INF;
	if (i==N+1){
		int diff=M+200-m;
		if (diff>M && diff<=2000)return -INF;
		else return 0;
	}

	if (memo[m][i]!=-1)return memo[m][i];

	return memo[m][i]=max ( solve(m,i+1) , solve(m-p[i],i+1) +f[i] );
	
}



int main ()
{

	
	while (cin>>M>>N){
		for (int i=1;i<=N;i++) cin>>p[i]>>f[i];
		
		if (M+200>2000)M2=M+200;
		else M2=M;
		memset(memo,-1,sizeof memo);
		cout<< solve(M+200,1)<<endl;


		//for (int i=0;i<=N;i++){t[0][i]=0;g[0][i]=0;}

	/*	for (int i=1;i<=M2;i++)
			for (int j=1;j<=N;j++){
				else if (i-p[j]>=0 && t[i-p[j]][j-1]+f[j]>t[i][j-1])
					{t[i][j]=t[i-p[j]][j-1]+f[j];g[i][j]=g[i-p[j]][j-1]+p[j];}
				else {t[i][j]=t[i][j-1];g[i][j]=g[i][j-1];}
			}
*/
		
		//int ansInd=M;
		//if (M+200>2000){
		//	/*for (int i=M+200;i>M;i--)
		//		if (t[i][N]>t[ansInd][N] && g[i][N]>2000)ansInd=M;*/

		//	cout<<t[M2][N]<<endl;
		//}
		//else cout<<t[M][N]<<endl;	
		////cout<<t[M][N]<<" "<<g[M][N]<<endl;

	}
		

	return 0;
}
