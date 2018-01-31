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

using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 0x7FFFFFFF
#define MAX 110

double g[MAX][MAX];
int main ()
{

	int V,E,v1,v2,w1;
	while (scanf("%d",&V),V!=0)
	{
		scanf("%d",&E);
		for (int k=1;k<=V;k++)
			for (int i=1;i<=V;i++)
				for (int j=1;j<=V;j++)
					if (i==j)
						g[i][j]=1;
					else
						g[i][j]=INF;
		

		for (int i=0;i<E;i++)
		{
			scanf("%d %d %d",&v1,&v2,&w1);
			g[v1][v2]=1/(w1/100.00);
			g[v2][v1]=1/(w1/100.00);
		}

		for (int k=1;k<=V;k++)
			for (int i=1;i<=V;i++)
				for (int j=1;j<=V;j++)
					g[i][j]=min(g[i][j],g[i][k]*g[k][j]);
						
		printf("%.6lf\n",(1/g[1][V])*100);

	}
	return 0;

}
