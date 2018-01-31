//543 - Goldbach's Conjecture
//prime number
//the point is : use a optimize code for finding is_prime function


#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n==2)
		return true;
	if (n==1)
		return false;
	if (n%2==0)
		return false;
	for (int i=3;i*i<=n;i+=2)
		if (n%i==0)
			return false;
	return true;

}

void f(int n)
{
	for (int i=n-3;i>(n/2)-1;i--)
		if (isPrime(i) && (i%2) && isPrime(n-i) && ((n-i)%2))
		{
			printf("%d = %d + %d\n",n,n-i,i);
			return;
		}
	cout<<"Goldbach's conjecture is wrong.\n";
}
int main()
{
	int n;
	int a,b;
	while (cin>>n,n!=0)
		f(n);
	


	return 0;
}