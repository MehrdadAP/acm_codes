#include <iostream>

using  namespace std;

int main ()
{
	int n,k,res;
	while (cin>>n>>k)
	{
		res=n;
		while (n>=k)
		{
			res+=n/k;
			n=(n/k)+n%k;
	
		}
		cout<<res<<endl;
	}
	return 0;
}

