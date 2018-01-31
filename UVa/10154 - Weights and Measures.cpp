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

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 0x7FFFFFFF
#define MAX 5700

int w[MAX],s[MAX],t[MAX],p[MAX];


void printPath(int x)
{
	if (p[x]==x)
	{
		printf("%d",x);
		return ;
	}

	printPath(p[x]);
	printf(" %d",x);
}
int main ()
{
	int weight,strength;
	int cnt=1;
	while(cin>>weight>>strength)
	{
		w[cnt]=weight;
		s[cnt]=strength;
		t[cnt]=1;
		cnt++;
		
	}
	int N=cnt-1;

	for (int i=1;i<=N-1;i++)
	{
		for (int j=i+1;j<=N;j++)
		{
			if (s[j]>s[i])
			{
				swap(s[i],s[j]);
				swap(w[i],w[j]);
			}
			else if (s[j]==s[i] && w[j]<w[i])
				{
				swap(s[i],s[j]);
				swap(w[i],w[j]);
			}
		}
	}
		
	cout<<"after sort\n";
	for (int i=1;i<=N;i++)
	{
		printf("%d: w:%d s:%d\n",i,w[i],s[i]);
	}
	cout<<endl;

	int p[MAX];
	for (int i=1;i<=N;i++)
		s[i]=s[i]-w[i];
	for (int i=1;i<=N;i++)
	{
		p[i]=i;
		for (int j=1;j<i;j++)
		{
			if (w[i]<=s[j])
			{
				if (t[j]+1>t[i])
				{
					t[i]=t[j]+1;
					s[i]=min(s[i],s[j]-w[i]);
					p[i]=j;
				}
				else if (t[j]+1==t[i])
				{
					int mini=min(s[j]-w[i],s[i]);
					if (mini>s[i])
					{
						s[i]=s[j]-w[j];
						p[i]=j;
					}
				}
			}
		}
	}
	int maxi=0,maxInd;
	for (int i=1;i<=N;i++)
	{
		if (t[i]>maxi)
		{
			maxi=t[i];
			maxInd=i;
		}
	}

	printf("ans:%d\n%d\n",maxi,maxInd);
	
	for (int i=1;i<=N;i++)
		cout<<t[i]<<" ";
	cout<<endl<<endl;
	for (int i=1;i<=N;i++)
		cout<<p[i]<<" ";

	//printPath(maxInd);
	cout<<endl;
	system("pause");
	return 0;

}
