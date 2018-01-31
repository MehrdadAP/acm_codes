									/*ba yade oo */


/*
AC Code

Problem : UVA - 573 - The Snail
Category : Adhoc
Tricky point : "The snail never climbs a negative distance. 
If the fatigue factor drops the snail's climbing distance below zero, the snail does not climb at all that day"

Author : Mehrdad AP

*/
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
#define INF 0x7FFFFFFF
#define MAX 1002

typedef vector<int> vi;


int main ()
{
	int H,U,D,F;
	while (cin>>H>>U>>D>>F , H!=0)
	{
		int day=0;
		float dist=0;
		float up=U,neg=((float)F*U)/100.0;
		bool flag=false;
		while (!(dist>H || (dist<0 && flag)))
		{
			flag=true;
			day++;
			dist+=up;
			if (dist>H)break;
			dist-=D;
			if (up>0)up-=neg;
		}

		if (dist>0)
			cout<<"success on day "<<day<<endl;
		else
			cout<<"failure on day "<<day<<endl;
	}


	return 0;
}