									/*ba yade oo */
/*
AC Code

Problem		: UVA - 750 - 8 Queens Chess Problem
Category	: Simple BT
Coder		: Mehrdad AP

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
typedef long long int lli;

vector<  vi > ans;
vector<int> row(10);
int x,y;

bool isOK(int col)
{

	for (int i=1;i<col;i++)
		if (row[col]==row[i] || absol(row[col]-row[i])==(col-i) )
			return false;

	return true;
}

void BT(int col)
{
	if (!isOK(col-1))return;
	if (col==y){BT(col+1);return;}
	if (col==9) {ans.push_back(row);return;}

	for (int i=1;i<=8;i++)
	{
		row[col]=i;
		BT(col+1);
	}
}

int main ()
{

	int tc;
	cin>>tc;

	while (tc--)
	{
		cin>>x>>y;

		ans.clear();
		row[y]=x;

		BT(1);

		sort(ans.begin(),ans.end());

		puts("SOLN       COLUMN");
		puts(" #      1 2 3 4 5 6 7 8");
		puts("");

		for (int i=0;i<ans.size();i++)
		{
			printf("%2d      ",i+1);
			for (int j=1;j<=7;j++)
				printf("%d ",ans[i][j]);
			printf("%d\n",ans[i][8]);
		}

		if (tc!=0)puts("");
	}
	

	return 0;
}
