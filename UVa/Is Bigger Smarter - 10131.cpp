									/*ba yade oo */

/*
AC code

Problem : UVA - 10131 - Is Bigger Smarter
Category : DP - LIS
Complexity : O(N^2)
Authur : Mehrdad AP
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
#define MAX 1009

typedef vector<int> vi;

int w[MAX],s[MAX],t[MAX],p[MAX];

struct node
{
	int w,s,id;

	bool operator < (const node& b)const
	{
		return (w<b.w);
	}
}arr[MAX];

void printPath(int x)
{
	if (p[x]==x)
		cout<<arr[x].id<<endl;
	else
	{
		printPath(p[x]);
		cout<<arr[x].id<<endl;
	}
}


int main ()
{

	int W,S;
	int k=1;
	while (cin>>W>>S)
	{
		arr[k].w=W;
		arr[k].s=S;
		arr[k].id=k;
		k++;
	}

	sort(arr,arr+k);
	int mx,mxi;
	mx=0;
	for (int i=1;i<k;i++)
	{
		t[i]=1;
		p[i]=i;
		for (int j=1;j<i;j++)
			if (arr[i].w>arr[j].w && arr[i].s<arr[j].s && t[j]+1>t[i])
			{
				t[i]=t[j]+1;
				p[i]=j;
			}


		if (t[i]>mx)
		{
			mx=t[i];mxi=i;
		}
	}

	cout<<mx<<endl;
	printPath(mxi);

	return 0;
}