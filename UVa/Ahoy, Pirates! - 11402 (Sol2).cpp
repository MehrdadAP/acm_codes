									/*ba yade oo */
//AC Code after 2 Days submissions and Q & A!
//one of the most challenging problem till now in summer 2012 :D
//I learn much about lazy propagation , so good tools for SG
//http://wcipeg.com/wiki/Segment_tree

//i want to thanks my parent who help me to be "here" :D:D

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
#define MAX 1024000*3+10
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;
#define Left(i) (2*i)
#define Right(i) (2*i+1)

int buc[MAX],lazyUpd[MAX];
string s;
char str[MAX];

void buildSeg(int L,int R,int root)
{
	if (L==R){
		buc[root]=(s[L]=='1');
		lazyUpd[root]=-1;
		return;
	}

	int mid=(L+R)/2;
	
	buildSeg(L,mid,Left(root));
	buildSeg(mid+1,R,Right(root));

	buc[root]=buc[Left(root)]+buc[Right(root)];
	lazyUpd[root]=-1;
	return;
}

void setFlag(int root,int state)
{
	if (state!=2)
		lazyUpd[root]=state;
	else{
		if (lazyUpd[root]==-1)		lazyUpd[root]=2;
		else if (lazyUpd[root]==0)	lazyUpd[root]=1;
		else if (lazyUpd[root]==1)	lazyUpd[root]=0;
		else if (lazyUpd[root]==2)	lazyUpd[root]=-1;
	}

}

void doUpdate(int L,int R,int root,int state)
{
	if (lazyUpd[root]==-1)return;

	if (state==1){
		buc[root]=(R-L+1);
		lazyUpd[root]=-1;
		setFlag(Left(root),state);
		setFlag(Right(root),state);
	}
	if (state==0){
		buc[root]=0;
		lazyUpd[root]=-1;
		setFlag(Left(root),state);
		setFlag(Right(root),state);
	}
	if (state==2){
		buc[root]=(R-L+1)-buc[root];
		lazyUpd[root]=-1;
		setFlag(Left(root),state);
		setFlag(Right(root),state);
	}
	
	return;
}

int getRange(int i,int j,int L,int R,int root)
{
	doUpdate(L,R,root,lazyUpd[root]);

	if (i>R || j<L)return 0;
	
	if (i<=L && j>=R) return buc[root];
	
	int mid=(L+R)/2;
	int ret = getRange(i,j,L,mid,Left(root)) + getRange(i,j,mid+1,R,Right(root));

	buc[root]=buc[Left(root)]+buc[Right(root)];
	
	return ret;
}

void mutate(int i,int j,int L,int R,int root,int state)
{
	
	if (i<=L && j>=R){
		setFlag(root,state);
		doUpdate(L,R,root,lazyUpd[root]);
		return;
	}
	doUpdate(L,R,root,lazyUpd[root]);

	if (i>R || j<L)return;
	int mid=(L+R)/2;

	mutate(i,j,L,mid,Left(root),state);
	mutate(i,j,mid+1,R,Right(root),state);

	buc[root]=buc[Left(root)]+buc[Right(root)];

	return;
}

int main ()
{

	int tc,TC=0,M,T,Q;
	int x,y;
	char ch;
	scanf("%d",&tc);
	string ts;
	char line[100];
	
	while (tc--){
		scanf("%d",&M);
		string newS;
		s.erase();
		str[0]='\0';
		while (M--){
			scanf("%d",&T);
			cin.ignore();
			getline(cin,ts);
			//gets(line);
			//for (int i=0;i<T;i++) strcat(str,line);
			//newS=Concat(ts,T);
			for (int i=0;i<T;i++) s.append(ts);
			//s.append(newS);
		}

		//cout<<s<<endl;
		//cout<<str<<endl;
		int sz=s.size();
		//int sz=strlen(str);
		
		buildSeg(0,sz-1,1);

		scanf("%d",&Q);
		printf("Case %d:\n",++TC);
		int QC=0;
		while (Q--){
			cin.ignore();
			scanf("%c%d%d",&ch,&x,&y);
			if (ch=='E') mutate(x,y,0,sz-1,1,0);
			else if (ch=='F') mutate(x,y,0,sz-1,1,1);
			else if (ch=='I') mutate(x,y,0,sz-1,1,2);
			else if (ch=='S'){
				int Bucc=getRange(x,y,0,sz-1,1);
				printf("Q%d: %d\n",++QC,Bucc);
			}
		}
	}
	return 0;
}
