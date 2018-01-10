									/*ba yade oo */
/*
AC Code

Problem : UVA - 10943 - How do you add?
Category : DP
Complxity : O(NK)
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
#define MAX 102
#define MODE 1000000

typedef vector<int> vi;

int t[MAX][MAX];


int main ()
{
	int N,K;

	memset(t,0,sizeof(t));
	for (int i=1;i<MAX;i++)
		t[0][i]=1;
	t[0][0]=1;


	//first mehtod , O(N^2K)
	/*for (int i=1;i<MAX;i++)
		for (int k=1;k<MAX;k++)
			for (int s=0;s<=i;s++)
				t[i][k]=(t[i][k]+t[s][k-1])%MODE;
*/

	//second Method
	for (int i=1;i<MAX;i++)
		for (int k=1;k<MAX;k++)
			t[i][k]=(t[i-1][k]+t[i][k-1])%MODE;

	while (scanf("%d %d",&N,&K),N || K)
	{
		
		printf("%d\n",t[N][K]);
	}
	return 0;
}