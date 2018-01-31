#include <iostream>

using namespace std;

int n;

int BinaryDance(int l,int r)
{
	if (l==r)
		return 0;
	else if (r-l==1)
		return l*r;

	int left=BinaryDance(l,(l+r)/2);
	int right=BinaryDance(((l+r)/2)+1,r);
	return left+right;
}

int main ()
{

	while (cin>>n)
		cout<<BinaryDance(1,n)<<endl;
	
	return 0;
}