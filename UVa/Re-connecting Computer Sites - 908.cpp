									/*ba yade oo */
//Mehrdad AP
//AC code
//just Kruskal
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
#define MAX 1000009
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;
typedef pair<int,pii> piii;

vector< piii > edge;

int N,M,K;
int par[MAX];


int findPar(int x)
{
	if (par[x]==x) return x;
	return (par[x]=findPar(par[x]));
}


int Kruskal()
{

	for (int i=1;i<=N;i++) par[i]=i;
	sort(edge.begin(),edge.end());

	int edgeCnt=0,ret=0;
	for (int i=0;i<M+K && edgeCnt<N-1;i++){

		int x=findPar(edge[i].second.first);
		int y=findPar(edge[i].second.second);

		if (x==y) continue;
		par[x]=y;

		ret+=edge[i].first;
		edgeCnt++;
	}

	return ret;
}

int main ()
{
	int x,y,c,TC=0;
	while (cin>>N){

		if (TC!=0)cout<<endl;
		++TC;
		edge.clear();

		int prevSum=0;
		for (int i=0;i<N-1;i++){
			cin>>x>>y>>c;
			prevSum+=c;
		}

		cin>>K;
		for (int i=0;i<K;i++){
			cin>>x>>y>>c;
			edge.push_back( piii(c,pii(x,y)) );
		}
		
		cin>>M;
		for (int i=0;i<M;i++){
			cin>>x>>y>>c;
			edge.push_back( piii(c,pii(x,y)) );
		}

		cout<<prevSum<<endl;
		cout<<Kruskal()<<endl;
	}


	return 0;
}
