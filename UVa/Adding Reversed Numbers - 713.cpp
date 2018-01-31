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

void strRev(char* ch)
{
	int len=strlen(ch);
	for (int i=0;i<len/2;i++)
		swap(ch[i],ch[len-i-1]);
}
string  add2Char(char* ch1,char* ch2)
{
	int len1=strlen(ch1);
	int len2=strlen(ch2);
	string ans;
	int carry=0;
	int i1=len1-1;
	int i2=len2-1;
	int a,b;
	while(i1!=-1 || i2!=-1 || carry!=0)
	{
		if (i1==-1)
			a=0;
		else
			a=ch1[i1--]-'0';

		if (i2==-1)
			b=0;
		else
			b=ch2[i2--]-'0';

		ans+=(a+b+carry)%10+'0';
		carry=(a+b+carry)/10;
	}

	return ans;
}
void intToChar(int n,char* c)
{
	int i=0;
	while (n>0)
	{
		c[i++]=n%10+'0';
		n=n/10;
	}

	c[i]='\0';

}
int main ()
{
	string str;
	int tc;cin>>tc;
	char ch1[203],ch2[203];
	int a,b;
	string ans;
	while(tc--)
	{
		cin>>ch1>>ch2;
		strRev(ch1);
		strRev(ch2);
		ans=add2Char(ch1,ch2);
		if (ans[0]=='0')
		{
			for (int i=ans.rfind("0")+1;i<ans.length();i++)
				cout<<ans[i];
			cout<<endl;
		}
		else
			cout<<ans<<endl;

	}

	return 0;

}