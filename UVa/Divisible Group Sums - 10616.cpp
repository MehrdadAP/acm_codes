									/*ba yade oo */
//RE !
//... Shahriar !
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
#define MAX 220
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

lli t[MAX*20][MAX][15];
int num[MAX],tnum[MAX];

lli memo[25][MAX][12];



//int mod(int a,int b)
//{
//    int c;
//
//    if(a<b)
//    {
//        a=-a;
//        c=a%b;
//        c=b-c;
//    }
//    else
//        c=a;
//    return c%b;
//}

int mod(int n,int m)
{
    if(n<0)
        n+=(ceil(-n*1.00/m)*m);
    return n%m;
}

//lli solve(int sum,int j,int m)
//{
//	if (sum==0 && (m==0 || j==0) )return 1;
//	if (memo[sum][j][m]!=-1)return memo[sum][j][m];
//
//}

int main ()
{

	int N,sum,Q,D,M,TC=0;
	//int i,j,k;
	while (cin>>N>>Q, N || Q){
		
		sum=0;
		for (int i=1;i<=N;i++) cin>>num[i];

		printf("SET %d:\n",++TC);
		for (int q=1;q<=Q;q++){
			cin>>D>>M;

			for (int i=1;i<=N;i++){
				tnum[i]=mod(num[i],D);
				/*tnum[i]=num[i]%D;
				if (tnum[i]<0)tnum[i]+=D;*/
				sum+=tnum[i];
			}

			memset(t,0,sizeof t);
			for (int i=0;i<=N;i++)t[0][i][0]=1;

			for (int i=0;i<=sum;i++)
				for (int j=1;j<=N;j++)
					for (int k=1;k<=M;k++)
						if (i-tnum[j]>=0) t[i][j][k]=t[i][j-1][k]+t[i-tnum[j]][j-1][k-1];
						else t[i][j][k]=t[i][j-1][k];			

			lli ans=0;
			for (int i=0;i<=sum;i++){
				if (i%D==0)ans+=t[i][N][M];
			}
		
			printf("QUERY %d: %lld\n",q,ans);
		}
	}

	return 0;
}
