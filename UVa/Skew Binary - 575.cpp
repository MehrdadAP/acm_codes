#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))

int powFast(int x,int a)
{
	int ans;
	if (a==1)
		return x;
	if (a%2==0)
	{
		ans=powFast(x,a/2);
		return ans*ans;
	}
	else
	{
		return x*powFast(x,a-1);
	}
}
int main ()
{
	string str;
	int ans=0;
	while (1)
	{
		ans=0;
		cin>>str;
		if (str=="0")
			break;
		
		int len=str.length();
		for (int i=0;i<len;i++)
		{
			ans+=(str[i]-'0')*(powFast(2,len-i)-1);
		}
		cout<<ans<<endl;
	}

	return 0;

}
