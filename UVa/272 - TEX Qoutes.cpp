									/*ba yade oo */

/*
AC Code
problem : UVA - 272 - TEX Qoutes
points :I think it can't output in a strinbg and then output it
		print the output simultanously

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

string s;


int main ()
{
	int k=0;
	bool end=false;
	char ch;
	//cout<<char (39)<<endl;
	//cout<<char (96)<<endl;
	while (scanf("%c",&ch)==1)
	{
		if (ch=='"')
			if (end==false)
			{
				printf("%c%c",char(96),char(96));
				end=true;
			}
			else
			{
				printf("%c%c",char(39),char(39));
				end=false;
				
			}
		else
		{
			printf("%c",ch);
		}
			s+=ch;
	}
	return 0;
}