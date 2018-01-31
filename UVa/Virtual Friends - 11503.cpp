									/*ba yade oo */
/*
AC Code

Probelm : UVA - 11503 - Virtual Friends
Category : Disjoint Set
Complexity : o(nlog*n)
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
#define MAX 2*100002

typedef vector<int> vi;

map<string,int> mp;

int p[MAX],h[MAX],size[MAX];

int findRoot(int x)
{
	if (p[x]==x)return x;

	int par=findRoot(p[x]);
	p[x]=par;
	return par;
}

void uni(int x,int y)
{
	if (h[x]<h[y])
	{
		p[x]=y;
		size[y]+=size[x];
	}
	else if (h[x]>h[y])
	{
		p[y]=x;
		size[x]+=size[y];
	}
	else
	{
		p[x]=y;
		h[y]++;
		size[y]+=size[x];
	}
}

int main ()
{

	int tc,F;
	scanf("%d",&tc);
	char name1[50],name2[50];
	while (tc--)
	{
		mp.clear();
		int cnt=0;
		scanf("%d",&F);
		/*for (int i=0;i<2*F;i++)
		{
			p[i]=i;
			h[i]=1;
			size[i]=1;
		}
*/
		for (int i=0;i<F;i++)
		{
			scanf("%s %s",name1,name2);
			if (mp.find(name1)==mp.end())
			{
				p[cnt]=cnt;
				h[cnt]=1;
				size[cnt]=1;
				mp[name1]=cnt++;

			}
			if (mp.find(name2)==mp.end())
			{
				p[cnt]=cnt;
				h[cnt]=1;
				size[cnt]=1;
				mp[name2]=cnt++;
			}
			
			int x=findRoot(mp[name1]);
			int y=findRoot(mp[name2]);

			if (x!=y)
				uni(x,y);
			printf("%d\n",max(size[x],size[y]));

		}
	}

	
	
	return 0;



}