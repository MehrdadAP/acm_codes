									/*ba yade oo */
/*
AC Code

Problem : UVA - 10954 - Add All
Categoy : Simple DS- PQ
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
priority_queue<int> pq;


int main ()
{

	int N,x,ans;
	while (cin>>N,N!=0)
	{
		while (!pq.empty())pq.pop();
		ans=0;
		for (int i=0;i<N;i++)
		{
			cin>>x;
			pq.push(-1*x);
		}

		for (int i=0;i<N-1;i++)
		{
			int x=pq.top();pq.pop();
			int y=pq.top();pq.pop();

			ans+=(-1*(x+y));
			pq.push(x+y);
		}

		printf("%d\n",ans);
	}


	return 0;
}