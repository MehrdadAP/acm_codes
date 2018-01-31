									/*ba yade oo */

//AC Code
//Bisection Method , also can be solved by DP
//note that for boundary value of bisection


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
#define MAX 1009
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

int N,M,val[MAX];


bool isOK(int mx)
{

	int cnt=0;
	lli s=0;
	for (int i=0;i<N;i++){

		if (s+val[i]>mx){s=val[i];cnt++;}
		else {s+=val[i];}
	}
	return (cnt+1<=M);//+1 for last one
}



int main ()
{

	lli lo,hi,mid,ans;

	while (cin>>N>>M){
		hi=0;
		for (int i=0;i<N;i++){cin>>val[i];hi+=val[i];}
		if (M>N)M=N;

		lo=*max_element(val,val+N);
		
		while (lo<hi){
			mid=(lo+hi)/2;

			if (isOK(mid)){hi=mid;ans=mid;}
			else lo=mid+1;
		}
		if (isOK(lo))ans=lo;
		cout<<ans<<endl;

	}

	return 0;
}
