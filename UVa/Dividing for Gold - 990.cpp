#include <iostream>
#include <algorithm>
using namespace std;

#define C 10004
#define H 32

bool f[C][H];
int t[C][H];
int h[H][2];
int cnt[C][H];


void print_path(int i,int j,int tm)
{
	if (i==0 || j==0)
		return ;
	if (f[i][j]==true)
	{
		print_path(i-3*tm*h[j][0],j-1,tm);
		cout<<h[j][0]<<" "<<h[j][1]<<endl;
	}
	else
		print_path(i,j-1,tm);
}
int main ()
{
    int tm;
	int sec,k;
	int temp=0;
	while (cin>>sec>>tm)
	{
		if (temp!=0)
			cout<<endl;
		else
			temp=1;
		cin>>k;
		for (int i=0;i<=sec;i++) 
			t[i][0]=0;
		for (int j=0;j<=k;j++)
			t[0][j]=0;
		for (int i=0;i<=sec;i++)
			for (int j=0;j<=k;j++)
				cnt[i][j]=0;
		for (int i=1;i<=k;i++)
		{
			cin>>h[i][0];
			cin>>h[i][1];
		}
		for (int i=1;i<=sec;i++)
			for (int j=1;j<=k;j++)
			{
				if (i<3*tm*h[j][0])
				{
						cnt[i][j]=cnt[i][j-1];
						t[i][j]=t[i][j-1];
						f[i][j]=false;
				}
				else if (t[i-3*tm*h[j][0]][j-1]+h[j][1]>t[i][j-1])
				{
					cnt[i][j]=cnt[i-3*tm*h[j][0]][j-1]+1;
					f[i][j]=true;
					t[i][j]=t[i-3*tm*h[j][0]][j-1]+h[j][1];
				}
				else
				{
					f[i][j]=false;
					t[i][j]=t[i][j-1];
					cnt[i][j]=cnt[i][j-1];
				}
				
			}
			/*
		for (int i=0;i<=n;i++)
			cout<<h[i]<<" ";
		cout<<endl;
		for (int i=0;i<=c;i++)
		{
			for(int j=0;j<=n;j++)
				cout<<t[i][j]<<" ";
			cout<<endl;
		}
		*/
		cout<<t[sec][k]<<endl<<cnt[sec][k]<<endl;
		print_path(sec,k,tm);
		
			
	}
	return 0;
}
