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
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 0x7FFFFFFF
#define MAX 1000008

#define isPrime(x) (( (x)==2 || (x)==3 ||) ? true:( !((x)%2) || !((x)%3) || ((x)==1) ? false : p[(x)/3]))

bool p[MAX/3];
int primes[MAX],pnum,best[MAX],bestVal[MAX];
struct FACTORS
{
	int fac,pow;
}factors[MAX];

void sieve()
{
	int i,j,v,t;
	for (i=0;i<MAX/3;i++)
		p[i]=true;

	v=2;
	for (i=5;i*i<=MAX;i+=v,v=6-v)
		if (p[i/3])
		{
			t=v;
			for (j=i*i;j<MAX;j+=t*i,t=6-t)
				p[j/3]=false;
		}

		primes[0]=2;
		primes[1]=3;
		pnum=2;
		v=2;
		for (i=5 ;i<MAX;i+=v,v=6-v)
			if (p[i/3])
				primes[pnum++]=i;
}

int countDivisors(int n)
{
	int temp=n,i,ans,fnum=0;
	for (i=0;primes[i]*primes[i]<=n;i++)
	{
		if (temp%primes[i]==0)
		{
			factors[fnum].fac=primes[i];
			factors[fnum].pow=0;
			while (temp%primes[i]==0)
			{
				factors[fnum].pow++;
				temp/=primes[i];
			}
			fnum++;
		}
	}
	if (temp!=1)
	{
		factors[fnum].fac=temp;
		factors[fnum++].pow=1;
	}
	ans=1;
	for (i=0;i<fnum;i++)
		ans*=(factors[i].pow+1);
	return ans;
}

int main ()
{
	int N,count;
	sieve();
	best[1]=1;
	bestVal[1]=1;
	for (int i=2;i<MAX;i++)
	{
		best[i]=countDivisors(i);
		bestVal[i]=i;
		if ( best[i-1]>best[i])
		{
			best[i]=best[i-1];
			bestVal[i]=bestVal[i-1];
		}
	}
	int tc;
	scanf("%d",&tc);

	while (tc--)
	{
		scanf("%d",&N);
		printf("%d\n",bestVal[N]);
	}
	
	return 0;

}