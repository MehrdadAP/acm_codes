									/*ba yade oo */
//AC COde
//just do the simple brute force


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
#define INF 100000000
#define MAX 10000
#define MODE 1000000007

typedef vector<int> vi;
typedef long long int lli;

int S,N;

set<string> st1;
set<string> st2;
string word;


void calc(int i)
{

	if (i==S)
	{
		st1.insert(word);
		return;
	}

	if (word[i]=='*')
	{
		word[i]='1';
		calc(i+1);
		word[i]='0';
		calc(i+1);
		word[i]='*';
	}
	else
		calc(i+1);

}

int main ()
{

	
	
	while (cin>>S>>N , N || S)
	{
		st2.clear();
		st1.clear();

		bool valid=true;
		for (int i=0;i<N;i++)
		{
			cin>>word;
			if (valid==false)continue;

			string tmp="";
			for (int k=0;k<S;k++)
				if (word[k]=='1')
					tmp+='0';
				else
					tmp+=word[k];

			if (st2.find(tmp)!=st2.end())
				valid=false;
			else
				st2.insert(tmp);

			calc(0);
		}

		if (valid==false)puts("NO");
		else printf("YES %d\n",st1.size());

	}

	puts("YES 0");
	return 0;
}
