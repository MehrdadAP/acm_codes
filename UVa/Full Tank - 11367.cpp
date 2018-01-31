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
#define MAX 1020

int g[MAX][MAX];
int t[MAX];
int w[MAX][MAX];

int main ()
{
	int V,E,v1,v2,w1,query;

	scanf("%d %d",&V,&E);
	for (int i=0;i<V;i++)
		scanf("%d",&t[i]);
	for (int i=0;i<E;i++)
	{
		scanf("%d %d %d",&v1,&v2,&w1);
		g[v1][++g[v1][0]]=v2;
		g[v2][++g[v2][0]]=v1;
		w[v1][v2]=w[v2][v1]=w1;
	}

	return 0;

}
