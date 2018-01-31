									/*ba yade oo */
//AC Code
//MAP!
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

map<string,int> mp;

int main ()
{

	int tc,sum;
	cin>>tc;
	cin.ignore();
	cin.ignore();
	string name;
	while (tc--){
		mp.clear();
		sum=0;

		while (getline(cin,name)){
			if (name.size()==0)break;
			
			if (mp.find(name)==mp.end())mp[name]=1;
			else mp[name]++;
			sum++;
		}

		for (map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
			printf("%s ",it->first.c_str());

			int cnt=it->second;

			printf("%.4lf\n",((double)cnt/sum)*100.0);
		}
		if (tc!=0)cout<<endl;

	}

	return 0;
}
