									/*ba yade oo */


/*
AC Code
Greedy Solution


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
	string a,b;

	while (cin>>a>>b)
	{
		int i=0;
		int j=0;

		int sza=a.size();
		int szb=b.size();

		while (i!=sza && j!=szb)
		{
			if (a[i]==b[j])i++;
			j++;
		}

		if (i==sza)puts("Yes");
		else puts("No");
	}

	return 0;
}