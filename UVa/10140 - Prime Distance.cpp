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
#define MAXP 2147483647
typedef vector<int> vi;

vector<int> primes;
void sieve()
{
	
	primes.push_back(1);
	for (int i=2;i<=MAXP;i++)
		if (isprime[i])
		{
			primes.push_back(i);
			for (int j=i*i;j<=MAXP;j+=i)
				isprime[j]=false;
		}

}

int binSearch(int f,int l,int x,bool st)//st true for lower bound
{

	if (f<l)
		return -1;

	int mid=(f+l)/2;

	if (primes[mid]==x)
		return mid;

	if (x<primes[mid])
	{
		if (st && x>primes[mid-1])
			return mid-1;
		else if (!st && x>primes[mid-1])
			return mid;
		else
			return binSearch(f,mid-1,x,st);
			
	}
	else
	{
		if (st && x<primes[mid+1])
			return mid;
		else if (!st && x<primes[mid+1])
			return mid+1;
		else
			return binSearch(mid+1,l,x,st);

	}
	
}
int main ()
{
	int L,U,pnum;
	sieve();
	pnum=primes.size();

	while (cin>>L>>U)
	{
		int indL=binSearch(1,pnum,L,false);
		int indU=binSearch(1,pnum,L,true);


	}
	cin>>L;
	return 0;
}