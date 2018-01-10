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

typedef vector<int> vi;
typedef vector<long long int> vlli;

long long int fibo[92];


int binSearch(int f,int l,long long int x)
{
	if (f>l)
		return -1;

	int mid=(f+l)/2;

	if (fibo[mid]==x)
		return mid;

	if (x>fibo[mid])
		if (x<fibo[mid+1])
			return mid;
		else
			return binSearch(mid+1,l,x);
	if (x<fibo[mid])
		if (x>fibo[mid-1])
			return mid-1;
		else
			return binSearch(f,mid-1,x);

}


vlli ind,val;


int main ()
{

	fibo[1]=1;
	fibo[2]=2;
	for (int i=3;i<=90;i++)
		fibo[i]=fibo[i-1]+fibo[i-2];

	long long int N,tmp;
	bool first=true;
	while (cin>>N)
	{
		
		
		ind.clear();
		val.clear();
		cout<<N<<endl;
		
		tmp=N;
		while (tmp>0)
		{
			int index=binSearch(1,90,tmp);
			if (index==-1)
				index=90;
			ind.push_back(index);
			val.push_back(fibo[index]);
			tmp-=fibo[index];
		}
		
		for (int i=0;i<ind.size();i++)
			cout<<ind[i]<<" ";

		cout<<endl;
		for (int i=0;i<val.size();i++)
			cout<<val[i]<<" ";
		cout<<"\n\n";
	}


	return 0;
}