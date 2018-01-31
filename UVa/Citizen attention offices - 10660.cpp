									/*ba yade oo */
//AC Code

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
#define EPS 1e13
#define INF 1e9;
#define MAX 30
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;
#define minimal(x,y) ( x<y ? x : y)

lli mini;

vector<vi> ans;

set<int> st;
vector< pair< pair<int,int> , int> > area;


void calcDis()
{
	
	lli dis=0;
	vector<int> tmp;
	for (int i=0;i<area.size();i++){
		
		lli less=INF;
		for (set<int>::iterator it=st.begin();it!=st.end();it++)
		{
			int val=*(it);
			int x=val/5;
			int y=val%5;
			less=minimal(less,(absol(x-area[i].first.first)+absol(y-area[i].first.second))*area[i].second);
		}
		dis+=less;
	}

	if (dis<mini)
	{
		ans.clear();
		mini=dis;
		ans.push_back(vi(st.begin(),st.end()));
	}
	else if (dis==mini)
	{
		ans.push_back(vi(st.begin(),st.end()));
	}
}

int oops;

void BT(int i,int cnt)
{
	if (cnt==5)return calcDis();
	if (i==25)return;

	st.insert(i);
	BT(i+1,cnt+1);
	

	if (25-i>5-cnt)
	{
		st.erase(i);
		BT(i+1,cnt);
	}
	st.erase(i);
}

int main ()
{
	int tc,a,b,c;
	cin>>tc;
	int N;

	while (tc--)
	{
		st.clear();
		ans.clear();
		area.clear();
		cin>>N;

		for (int i=0;i<N;i++){
			cin>> a >> b >> c;
			area.push_back( pair< pair<int,int>,int >(pii(a,b),c));
		}
		
		mini=INF;
		BT(0,0);
		
		sort(ans.begin(),ans.end());

		for (int i=0;i<4;i++)
			cout<<ans[0][i]<<" ";
		cout<<ans[0][4]<<endl;
		

	}
	

	return 0;
}
