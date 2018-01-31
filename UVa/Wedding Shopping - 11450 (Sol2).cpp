									/*ba yade oo */
//AC code
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
#define MAX 210
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int t[22][MAX];
vi p[30];

int main ()
{
	int tc,M,C,K,x;
	cin>>tc;
	while (tc--){
		cin>>M>>C;

		for (int i=1;i<=C;i++){
			cin>>K;
			p[i].clear();
			for (int k=0;k<K;k++){
				cin>>x;
				p[i].push_back(x);
			}
		}

		memset(t,-1,sizeof t);
		for (int i=0;i<=M;i++)t[0][i]=0;
		bool NO=false;

		for (int i=1;i<=C && !NO;i++){
			for (int j=1;j<=M;j++){
				for (int k=0;k<p[i].size();k++){
					if (j-p[i][k]>=0 && t[i-1][j-p[i][k]]!=-1)
						t[i][j]=max(t[i][j],t[i-1][j-p[i][k]]+p[i][k]);
				}
			}
		}

		if (t[C][M]==-1)puts("no solution");
		else cout<<t[C][M]<<endl;
	}
	

	return 0;
}
