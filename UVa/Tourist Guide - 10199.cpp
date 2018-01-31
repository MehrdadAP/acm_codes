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
#define MAX 130


map<string,int> mp;
string mp2[MAX];
vector<int> adj[MAX];

int lowNum[MAX],dfsNum[MAX];
vector<string> cutVertex;
int dfsCnt,dfsRoot;
bool visited[MAX],isCutVertex[MAX];


void DFS(int v,int parent)
{

	visited[v]=true;
	dfsNum[v]=lowNum[v]=dfsCnt++;
	int sz=adj[v].size();
	int childs=0;
	for (int i=0;i<sz;i++)
	{
		int curr=adj[v][i];
		if (visited[curr]==false)
		{
			DFS(curr,v);

			if (lowNum[curr]<lowNum[v])
				lowNum[v]=lowNum[curr];

			if (v==dfsRoot)
				childs++;
			else if (dfsNum[v]<=lowNum[curr])
				isCutVertex[v]=true;
		}
		else if (curr!=parent)
			lowNum[v]=min(dfsNum[v],dfsNum[curr]);
	}

	if (v==dfsRoot && childs>1)
		isCutVertex[v]=true;

	if (isCutVertex[v]==true)
		cutVertex.push_back(mp2[v]);

}

int main ()
{

	int N,E,v1,v2,TC;
	char s1[100],s2[100];
	TC=0;
	cin>>N;
	while (N)
	{
		mp.clear();
		cutVertex.clear();
		memset(visited,false,sizeof(visited));
		memset(isCutVertex,false,sizeof(isCutVertex));

		for (int i=0;i<N;i++)
		{
			adj[i].clear();
			cin>>s1;
			mp[s1]=i;
			mp2[i]=s1;
		}

		cin>>E;
		for (int i=0;i<E;i++)
		{
			cin>>s1>>s2;
			v1=mp[s1];v2=mp[s2];
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}

		for (int i=0;i<N;i++)
			if (visited[i]==false)
			{
				dfsRoot=i;
				DFS(i,i);
			}

		printf("City map #%d: %d camera(s) found\n",++TC,cutVertex.size());

		sort(cutVertex.begin(),cutVertex.end());

		for (int i=0;i<cutVertex.size();i++)
		{
			cout<<cutVertex[i]<<endl;
		}

		cin>>N;
		if (N)
			cout<<endl;
	}


	return 0;

}