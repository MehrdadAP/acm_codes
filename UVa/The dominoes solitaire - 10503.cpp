									/*ba yade oo */
//AC COde
/*
BT and check ->Sol 1
check2 -> Sol2


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
#define MAX 20
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

pii dom[MAX];
bool state[MAX],YES;
int M,N;
bool visited[MAX];
pii space[MAX];

void check2(int i)
{
	if (i==N+1)YES=true;
	if(YES)return;

	for (int j=1;j<=M;j++)
		if (visited[j]==false){
			if (dom[j].first==space[i-1].second )
			{
				if (i==N && dom[j].second!=space[N+1].first)continue;

				space[i].first=dom[j].first;
				space[i].second=dom[j].second;

				visited[j]=true;
				check2(i+1);
				visited[j]=false;
			}
			else if (dom[j].second==space[i-1].second)
			{
				if (i==N && dom[j].first!=space[N+1].first)continue;

				space[i].first=dom[j].second;
				space[i].second=dom[j].first;

				visited[j]=true;
				check2(i+1);
				visited[j]=false;
			}
		}


}



void check(int i)
{
	if (i==N+1)YES=true;
	if(YES)return;

	for (int j=1;j<=M;j++)
		if (visited[j]==false){
			
			if ( (state[j]==true && dom[j].first==space[i-1].second) )
			{
				if (i==N && dom[j].second!=space[N+1].first)continue;

				space[i].first=dom[j].first;
				space[i].second=dom[j].second;

				visited[j]=true;
				check(i+1);
				visited[j]=false;
			}
			else if (state[j]==false && dom[j].second==space[i-1].second)
			{
				if (i==N && dom[j].first!=space[N+1].first)continue;

				space[i].first=dom[j].second;
				space[i].second=dom[j].first;

				visited[j]=true;
				check(i+1);
				visited[j]=false;
			}
		}


}

void BT(int i)
{
	if (YES)return;
	if (i==M+1){
		check(1);
		return;
	}

	state[i]=true;
	BT(i+1);
	state[i]=false;
	BT(i+1);

}



int main ()
{

	while (cin>>N,N)
	{
		YES=false;
		memset(visited,false,sizeof visited);

		cin>>M;
		cin>>space[0].first>>space[0].second;
		cin>>space[N+1].first>>space[N+1].second;

		for (int i=1;i<=M;i++)
			cin>>dom[i].first>>dom[i].second;

		 //BT(1);
		 check2(1);
		 if (YES) puts("YES");
		 else puts("NO");

	}
	

	return 0;
}
