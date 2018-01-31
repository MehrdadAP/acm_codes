									/*ba yade oo */
//DP Method
//t(i,j) ==> is the best score achieved by i'th course and j time
//O(n*m*m)


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
#define COURSE 20
#define TIME 120

int val[COURSE][TIME],t[COURSE][TIME];


int main ()
{
	int tc,N,H;
	scanf("%d",&tc);
	while (tc--)
	{
		
		scanf("%d %d",&N,&H);
		for (int i=1;i<=N;i++)
			for (int j=1;j<=H;j++)
				scanf("%d",&val[i][j]);

		for (int j=1;j<=H;j++)
			t[1][j]=(val[1][j]>=5) ? val[1][j]:0;


		for (int i=2;i<=N;i++)//i course
			for (int j=1;j<=H;j++)// j time
			{
				t[i][j]=0;
				for (int k=1;k<=H;k++)//test all times for i'th course
					if (j-k>0 && val[i][k]>=5 && t[i-1][j-k]!=0)
						t[i][j]=max(t[i][j],t[i-1][j-k]+val[i][k]);
			}
	
		if (t[N][H]==0)
			puts("Peter, you shouldn't have played billiard that much.");
		else
			printf("Maximal possible average mark - %.2lf.\n",((double)t[N][H]/N)+1e-9);
	}

	return 0;

}