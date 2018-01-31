									/*ba yade oo */

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <cstring>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 0x7FFFFFFF
#define EPS 1e-7

struct POINT 
{
	double x,y;
};

inline double dis_point_to_line(POINT a,POINT b,POINT c)//c is POINT outside line
{
	double A=c.x-a.x;
	double B=c.y-a.y;
	double C=b.x-a.x;
	double D=b.y-a.y;
	if (C==0 && D==0)
		return 0;
	double dist=(double)absol(A*D-C*B)/sqrt((double)C*C+D*D);
	return dist;
}

inline double dist2(POINT a,POINT b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main ()
{

	int tc;
	scanf("%d",&tc);
	POINT A,B;
	double r;
	POINT center;
	center.x=0;center.y=0;
	//double AT,BT,; 
	double AO2,BO2,AT2,BT2,AB2,z1,z2,o1,o2,arc;
	while (tc--)
	{
		//scanf("%d %d %d %d %d",&A.x,&A.y,&B.x,&B.y,&r);
		scanf("%lf %lf %lf %lf %lf",&A.x,&A.y,&B.x,&B.y,&r);
		double disPoint=dis_point_to_line(A,B,center);
		if (A.x==B.x && A.y==B.y)
		{
			printf("%.3lf\n",0);
			continue;
		}
		if (disPoint-r>=EPS)
		{
			printf("%.3lf\n",sqrt(dist2(A,B)));
			continue;
		}

		AO2=dist2(center,A);
		BO2=dist2(center,B);

		AT2=AO2-r*r;
		BT2=BO2-r*r;
		AB2=dist2(A,B);

		//z1=atan((sqrt)(AT2/r*r));
		//z2=atan((sqrt)(BT2/r*r));

		z1=atan2(sqrt(AT2),r);
		z2=atan2(sqrt(BT2),r);

		o1=acos((AO2+BO2-AB2)/(2*sqrt(AO2*BO2)))-z1-z2;
		o2=2*PI-2*z1-2*z2-o1;

		double angle=min(o1,o2);
		if (angle<0 || absol(angle)<EPS)
			printf("%.3lf\n",sqrt(dist2(A,B)));
		else
			printf("%.3lf\n",sqrt(AT2)+sqrt(BT2)+angle*r);
		
	}
	return 0;

}

/*
200
-5 0 5 -1 5
10 10 -10 -10 5
13 15 17 6 3
1 9 12 6 5
3 19 10 7 2
16 12 6 0 6
2 9 7 8 1
15 7 3 2 1
2 11 16 13 7
4 19 1 13 9
10 15 4 18 7
3 5 7 6 3
1 9 2 6 5
3 9 0 7 2
6 2 6 0 6
2 9 7 8 1
5 7 3 2 1

--OUt:
14.734
30.071
9.849
11.402
13.892
15.620
5.099
13.000
14.142
6.708
6.708
4.123
3.162
3.606
2.000
5.099
5.385
*/