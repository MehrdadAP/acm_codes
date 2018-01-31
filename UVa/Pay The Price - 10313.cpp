/// Provided By Mehrdad


#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 302
#define COIN 302
int main()
{
	unsigned long long int t[MAX][COIN];
	int coin[COIN];
	int n,sum;
	n=300;
	for (int i=1;i<=n;i++)
		coin[i]=i;
	//sort(coin,coin+COIN);;

	for (int i=0;i<MAX;i++)
		for (int j=0;j<COIN;j++)
		{
			t[i][j]=0;
			if (i==0)
				t[i][j]=1;
		}

	for (int i=1;i<MAX;i++)
		for (int j=1;j<=n;j++)
		{
			if (i<coin[j])
				t[i][j]=t[i][j-1];
			else
				t[i][j]=t[i-coin[j]][j]+t[i][j-1];
			
		}
	/*
	for (int i=0;i<MAX;i++)
	{
		for (int j=0;j<=n;j++)
			cout<<t[i][j]<<" ";
		cout<<endl;
	}
	*/
	char c;
	int l1,l2,p;
	while (cin>>sum)
	{
		
		c=cin.get();
		if (c=='\n')
			if (sum!=0)
				cout<<t[sum][sum]<<endl;
			else
				cout<<1<<endl;
		else 
		{
			cin>>l1;
			if (l1>300)
				p=300;
			else
				p=l1;
			c=cin.get();
			if (c=='\n')
				if (sum!=0)
					cout<<t[sum][p]<<endl;
				else
					cout<<1<<endl;
			else
			{
				if (l1>300)
					p=301;
				if (l1==0)
					p=1;
				cin>>l2;
				if (l2>300)
					l2=300;
				if (sum!=0)
					cout<<t[sum][l2]-t[sum][p-1]<<endl;
				else
					cout<<1<<endl;
			}
		}
		
	}
	return 0;

}