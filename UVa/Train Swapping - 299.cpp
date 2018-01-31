//Flip Sort
//find max value and move it to end
//be careful about repeated number
//sec algo : count number of swapping in bubble sort !
#include <iostream>
#include <algorithm>
using namespace std;
int a[1003],b[1003];
int n;
void copy_and_sort()
{
	for (int i=0;i<n;i++)
		b[i]=a[i];
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			if (b[i]<b[j])
				swap(b[i],b[j]);
}

void print_arr(int x[])
{
	cout<<"\n";
	for (int i=0;i<n;i++)
		cout<<x[i]<<" ";

}


int main ()
{
	int tc;
	cin>>tc;
	while (tc--)
	{
		cin>>n;
		int cnt=0;
		for (int i=0;i<n;i++)
			cin>>a[i];
		copy_and_sort();
		for (int i=0;i<n;i++)
			for (int j=0;j<n-i;j++)
			{
				if (b[i]==a[j])
				{
					for (int k=j;k<n-i-1;k++)
					{
						if (a[k]!=a[k+1])
						{
							swap(a[k],a[k+1]);
							cnt++;
						}
						//print_arr(a);
						//cout<<" cnt: "<<cnt;
					}
					break;
				}
			
			}
		printf("Optimal train swapping takes %d swaps.\n",cnt);
	}

	return 0;
}