									/*ba yade oo */
//AC Code
//pure map !!:D
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
typedef pair<int,int> pii;
typedef long long int lli;

map<vi,int> mp;

int main ()
{

	int N,x;
	vi vec;
	while (cin>>N,N){
		mp.clear();
		for (int i=0;i<N;i++){
			vec.clear();
			int k=5;
			while (k--){
				cin>>x;
				vec.push_back(x);
			}

			sort(vec.begin(),vec.end());

			if(mp.find(vec)==mp.end())mp[vec]=1;
			else mp[vec]++;
		}

		int mx=0;
		for (map<vi,int>::iterator it=mp.begin();it!=mp.end();it++){
			mx=max(mx,it->second);
		}

		int ans=0;
		for (map<vi,int>::iterator it=mp.begin();it!=mp.end();it++){
			if (it->second==mx)ans+=it->second;
		}

		cout<<ans<<endl;
		

	}

	return 0;
}
