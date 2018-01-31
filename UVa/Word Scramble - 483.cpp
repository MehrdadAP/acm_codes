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

void strRevers(char* s)
{
	for (int i=0;s[i]!=NULL;i++);


}

int main ()
{
	string s;
	char sent[10000];
	while (gets(sent)!=NULL)
	{
		int i=0;
		while (sent[i]!=NULL)
		{
			s="";
			while (sent[i]!=NULL && sent[i]!=' ')
			{
				s+=sent[i];
				i++;
			}
			if (sent[i]==' ')i++;
			reverse(s.begin(),s.end());
			cout<<s;
			if (sent[i]!=NULL)cout<<" ";
			else
				cout<<endl;
		}

	}


	return 0;
}