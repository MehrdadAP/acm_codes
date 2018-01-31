#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#define MAX 9
using namespace std;

int n,k,ans;
bool a[MAX][MAX];


struct cell
{
	int x;
	int y;
	cell(int i,int j):x(i),y(j){};
		
};

stack<cell> s;
bool promising(int b,int pi,int pj)
{
	stack<cell> sCopy=s;
	if (!s.empty())
		sCopy.pop();
	while (!sCopy.empty())
	{
		cell temp=sCopy.top();
		if (abs(temp.x-pi)==abs(temp.y-pj))
			return false;
		sCopy.pop();
	}
	return true;
}

void bt(int b,int pi,int pj)//b:number of Bishops currently used
{
	if (promising(b,pi,pj))
	{
		if (b==k)
		{ 
			/*
			for (int i=0;i<n;i++)
			{
				for (int j=0;j<n;j++)
					cout<<a[i][j]<<" ";
				printf("\n");
			}
			printf("\n\n");
			*/
			//printf("%d\n",ans);
			ans++;
			return ;
		}

		for (int j=0;j<n;j++)
			for (int i=0;i<n;i++)
			{
				if (j<pj)
					continue;
				if (i<=pi && j==pj)
					continue;
				if (a[i][j]==false)
				{
					a[i][j]=true;
					cell tempCell(i,j);
					s.push(tempCell);
					bt(b+1,i,j);
					s.pop();
					a[i][j]=false;
				}
			}
	}
}
int main ()
{
	unsigned long long int big=1;
	while (cin>>n>>k,n!=0 && k!=0)
	{
		ans=0;
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				a[i][j]=false;
		//bt(1,0,0);
		
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				cell tempCell(i,j);
				s.push(tempCell);
				bt(1,i,j);
				while (!s.empty())
					s.pop();
				a[i][j]=false;
			}

		printf("%d\n",ans);
	}
	return 0;
}