									/*ba yade oo */
/*
Probelm : UVA - 725 - Division
Category : simple Brute-Force
Authur : Mehrdad AP

*/
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
#define MAX 10000
#define MODE 1000000007

typedef vector<int> vi;
typedef long long int lli;
typedef pair<int,int> pii;

bool digit[10];
vector<pii> ans;
int a[5],b[5];

int arrToNum(int x[])
{
	int ans=0;
	for (int i=0;i<5;i++)
		ans=ans*10+x[i];

	return ans;
}

bool haveSame(int b[])
{
	int x[5];
	for (int i=0;i<5;i++)x[i]=b[i];
	sort(x,x+5);
	for (int i=0;i<4;i++)
		if (x[i]==x[i+1])return false;

	return true;
}

bool isOK(int a,int b[])
{
	int t[10],i;
	for (i=0;i<5;i++)
		t[i]=b[i];

	if (a<10000)
		t[i++]=0;
	for (;i<10;i++)
	{
		t[i]=a%10;
		a=a/10;
	}
	sort(t,t+10);
	for (int k=0;k<9;k++)
		if (t[k]==t[k+1])return false;
	return true;
}

int main ()
{
	int N,bnum,anum;
	bool firstTC=true;
	while (cin>>N , N)
	{
		if (firstTC)
		{
			firstTC=false;
		}
		else
			cout<<endl;

		ans.clear();
		for (int f=0;f<10;f++)
			for (int g=0;g<10;g++)
				for (int h=0;h<10;h++)
					for (int i=0;i<10;i++)
						for  (int j=0;j<10;j++)
						{
							b[0]=f;b[1]=g;b[2]=h;b[3]=i;b[4]=j;
							if (haveSame(b)==false)continue;
							bnum=arrToNum(b);
							if (bnum*N<100000 && bnum*N>=1000)
							{
								if (isOK(bnum*N,b))
									ans.push_back(pii(bnum*N,bnum));
							}
						}

		
		sort(ans.begin(),ans.end());
		if (ans.size()==0)printf("There are no solutions for %d.\n",N);
		else
			for (int i=0;i<ans.size();i++)
				printf("%05d / %05d = %d\n",ans[i].first,ans[i].second,N);

	}
	

	return 0;
}
