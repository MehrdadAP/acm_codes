									/*ba yade oo */

//AC Code
//Backtrack

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
#define MAX 20009
#define MODE 1000000007

typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;

int N=1025,d;
#define inRange(x,y) (x>=0 && x<N && y>=0 && y<N )

lli kill[1026][1026];
pair< pii,int> rats[MAX];

int dx[]={-1,-1,-1,0,0,+1,+1,+1};
int dy[]={-1,0,1,-1,+1,-1,0,+1};


void calcKill(int x,int y,int val)
{

	for (int i=x-d;i<=x+d;i++)
		for (int j=y-d;j<=y+d;j++){
			if (inRange(i,j))
				kill[i][j]+=val;	
		}
}

int main ()
{

	int tc,M;
	cin>>tc;

	while (tc--)
	{
		memset(kill,0,sizeof kill);
		cin>>d;
		cin>>M;

		for (int i=0;i<M;i++)
		{
			cin>>rats[i].first.first>>rats[i].first.second>>rats[i].second;
			calcKill(rats[i].first.first,rats[i].first.second,rats[i].second);
		}

		int ax=0,ay=0;

		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
			{
				if (kill[i][j]>kill[ax][ay]){
					ax=i;ay=j;
				}
			}

		printf("%d %d %lld\n",ax,ay,kill[ax][ay]);
	}


	return 0;
}
