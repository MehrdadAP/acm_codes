									/*ba yade oo */
//AC Code
//athor of this problem just can be shahriar manzoor !!!
//shahriar-type-problem !

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

vi ans;

int main ()
{
	int N,x;
	while (cin>>N,N){
		ans.clear();
		for (int i=0;i<N;i++){
			cin>>x;
			if (x>0)ans.push_back(x);
		}
		if (ans.size()==0)ans.push_back(0);

		printf("%d",ans[0]);
		for (int i=1;i<ans.size();i++)printf(" %d",ans[i]);
		cout<<endl;
	}

	return 0;
}
