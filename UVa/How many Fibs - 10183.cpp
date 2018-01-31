//formula : ans=original circle+number of lines+number of intersections
//			ans=1+C(2,n)+C(4,n)
//BigNumber Needed


#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

typedef vector<int> BIG;


//for assign a string to a BIGnum
void assign(BIG &des,string src)
{
	des.clear();
	for (int i=src.size()-1;i>=0;i--)
		des.push_back(src[i]-'0');
}


//for asaignig two BIGnum

void assign(BIG &des,BIG src)
{
	des.clear();
	for (int i=0;i<src.size();i++)
		des.push_back(src[i]);

}

void flush(BIG &a)
{
	while (a.size()>1 && a[a.size()-1]==0)
		a.pop_back();
}


int comp(BIG l,BIG r)
{
	if (l.size()>r.size())
		return 1;
	if (l.size()<r.size())
		return -1;
	for (int i=0;i<l.size();i++)
	{
		if (l[i]>r[i])
			return 1;
		if (l[i]<r[i])
			return -1;
	}
	return 0;
}
void add(BIG &des,BIG a,BIG b)
{
	int t,len,carry=0,m=max(a.size(),b.size());
	len=b.size();
	for (int i=len+1;i<=a.size();i++)
		b.push_back(0);
	len=a.size();
	for (int i=len+1;i<=b.size();i++)
		a.push_back(0);
	for (int i=0;i<m;i++)
	{
		t=a[i]+b[i]+carry;
		des.push_back(t%10);
		carry=t/10;

	}
	if (carry)
		des.push_back(carry);
	flush(des);
}

void addx(BIG &des,int x)
{
	int i=-1;
	des[0]+=x;
	while (des[++i]>=10)
	{
		if (i+1>des.size())
			des.push_back(0);
		des[i+1]+=des[i]/10;
		des[i]%=10;
	}

}


void sub(BIG &des,BIG a,BIG b)
{
	int t,len,borrow=0,cmp;
	cmp=comp(a,b);
	
	if (cmp==0)
	{
		des.push_back(0);
		return ;
	}
	else if (cmp==-1)
	{
		sub(des,b,a);
		return ;
	}
	len=b.size();
	for (int i=len+1;i<=a.size();i++)
		b.push_back(0);
	len=a.size();
	for (int i=0;i<len;i++)
	{
		t=a[i]-b[i]-borrow;
		if (t<0)
		{
			borrow=1;
			t+=10;
		}
		else
			borrow=0;
		des.push_back(t);
	}
	flush(des);
}
void mul(BIG &des,BIG a,BIG b)
{
	int lena,lenb;

	unsigned int carry,p;
	if (a.size()<b.size())
	{
		mul(des,b,a);
		return ;
	}

	lena=a.size();
	lenb=b.size();
	des.assign(lena+lenb,0);
	for (int i=0;i<lenb;i++)
		if (b[i])
		{
			carry=0;
			for (int j=0;j<lena || carry;j++)
			{
				p=des[i+j]+(j<lena ? b[i]*a[j] : 0)+carry;
				des[i+j]=p%10;
				carry=p/10;
			}
		}
	flush(des);
}

void divx(BIG &des,int x)
{
	int len;
	int i;
	unsigned long long r,p=0;
	len=des.size();
	for (int i=len-1;i>=0;i--)
	{
		p+=des[i];
		des[i]=p/x;
		r=p%x;
		p=r*10;

	}
	flush(des);
}

void print(BIG &a)
{
	flush(a);
	for (int i=a.size()-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;
}

#define MAX 501

BIG a[MAX];

int main()
{
	
	
	assign(a[0],"0");
	assign(a[1],"1");
	for (int i=2;i<MAX;i++)
		add (a[i],a[i-1],a[i-2]);
	int n;
	string a,b;
	while (cin>>a>>b)
	{
		if (a=="0" && b=="0")
			break;

		printf("The Fibonacci number for %d is ",n);
		print(a[n]);
	}
	return 0;
}