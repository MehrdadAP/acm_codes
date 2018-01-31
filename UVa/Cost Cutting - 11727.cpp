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


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 0x7FFFFFFF



int main ()
{

	int tc,a[3];
	cin>>tc;
	for (int t=1;t<=tc;t++)
	{
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		printf("Case %d: %d\n",t,a[1]);
	}


	return 0;

}