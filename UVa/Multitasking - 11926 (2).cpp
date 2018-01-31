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
#define INF 100000000
#define MAX 1000000*3+10
#define MODE 1000000007

#define Left(i) ( 2*i )
#define Right(i) ( 2*i+1 )

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

vector<pii> p;
bool Conflict;
int t[MAX],lazyUpd[MAX];

int isEdge[MAX];

void doUpdate(int L,int R,int root)
{
	if (lazyUpd[root]==0)return;

	t[root]+=lazyUpd[root]*(R-L+1);
	lazyUpd[root]=0;

	if (t[root]>(R-L+1))Conflict=true;
}

void check(int L,int R,int root)
{
	if(Conflict)return;
	R=min(R,1000000);

	doUpdate(L,R,root);
	int mid=(L+R)/2;
	doUpdate(L,mid,Left(root));
	doUpdate(mid+1,R,Right(root));
}


void update(int i,int j,int L,int R,int root)
{
	if(Conflict)return;
	R=min(R,1000000);

	if (i>R || j<L)return;

	if (L==R){
		if (i==L || j==L)
			if (isEdge[L]!=0){
				isEdge[L]=1;
				doUpdate(L,R,root);
				return;
			}
		isEdge[L]=0;
	}

	if (i<=L && j>=R){
		lazyUpd[root]++;
		lazyUpd[Left(root)]++;
		lazyUpd[Right(root)]++;

		doUpdate(L,R,root);
		return;
	}

	doUpdate(L,R,root);

	int mid=(L+R)/2;
	update(i,j,L,mid,Left(root));
	update(i,j,mid+1,R,Right(root));

	t[root]=t[Left(root)]+t[Right(root)];
	if (t[root]>(R-L+1))
		Conflict=true;
	return;
}

int main ()
{

	int N,M,x,y,r;
	int sz=1000000;
	while (cin>>N>>M, N || M){
		memset(t,0,sizeof t);
		memset(lazyUpd,0,sizeof lazyUpd);
		memset(isEdge,-1,sizeof isEdge);

		Conflict=false;

		for (int i=0;i<N;i++){
			cin>>x>>y;
			update(x,y,0,sz,1);
		}
		for (int i=0;i<M;i++){
			cin>>x>>y>>r;
			while (x<=sz){
				update(x,y,0,sz,1);
				x+=r;
				y+=r;
			}
		}
		check(0,sz,1);
		if (Conflict)puts("CONFLICT");
		else puts("NO CONFLICT");

	}

	return 0;
}
