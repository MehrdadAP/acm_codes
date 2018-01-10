									/*ba yade oo */
//AC, Dec 24 2011

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
#define MAX 110

typedef vector<int> vi;

int a[MAX][MAX];
int par[MAX][MAX],w[MAX][MAX],M;
vi path[MAX];
void printPath(int x,int y,int ind)
{
	if (y==M+1)
	{
		return;
	}
	path[ind].push_back(x);
	printPath(par[x][y],y+1,ind);
	
	int a=1;
	a=a/x;
}

int main ()
{
	int N;
	while (cin>>N>>M)
	{
		path[0].clear();
		for (int i=1;i<=N;i++)
		{
			path[i].clear();
			par[i][1]=i;
			for (int j=1;j<=M;j++)
			{
				
				cin>>a[i][j];
				
				w[i][j]=INF;
			}
		}

		for (int i=1;i<=N;i++)
			w[i][M]=a[i][M];

		for (int j=M-1;j>=1;j--)
			for (int i=1;i<=N;i++)
			{
				int ii=(i-1==0) ? N:i-1;
				int ii2=(i+1==N+1)? 1 : i+1;
				w[i][j]=min(w[ii][j+1],min(w[i][j+1],w[ii2][j+1]))+a[i][j];

				if (w[i][j+1]<w[ii][j+1])
				{
					if (w[i][j+1]<w[ii2][j+1])
						par[i][j]=i;//i smallest
					else if (w[ii2][j+1]<w[i][j+1])
						par[i][j]=ii2;//ii2 smallest
					else
						par[i][j]=min(i,ii2);//i==ii2
				}
				else if ( w[ii][j+1]<w[i][j+1])
				{
					if (w[ii][j+1]<w[ii2][j+1])
						par[i][j]=ii;//ii smallest
					else if (w[ii2][j+1]<w[ii][j+1])
						par[i][j]=ii2;//ii2 smallest
					else
						par[i][j]=min(ii,ii2);//ii==ii2
				}
				else
				{
					if (w[ii2][j+1]<w[i][j+1])
						par[i][j]=ii2;//ii2 smallest
					else if (w[i][j+1]<w[ii2][j+1])
						par[i][j]=min(ii,i);
					else
						par[i][j]=min(ii,min(ii2,i));//i==ii2=ii
				}

			}
			
		int ind=0;
		int tmpw=w[1][1];
		for (int i=2;i<=N;i++)
			tmpw=min(tmpw,w[i][1]);

		for (int i=1;i<=N;i++)
			if (w[i][1]==tmpw)
			{
				printPath(i,1,ind);
				ind++;
			}
		
		/*cout<<endl<<"Weights:\n";
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=M;j++)
				cout<<w[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;

		cout<<endl<<"parents:\n";
		for (int i=1;i<=N;i++)
		{
			for (int j=1;j<=M;j++)
				cout<<par[i][j]<<" ";
			cout<<endl;
		}
		cout<<endl;
*/
		for (int i=0;i<ind-1;i++)
			for (int j=i+1;j<ind;j++)
			{
				int k=0;
				while (k!=M && path[i][k]==path[j][k])k++;
					
				if (k!=M && path[j][k]<path[i][k])
				{
					//swap two arrays
					for (int s=0;s<M;s++)
						swap(path[i][s],path[j][s]);
				}

			}
			
			for (int i=0;i<M-1;i++)
				printf("%d ",path[0][i]);
			cout<<path[0][M-1]<<endl;
			cout<<tmpw<<endl;
	}
	return 0;
}	 