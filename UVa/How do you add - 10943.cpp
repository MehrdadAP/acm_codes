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
#define MAX 110
#define MOD 1000000



int main ()
{

	int N,K;
	int t[MAX][MAX]={0};
	for (int i=0;i<MAX;i++)
	{
		t[i][1]=1;
		t[0][i]=1;
	}


	for (int i=1;i<MAX;i++)
		for (int k=2;k<MAX;k++)
			for (int s=0;s<=i;s++)
				t[i][k]=(t[i][k]+t[i-s][k-1])%MOD;
	while (scanf("%d %d",&N,&K))
	{
		if (N==0 && K==0)
			break;
		printf("%d\n",t[N][K]);
	}

	return 0;

}