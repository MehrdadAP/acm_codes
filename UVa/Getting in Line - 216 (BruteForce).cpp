									/*ba yade oo */
//AC Code
//BruteForce
//there is a DP solution :D

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
#define MAX 10
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

pii p[MAX];
vi ans,arr;
int N;

double dist(int i,int j)
{
	double ret= ((p[i].first-p[j].first)*(p[i].first-p[j].first)) + ( (p[i].second-p[j].second)*(p[i].second-p[j].second) );
	ret=sqrt(ret);
	return ret;

}

double calc()
{
	double ret=0;
	for (int i=0;i<N-1;i++)
		ret+=dist(arr[i],arr[i+1]);

	return ret;
}



int main ()
{

	int x,y,TC=0;
	while (cin>>N,N){

		arr.clear();
		for (int i=0;i<N;i++){
			cin>>p[i].first>>p[i].second;
			arr.push_back(i);
		}

		double mini=INF;

		do{

			double tmp=calc();
			if (tmp<mini){
				mini=tmp;
				ans.clear();
				ans.resize(N+1);
				copy(arr.begin(),arr.end(),ans.begin());
			}


		}while (next_permutation(arr.begin(),arr.end()));
		

		puts("**********************************************************");
		printf("Network #%d\n",++TC);

		double x,sum=0;
		for (int i=0;i<N-1;i++){
			x=dist(ans[i],ans[i+1])+16.0;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",p[ans[i]].first,p[ans[i]].second
												,p[ans[i+1]].first,p[ans[i+1]].second,x);
			sum+=x;
		}

		printf("Number of feet of cable required is %.2lf.\n",sum);

	}

	return 0;
}
