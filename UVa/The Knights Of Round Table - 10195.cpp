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

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 0x7FFFFFFF
#define EPS 1e-7
#define pow2(x) (x*x)

int main ()
{

	double a,b,c;
	double p,area,r;

	while (scanf("%lf %lf %lf",&a,&b,&c)==3)//ls
	{
		p=(a+b+c)/2.0;
		area=sqrt(p*(p-a)*(p-b)*(p-c));
		r=(2*area)/(a+b+c);
		if (a*b*c==0)
			r=0;
		printf("The radius of the round table is: %.3lf\n",r+EPS);
	}
	return 0;

}