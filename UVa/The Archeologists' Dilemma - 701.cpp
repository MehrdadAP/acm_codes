#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <cstring>


using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define INF 1e8

void intToString(int n,char st[])
{
	int len=0;
	while (n>0)
	{
		st[len++]=n%10+'0';
		n=n/10;
	}
	st[len]='\0';
}


long long int power(int a,int x)
{
	long long int ans;
	if (x==0)
		return 1;
	if (x%2==0)
	{
		ans=power(a,x/2);
		return ans*ans;
	}
	else
		return a*power(a,x-1);

}

int intLen(long long int n)
{
	int ans=0;
	while (n>0)
	{
		n=n/10;
		ans++;
	}
	return ans;
}
void strrev2(char ch[])
{
	int len=strlen(ch);
	for(int i=0;i<len/2;i++)
		swap(ch[i],ch[len-i-1]);

}
int main ()
{
	char s[]="X=10 Y=19";
	int x,y;
	sscanf(s,"X=%d Y=%d",&x,&y);
	cout<<x<<" " <<y<<endl;

	long long int n;
	int len;
	bool flag,flag2;
	char str[65][65];
	char tStr[65];
	long long pow2[65];
	for (int i=0;i<64;i++)
	{
		pow2[i]=power(2,i);
		intToString(pow2[i],str[i]);
		strrev2(str[i]);

	}
	while (cin>>n)
	{
		flag=false;
		len=intLen(n);
		intToString(n,tStr);
		strrev2(tStr);
		int i,j;
		for (i=0;i<64 && !flag;i++)
		{
			
			if (2*len<strlen(str[i]))
			{
				flag2=true;
				for (j=0;j<len && flag2;j++)
					if (tStr[j]!=str[i][j])
						flag2=false;
				if (flag2)
					flag=true;
			}
		}
		if (flag2 && i!=64)
			printf("%d\n",i-1);
		else
			printf("no power of 2\n");
	}
	
	
	return 0;

}
