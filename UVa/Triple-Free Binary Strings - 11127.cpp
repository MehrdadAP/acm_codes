									/*ba yade oo */
/*
AC Code 

Probem : UVA - 11127 - Triple-Free Binary String
Category : BT with pruning
Complexity : Bemanad !
Author : Mehrdad AP

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
#define INF 0x7FFFFFFF
#define MAX 33

typedef vector<int> vi;

int ans,N;
char a[MAX],b[MAX];



bool isOK(int x)
{
	int cnt;
	if (x<2) return true;
	for (int s=1;s<=(x+1)/3;s++)
	{
		int i=x-3*s+1;
		cnt=0;
		bool flag=true;
		for (int j=i+s-1;j>=i && flag;j--)
			if (a[j]==a[j+s] && a[j+s]==a[j+2*s])
				cnt++;
			else
				flag=false;
		if (cnt==s)
			return false;
	}
	return true;
	
}

void BT(int k)
{
	if (isOK(k-1)==false)return;//Harasing !

	if (k==N)
	{
		ans++;
		return;
	}

	if (b[k]!='*')
		BT(k+1);
	else
	{
		a[k]='1';
		BT(k+1);
		a[k]='0';
		BT(k+1);
	}

}

int main ()
{
	int tc=0;
	while (scanf("%d",&N),N!=0)
	{
		ans=0;
		scanf("%s",a);
		memcpy(b,a,sizeof(a));
		BT(0);
		printf("Case %d: %d\n",++tc,ans);
	}
	return 0;
}