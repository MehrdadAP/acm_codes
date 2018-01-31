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
#define MAX 55

long long int t[MAX][MAX][MAX];

int main ()
{

	for (int i=0;i<MAX;i++)
		t[0][0][i]=1;

	for (int i=1;i<MAX;i++)
		for (int j=1;j<MAX;j++)
			for (int m=1;m<MAX;m++)
				for (int k=1;k<=m && i-k>=0;k++)
					t[i][j][m]+=t[i-k][j-1][m];

	int N,K,M;
	while (scanf("%d %d %d",&N,&K,&M)==3)
		printf("%lld\n",t[N][K][M]);
	return 0;

}