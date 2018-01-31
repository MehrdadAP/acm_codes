#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 1e8
#define MAX 500

int a[MAX][MAX];

int main ()
{
	string street[MAX];
	int n=0;
	int ind=0;
	int end;
	while (cin>>street[ind++])
	{

		if (street[ind-1]=="deadend")
		{
			for (int i=0;i<ind;i++)
			{
				int endi=street[i].size();
				for (int j=i+1;j<ind;j++)
				{
					int endj=street[j].size();
					if (street[i][0]==street[j][0] || street[i][0]==street[j][endj]
					|| street[i][endi]==street[j][0] || street[i][endi]==street[j][endj])
						a[i][j]=
				}
			}
		}
			
	}

	return 0;

}
