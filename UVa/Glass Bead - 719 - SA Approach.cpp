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
#define MAXLG 40

typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;

char A[2*MAX],B[MAX];
int P[MAXLG][2*MAX];
//pii pos[MAX];


struct entry
{
	int left,right,pos;
}L[2*MAX];

bool cmp(const entry &a,const entry &b)
{
	if (a.left!=b.left)
		return a.left<b.left;
	else
		return a.right<b.right;

}

int makeSA(int N)//return the K,last row of P
{
	int step;
	int cnt;
	for (int i=0;i<N;i++)
			P[0][i]=A[i]-'a';

	for (step=1,cnt=1;cnt>>1<N;step++,cnt<<=1)
	{
		//note : cnt=2^step
		//first, set L values
			
		for (int i=0;i<N;i++)
		{
			L[i].left=P[step-1][i];
			L[i].right=i+cnt<N ? P[step-1][i+cnt]:-1;
			L[i].pos=i;
		}

		sort(L,L+N,cmp);

		for (int i=0;i<N;i++)
			if (i>0 && L[i].left==L[i-1].left && L[i].right==L[i-1].right)
				P[step][L[i].pos]=P[step][L[i-1].pos];
			else
				P[step][L[i].pos]=i;
	}
	return step;
}

int main ()
{

	int tc,N,K;
	cin>>tc;

	while (tc--)
	{

		scanf("%s",B);
		int NB=strlen(B);

		bool flag=true;
		for (int i=1;flag && i<NB;i++)
			if (B[i]!=B[i-1])flag=false;

		if (flag)
		{
			cout<<1<<endl;
			continue;
		}

		strcpy(A,B);
		strcat(A,B);
		
		N=strlen(A);
		K=makeSA(N)-1;

		int ans;
		int mini=INF;
		for (int i=0;i<N/2;i++)
		{
			if (P[K][i]<mini)
			{
				mini=P[K][i];
				ans=i;
			}
		}

		cout<<ans+1<<endl;
	}


	return 0;
}
