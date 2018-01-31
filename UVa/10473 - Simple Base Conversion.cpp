#include <iostream>
#include <string>
#define MAX 30
using namespace std;

void toDec(string d)
{
	unsigned long int ans=0;
	int r;
	for (int i=2;i<d.size();i++)
	{
		if ((d[i]-'0')<=9)
			r=d[i]-'0';
		else
			r=d[i]-'A'+10;
		ans=ans*16+r;
	}
	cout<<ans<<endl;
}

void toHex(string d)
{
	char ans[MAX];
	int cnt=0;
	int r;
	unsigned long int n=0;
	for (int i=0;i<d.size();i++)
		n=n*10+(d[i]-'0');
	while (n>0)
	{
		r=n%16;
		if (r>=10)
			ans[cnt++]=r-10+'A';
		else
			ans[cnt++]=r+'0';
		n=n/16;
	}
	ans[cnt]=0;
	cnt--;
	for (int i=cnt;i>cnt/2;i--)
		swap(ans[i],ans[cnt-i]);
	
	cout<<"0x"<<ans<<endl;
}
int main ()
{
	string d;
	//scanf("0x%[0-9]",&digit);
	while (cin>>d)
	{
		if (d[0]=='-')
			break;
		if (d[0]=='0')
			toDec(d);
		else
			toHex(d);
	}
	return 0;
}