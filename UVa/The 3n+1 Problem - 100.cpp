									/*ba yade oo */

/*
AC Code
but I cann't understand why it's accepted instead of TLE !

Problem : UVA - 100 - The 3n+1 Problem
Category : Adhoc
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
#define MAX 1000000

typedef vector<int> vi;


int calc(int n)
{
	int ret=0;
	while (n!=1)
	{
		if (n%2==0)n=n/2;
		//else n=3*n+1;
		else 
		{
			n=3*(n/2)+2;
			ret++;
		}
		ret++;
	}

	return ret+1;
}

unsigned int t[MAX];
int main ()
{
	int x,y;
	////for (int i=1;i<MAX-4;i++)
	//	//t[i]=calc(i);
	/*while (cin>>x)
		cout<<calc(x)<<endl;*/

	//for (int i=MAX/10;i<=MAX;i++)
	//	t[i]=calc(i);
	while (cin>>x>>y)
	{
		bool flag=true;
		if (x>y)
		{
			swap(x,y);
			flag=false;
		}
		int ans=0;
		for (int i=x;i<=y;i++)
		{
			ans=max(ans,calc(i));
		}
		if (flag)printf("%d %d ",x,y);
		else printf("%d %d ",y,x);
		cout<<ans<<endl;
	}
	return 0;
}