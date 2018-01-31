									/*ba yade oo */
//AC Code
//longest maximum substring!

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
#define MAX 20100
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int t[MAX],val[MAX],start[MAX];

int main ()
{

	int tc,N,ansInd,TC=0;
	cin>>tc;

	while (tc--){
		cin>>N;
		for (int i=0;i<N-1;i++)cin>>val[i];

		t[0]=val[0];start[0]=0;
		ansInd=0;
		for (int i=1;i<N-1;i++){
			if (t[i-1]>=0){t[i]=t[i-1]+val[i];start[i]=start[i-1];}
			else {t[i]=val[i];start[i]=i;}
			
			if (t[i]<t[ansInd])continue;

			if (t[i]>t[ansInd])ansInd=i;
			else if (t[i]==t[ansInd] && i-start[i]>ansInd-start[ansInd])ansInd=i;
			else if (t[i]==t[ansInd] && i-start[i]==ansInd-start[ansInd] && start[i]<start[ansInd])ansInd=i;
		}

		if (t[ansInd]<=0)printf("Route %d has no nice parts\n",++TC);
		else printf("The nicest part of route %d is between stops %d and %d\n",++TC,start[ansInd]+1,ansInd+2);

	}

	return 0;
}
