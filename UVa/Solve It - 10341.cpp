									/*ba yade oo */
//AC Code
//Bisection Method
//Also read http://www.algorithmist.com/index.php/UVa_10341

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
#define EPS 1e-10
#define EPS2 1e-14
#define INF 100000000
#define MAX 10000
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;


int p,q,r,s,t,u;

int solve(double x)
{
	double eq;
	eq=p/exp(x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;

	if (fabs(eq-0.0)<EPS) return 0;
	else if (eq>EPS)return 1;
	else return -1;

}

int main ()
{

	double lo,hi,mid,tmp;
	bool OK=false;
	int st;
	
	while (cin>>p>>q>>r>>s>>t>>u){
		//cout<<solve(0.7071)<<endl;
		
		double x=solve(0.0),y=solve(1.0);
		if ((x>EPS && y>EPS) || (x<-EPS && y<-EPS)){puts("No solution");continue;}
		if (fabs(x)<EPS){printf("%.4lf\n",0.0);continue;}
		if (fabs(y)<EPS){printf("%.4lf\n",1.0);continue;}

		OK=false;
		lo=0;hi=1;
		mid=0;
		while ((lo-hi)<-EPS2){
			tmp=mid;
			mid=(lo+hi)/2;
			
			if (fabs(tmp-mid)<EPS2)
				break;
			st=solve(mid);
			if(st==0){OK=true;break;}
			else if (st==1)lo=mid;
			else hi=mid;
			
		}

		if (OK)printf("%.4lf\n",mid);
		else puts("No solution");

	}

	return 0;
}
