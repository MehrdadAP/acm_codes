									/*ba yade oo */
/*
AC Code
WHY ACCEPTED ?!!!:D for small N , TLE !!

Problem : UVA - 471 - Magic Numbers
Category: Backtrack
Coder : Mehrdad AP

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
#define MAX 10000
#define MODE 1000000007

typedef vector<int> vi;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<long long,long long> plili;

vector< pair<lli,lli> > ans;
//set< pair<lli,lli> > ans;
bool vis[10];
lli N;

bool allSame(lli x)
{
	set<int> st;
	while (x>0)
	{
		if (st.find(x%10)!=st.end())return false;
		st.insert(x%10);
		x/=10;
	}
	return true;
}

void BT(lli x,int level)
{
	if (level>10) return;

	for (int i=0;i<10;i++)
		if (vis[i]==false)
		{
			//if (level==1 && i==5)return;
			//nums.insert(x*10+i);
			lli b=x*10+i;
			if (b==0)continue;
			if (b*N<10000000000 && allSame(b*N))
				ans.push_back(plili(b*N,b));
			else if (b*N>9876543210)return;
			vis[i]=true;
			BT(x*10+i,level+1);
			vis[i]=false;
		}
}

int main ()
{

	int tc;

	cin>>tc;
	while (tc--)
	{
		cin>>N;
		ans.clear();
		for (int i=0;i<10;i++)vis[i]=false;

		BT(0,1);
		sort(ans.begin(),ans.end());

		for (int i=0;i<ans.size();i++)
			printf("%lld / %lld = %lld\n",ans[i].first,ans[i].second,N);
		if (tc!=0)puts("");
	}


	return 0;
}
