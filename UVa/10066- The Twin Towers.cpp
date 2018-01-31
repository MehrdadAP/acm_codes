//Problem 10066:The Twin Towers


#include <iostream>
 using namespace std;
#define MAX 102
int a[MAX],b[MAX];
int t[MAX+1][MAX+1];


 int main ()
 {
	 int n1,n2;
	 int cnt=1;
	 while (cin>>n1>>n2,n1!=0 || n2!=0)
	 {
		 for (int i=1;i<=n1;i++)
			 cin>>a[i];
		 for (int i=1;i<=n2;i++)
			 cin>>b[i];
		// init_t(max(n1,n2));
		for (int i=1;i<=n1;i++)
			t[i][0]=0;
		for (int j=0;j<=n2;j++)
			t[0][j]=0;

		 for (int i=1;i<=n1;i++)
			 for (int j=1;j<=n2;j++)
				 if (a[i]==b[j])
				 {
					 t[i][j]=t[i-1][j-1]+1;
				 }
				 else
				 {
					 t[i][j]=max(t[i-1][j],t[i][j-1]);
				 }
		 cout<<"Twin Towers #"<<cnt++<<endl;
		 cout<<"Number of Tiles : "<<t[n1][n2]<<endl<<endl;			
	 }
	 return 0;

 }