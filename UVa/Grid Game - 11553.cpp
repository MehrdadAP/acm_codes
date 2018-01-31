									/*ba yade oo */
//AC Code

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
#define MAX 10
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int row[MAX],col[MAX];
int mat[MAX][MAX];
int t[MAX][MAX],N;

int ans;
bool visited[MAX];

void BT(int j,int sum)
{
	if (j==N+1){

		ans=min(ans,sum);
		return;
	}

	for (int i=1;i<=N;i++)
		if (visited[i]==false)
		{
			visited[i]=true;
			BT(j+1,sum+mat[i][j]);
			visited[i]=false;
		}

}

int main ()
{


	int tc;
	cin>>tc;

	

	while (tc--)
	{
		cin>>N;
		memset(t,0,sizeof t);
		memset(visited,false,sizeof visited);

		for (int i=1;i<=N;i++)
		{
			row[i]=col[i]=i;
			for (int j=1;j<=N;j++)
				cin>>mat[i][j];
		}
		
		ans=INF;

		BT(1,0);
		cout<<ans<<endl;

		
		//int ans=INF,tmp;
		//do
		//{
		//	do
		//	{
		//		tmp=0;
		//		for (int i=0;i<N;i++)
		//			tmp+=mat[row[i]][col[i]];
		//			
		//		ans=min(ans,tmp);

		//	}while (next_permutation(col,col+N));


		//}while (next_permutation(row,row+N));
		

	}
	

	return 0;
}
