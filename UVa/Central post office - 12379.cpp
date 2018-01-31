									/*ba yade oo */

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
#define INF 0x7FFFFFFF
#define MAX 10002

typedef vector<int> vi;
vi adj[MAX];

int wnode;
bool visited[MAX];
int diam;
int dfs1(int v)
{
	visited[v]=true;
	int sz=adj[v].size();
	for (int i=0;i<sz;i++)
	{
		

	}


}


int BFS(int N)
{
	
}
int main ()
{

	int N,tc,M,v1,v2;
	cin>>tc;
	while (tc--)
	{
		cin>>N;
		for (int i=1;i<=N;i++)
		{
			adj[i].clear();
			cin>>M;
			for (int i=0;i<M;i++)
			{
				cin>>v1;
				adj[i].push_back(v1);
			}
		}



	}

	return 0;
}