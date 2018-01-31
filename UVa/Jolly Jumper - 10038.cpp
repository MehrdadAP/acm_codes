//Jolly Jumper


#include <iostream>
#include <stdio.h>


using namespace std;
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define MAX 3002
int a[MAX];
bool b[MAX];


int main ()
{
	int n;
	while (cin>>n)
	{
		for (int i=0;i<=MAX;i++)
			b[i]=false;
			
		for (int i=0;i<n;i++)
			cin>>a[i];
			
		bool flag=true;
		for (int i=0;i<n-1;i++)
			b[absol(a[i]-a[i+1])]=true;
		for (int i=1;i<=n-1;i++)
			if (b[i]==false)
			{
				flag=false;
				break;
			}
		
		if (flag==true || n==1)
			cout<<"Jolly\n";
		else
			cout<<"Not jolly\n";
	}
	return  0;
}
