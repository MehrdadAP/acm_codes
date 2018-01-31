									/*ba yade oo */
//TLE !
//ajiban ghariba !:D
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
#define INF 100000000
#define MAX 20
#define MODE 1000000007

typedef vector<int> vi;
typedef long long int lli;

//bool bad[MAX][MAX],vis[MAX],rightDiag[2*MAX],leftDiag[2*MAX];
//int row[MAX],N;
//bool bad[MAX][MAX];
int N,ans;

int Bad[20];//,RightDiag,LeftDiag,Vis;
//long long ans;

 //bool isOK(int col)
 //{
	// /*for (int i=1;i<col;i++)
	//	 if (row[i]==row[col] || absol(row[i]-row[col])==(col-i)) return false;
	// */
	// 
	// return true;
 //}

#define rightCalc(x,y) (y>=x ? y-x+1 : x-y+N)
 

 void BT(int col,int rightDiag,int leftDiag,int unvis)
 {
	 //if (!isOK(col-1))return;
	 if (col==N+1){ans++;return;}
	 int i;

	 for (i=(-unvis & unvis);i<=N;i++)
	 {
		 if ( (Bad[col] & (1<<i) ) )continue;
		 //if ((Bad & (1<<(i*N+col))) || (Vis & (1<<i))) continue;

		//if (vis[i])continue;
		

		//if (rightDiag[rightCalc(i,col)])continue;
		//if (( vis & (1<<i)) || (rightDiag & (1<<rightCalc(i,col))) || (leftDiag & (1<< (col+i-1)) ) )continue;

		 if ( !( unvis & (1<<i)) || (rightDiag & (1<<rightCalc(i,col))) || (leftDiag & (1<< (col+i-1)) ) )continue;
		//if (leftDiag[col+i-1])continue;
		//if (LeftDiag & (1<< (col+i-1)) ) continue;

		
		//row[col]=i;
		//vis[i]=rightDiag[rightCalc(i,col)]=leftDiag[col+i-1]=true;
		
		/*Vis|=(1<<i);
		RightDiag|=(1<<(rightCalc(i,col)));
		LeftDiag|=(1<<(col+i-1));*/
		
		BT(col+1, ( rightDiag | (1<<rightCalc(i,col))) , ( leftDiag | (1<<(col+i-1)) ), (unvis & ~(1<<i) ) );
		//vis[i]=rightDiag[rightCalc(i,col)]=leftDiag[col+i-1]=false;
		
		/*Vis&=~(1<<i);
		RightDiag&=~(1<<(rightCalc(i,col)));
		LeftDiag&=~(1<<(col+i-1));*/
	 }

 }

int main ()
{
	char ch;
	int x;
	//while (cin>>x)cout<< ( -x & x ) <<endl;
	int TC=0;
	char line[1000];
	while (gets(line))
	{
		sscanf(line,"%d",&N);
		if (N==0)break;
		/*memset(rightDiag,false,sizeof rightDiag);
		memset(leftDiag,false,sizeof leftDiag);
*/
		//Bad=RightDiag=LeftDiag=Vis=0;
		//bool hasBad=false;
		//cin.ignore();
		
		for (int i=1;i<=N;i++)
		{
			gets(line);
			Bad[i]=0;
			for (int j=0;j<N;j++){
				
				//cin>>ch;
				if (line[j]=='*') 
				{
					//Bad|=(1<<(i*N+j));
					//bad[i][j]=true;
					Bad[i]|=(1<<(j+1));
					//hasBad=true;
				}
				
				
			}
		}

		ans=0;
		//if (hasBad || N<12)
		BT(1,0,0,65535);
	/*	else if (N==14)ans=365596;
		else if (N==13)ans=73712;
		else if (N==12)ans=14200;
*/
		printf("Case %d: %d\n",++TC,ans);
	}
	

	return 0;
}
