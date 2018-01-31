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
#define MAX 10000
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

map<char,int> mp;

void init()
{
	int k=1,i;
	for (i=0;i<18;i++){
		mp['a'+i]=k++;
		if (k==4)k=1;
	}
	mp['a'+i]=4;
	k=1;
	i++;
	for (;i<25;i++){
		mp['a'+i]=k++;
		if (k==4)k=1;
	}
	mp['a'+i]=4;

}


int main ()
{

	init();

	int tc,TC=0;
	cin>>tc;
	cin.ignore();
	char line[200];
	while (tc--){
		gets(line);

		int ans=0;
		int sz=strlen(line);
		for (int i=0;i<sz;i++){
			if (line[i]==' ')ans+=1;
			else ans+=mp[line[i]];
		}

		printf("Case #%d: %d\n",++TC,ans);
		
	}
	

	return 0;
}
