#include <iostream>
#include <algorithm>
using namespace std;

#define C 334
#define H 32

int f[C][H];
int t[C][H];
int h[H][2];

void print_path(int i,int j)
{
	if (i==0 || j==0)
		return ;
	if (f[i][j]==1)
	{
		print_path(i-h[j][1],j-1);
		cout<<h[j][0]<<" "<<h[j][1]<<endl;
	}
	else
		print_path(i,j-1);
}
int main ()
{
	
	int sec,time;
	while (cin>>sec>>time)
	{
		for (int i=0;i<=C;i++) 
			for (int j=0;j<=H;j++)
				t[i][j]=0;
		int k;
		cin>>k;
		for (int i=1;i<=k;i++)
		{
			cin>>h[i][0];
			cin>>h[i][1];
		}
		int i,j;
		for (i=1;i<=sec;i++)
		{
			bool flag=true;
			for (j=1;j<=k;j++)
			{
				if (i<h[j][1])
				{
						t[i][j]=t[i][j-1];
						f[i][j]=2;
				}
				else
				{
					if (t[i-h[j][1]][j-1]+h[j][1]>t[i][j-1])
					{
						sec-=3*time*h[j][0];
						printf("sec:%d ",sec);
						if (sec<0)
						{
							flag=false;
							break;
						}
						f[i][j]=1;
						t[i][j]=t[i-h[j][1]][j-1]+h[j][1];
					}
					else
					{
						f[i][j]=2;
						t[i][j]=t[i][j-1];
					}
				}
			}	
			if (flag==false)
					break;
		}
		cout<<endl;
		//cout<<i<<" "<<j<<endl;
		for (int v=0;v<=k;v++)
			cout<<h[v][0]<<" "<<h[v][1]<<" - ";
		cout<<endl;
		for (int w=0;w<=i;w++)
		{
			for(int v=0;v<=j;v++)
				cout<<t[w][v]<<" ";
			cout<<endl;
		}
		
		print_path(i-1,j-1);
		cout<<"sum:"<<t[i-1][j-1]<<endl;
			
	}
	return 0;



}