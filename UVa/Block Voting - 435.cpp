									/*ba yade oo */
//AC Code

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
#define MAX 22
#define MODE 1000000007

typedef vector<int> vi;
typedef long long int lli;

bool active[MAX];
int num[MAX];
int ans,N,mini,X;

void BT(int i,int sum)
{
	if (i==N+1){
		if (sum<mini && sum+X>=mini)
			ans++;
		return;
	}

	if (active[i]==false)BT(i+1,sum);
	else{
		BT(i+1,sum+num[i]);
		BT(i+1,sum);
	}
}


int main ()
{

	int tc,tot;
	cin>>tc;


	while (tc--)
	{
		
		tot=0;
		memset(active,true,sizeof active);

		cin>>N;
		for (int i=1;i<=N;i++){
			cin>>num[i];
			tot+=num[i];
		}

		mini=(tot+1)/2;
		for (int i=1;i<=N;i++)
		{
			ans=0;
			X=num[i];
			active[i]=false;

			BT(1,0);
			printf("party %d has power index %d\n",i,ans);

			active[i]=true;
		}
		cout<<endl;
	}

	return 0;
}
