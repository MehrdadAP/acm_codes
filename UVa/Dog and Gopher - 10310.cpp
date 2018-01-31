									/*ba yade oo */

//AC-code

//note : while (scanf("%d",&N)!=EOF) doesn't work and we should 
//use while (scanf(...)==1)


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
#define MAX 1009
#define EPS 1e-7


struct POINT
{
	double x,y;
}g,d,hole[MAX];

inline float dist2(POINT a,POINT b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline float dist(POINT a,POINT b)
{
	return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

int main ()
{
	int N;
	bool flag;
	double disGopher,disDog;
	while (scanf("%d",&N)==1)
	{
		flag=false;
		scanf("%lf %lf %lf %lf",&g.x,&g.y,&d.x,&d.y);
		//cin>>g.x>>g.y>>d.x>>d.y;
		
		for (int i=0;i<N && !flag;i++)
		{
			scanf("%lf %lf",&hole[i].x,&hole[i].y);
			if (flag)continue;

			disGopher=dist2(g,hole[i]);
			disDog=dist2(d,hole[i]);
			if (4.0*disGopher-disDog<=EPS)
			{
				flag=true;
				printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n",hole[i].x,hole[i].y);
			}
			//cin>>hole[i].x>>hole[i].y;
		}
/*
		for (i=0;i<N;i++)
		{
			disGopher=dist2(g,hole[i]);
			disDog=dist2(d,hole[i]);
			if (4.0*disGopher-disDog<=EPS)
			{
				flag=true;
				break;
			}

		}*/

		if (!flag)
			puts("The gopher cannot escape.");
	}

	return 0;

}