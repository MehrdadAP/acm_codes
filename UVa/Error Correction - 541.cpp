#include <iostream>

using namespace std;

#define MAX 105
bool a[MAX][MAX];
int main ()
{
	int row,col,rowi,colj;
	int rowcnt,colcnt;
	int n;
	while (cin>>n,n!=0)
	{
		rowcnt=colcnt=0;
		for(int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				cin>>a[i][j];
		/*
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
		*/
		for (int i=1;i<=n;i++)
		{
			row=col=0;
			for (int j=1;j<=n;j++)
			{
				if (a[i][j]==true)
						row++;
				
				if (a[j][i]==true)
					col++;
			}
			if (row%2!=0)
			{
				rowi=i;
				rowcnt++;
			}
			if (col%2!=0)
			{
				colj=i;
				colcnt++;
			}
		}

		if (rowcnt==0 && colcnt==0)
			cout<<"OK\n";
		else if (rowcnt>1 || colcnt>1)
			cout<<"Corrupt\n";
		else
		{
			printf("Change bit (%d,%d)\n",rowi,colj);
		}
	}
	return 0;
}
