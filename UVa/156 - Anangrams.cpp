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

string a[MAX],b[MAX];
string ans[MAX];
int main ()
{
	string str;
	int ind=0,ansInd=0;
	while (cin>>str)
	{
		if (str=="#")break;
		b[ind]=str;
		for (int i=0;i<str.size();i++)
			str[i]=tolower(str[i]);
		sort(str.begin(),str.end());
		a[ind++]=str;
	}
	for (int i=0;i<ind;i++)
	{
		bool flag=true;
		for (int j=0;j<ind && flag;j++)
		{
			if (i==j)continue;
			if (a[i]==a[j])flag=false;
		}
		if (flag)
			ans[ansInd++]=b[i];
	}


	sort(ans,ans+ansInd);
	for (int i=0;i<ansInd;i++)
		cout<<ans[i]<<endl;
	//system("pause");
	return 0;
}