									/*ba yade oo */


//AC
//just count number of Bridges


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


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 0x7FFFFFFF
#define MAX 2000

set<int> adjSet[MAX];
vector<int> adj[MAX];
int lowNum[MAX],dfsNum[MAX],dfsCnt;
bool visited[MAX];
typedef pair<int,int> ii;

vector<ii> bridges;

void DFS(int v,int parent)
{
	visited[v]=true;
	lowNum[v]=dfsNum[v]=dfsCnt++;
	int sz=adj[v].size();

	for (int i=0;i<sz;i++)
	{
		int curr=adj[v][i];
		if (visited[curr]==false)
		{
			
			DFS(curr,v);
			if(lowNum[v]>lowNum[curr])
				lowNum[v]=lowNum[curr];
			
			if(lowNum[curr]>dfsNum[v])
				bridges.push_back(ii(min(v,curr),max(v,curr)));
		}
		else if (curr!=parent)
			lowNum[v]=min(lowNum[v],dfsNum[curr]);
	}
}


int main ()
{
	int tc,N,v1,v2,i,temp;
	char s[9000];
	char ch;
	while(cin>>N)
	{
		int sz;
		for (int i=0;i<N;i++)
		{
			adj[i].clear();
			adjSet[i].clear();
		}

		for (int i=0;i<N;i++)
		{
			cin>>v1;
			cin>>ch;
			cin>>sz;
			cin>>ch;
			while(sz--)
			{
				cin>>v2;
				if (adjSet[v1].find(v2)!=adjSet[v1].end()) continue;
				adj[v1].push_back(v2);
				adj[v2].push_back(v1);

				adjSet[v1].insert(v2);
				adjSet[v2].insert(v1);
			}
		}


		int ans=0;
		memset(visited,false,sizeof(visited));
		bridges.clear();
		dfsCnt=0;
		for (int i=0;i<N;i++)
			if (visited[i]==false)
			{
				dfsCnt=0;
				DFS(i,i);
			}
		
		sz=bridges.size();
		printf("%d critical links\n",sz);
		sort(bridges.begin(),bridges.end());


		for (int i=0;i<sz;i++)
			printf("%d - %d\n",bridges[i].first,bridges[i].second);

		printf("\n");
	}


	return 0;

}

