									/*ba yade oo */

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
#define INF 10000
#define MAX 500

typedef vector<int> vi;

map<string,int> mp;
int g[MAX][MAX];

pair<string,int> names[MAX];

int num;
int isExist(string x)
{
	for (int i=0;i<num;i++)
		if (x==names[i].first)
			return names[i].second;
	return -1;
}
int main ()
{
	int N,R,id;
	string name1,name2;
	int TC=0;
	while (cin>>N>>R , R || N)
	{
		TC++;
		id=0;
		mp.clear();
		for (int i=0;i<N;i++)
			for (int j=0;j<N;j++)
				if (i!=j)
					g[i][j]=INF;
				else
					g[i][j]=0;

		for (int i=0;i<R;i++)
		{
			
			cin>>name1>>name2;
			if (mp.find(name1)==mp.end())
				mp[name1]=id++;
			
			if (mp.find(name2)==mp.end())
				mp[name2]=id++;

			g[mp[name1]][mp[name2]]=1;
			g[mp[name2]][mp[name1]]=1;
			/*int ind1=isExist(name1);
			if (ind1==-1)
			{
				names[num].first=name1;
				names[num].second=num;
				ind1=num;
				num++;
			}

			int ind2=isExist(name2);
			if (ind2==-1)
			{
				names[num].first=name2;
				names[num].second=num;
				ind2=num;
				num++;
			}

			g[ind1][ind2]=1;
			g[ind2][ind1]=1;*/
		}

		for (int k=0;k<N;k++)
			for (int i=0;i<N;i++)
				for (int j=0;j<N;j++)
					g[i][j]=min(g[i][j],g[i][k]+g[k][j]);


		int mx=0;
		bool flag=true;

		for (int i=0;i<N && flag;i++)
			for (int j=0;j<N && flag;j++)
				if (i!=j && g[i][j]==INF)
					flag=false;
				else if (i!=j)
					mx=max(mx,g[i][j]);
		if (flag)
			printf("Network %d: %d\n\n",TC,mx);
		else
			printf("Network %d: DISCONNECTED\n\n",TC);
	}



	return 0;
}