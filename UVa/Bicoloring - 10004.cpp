#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 202

int a[MAX][MAX];
int color[MAX];
int n;
int cnt=0;
 
bool f(int i,int col)
{
	bool flag=true;
	color[i]=col;
	for (int k=1;k<=a[i][0];k++)
	{
		if (color[a[i][k]]==0)
		{
			flag=f(a[i][k],col*-1);
			if (flag==false)
				break;
			cnt++;
			if (cnt==n)
				return true;
		}

		if (color[a[i][k]]==col)
			return false;
		

	}
	return flag;
	
	
}


int main()
{
	int m;
	int x,y;
	while (cin>>n,n!=0)
	{
		cin>>m;
		for (int i=0;i<n;i++)
		{
			color[i]=0;
			for (int j=0;j<n;j++)
				a[i][j]=0;
		}
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&x,&y);
			//a[x][y]=1;
			//a[y][x]=1;
			
			a[x][++a[x][0]]=y;
			a[y][++a[y][0]]=x;

			
		}
		/*
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
				printf("%d ",a[i][j]);
			cout<<endl;
		}*/
		if (f(0,1))
			puts("BICOLORABLE.");
		else
			puts("NOT BICOLORABLE.");
	}

	return 0;
}