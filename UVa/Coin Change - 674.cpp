/// Provided By Mehrdad


#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 7492
#define COIN 10
int main()
{
	int t[MAX][COIN];
	int coin[COIN];
	int n,sum;
	n=5;
	coin[1]=1;coin[2]=5;
	coin[3]=10;coin[4]=25;
	coin[5]=50;
	//generlize
	/*
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>coin[i];
	//sort(coin,coin+COIN);;
	*/
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
	/*Table :
	for (int i=0;i<MAX;i++)
	{
		for (int j=0;j<=n;j++)
			cout<<t[i][j]<<" ";
		cout<<endl;
	}
	*/
	while (cin>>sum)
		cout<<t[sum][n]<<endl;
	return 0;

}