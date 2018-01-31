									/*ba yade oo */
//AC Code
//just use map , double precison issue ->convert to int

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cstring>
#include <sstream>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <map>



using namespace std;

#define PI 3.14159265358997
#define absol(x) ((x)>(0) ? (x):(-1)*(x))
#define pow2(x) (x*x)
#define EPS 1e-7
#define INF 100000000
#define MAX 10000
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

map<string,int> mp;

int main ()
{
	int P,G;
	string name,name2,op1,op2;
	double val;
	int ival;
	cin>>P>>G;

	for (int i=0;i<P;i++){
		cin>>name>>val;
		mp[name]=val*10;
	}

	for (int i=1;i<=G;i++){
		name=name2="";
		cin >> name >> op1 ;
		int x=0;
		x+=mp[name];
		while (op1=="+"){cin>>name2;x+=mp[name2];cin>>op1;}
		cin>>ival;
		ival*=10;
		op2=op1;

		bool YES;


		if (op2==">") YES=(x>ival);
		else if (op2==">=") YES=( x>=ival);
		else if (op2=="<") YES = (x<ival);
		else if (op2=="<=") YES = ( x<=ival);
		else if (op2=="=") YES = ( x==ival);

		if (YES)printf("Guess #%d was correct.\n",i);
		else	printf("Guess #%d was incorrect.\n",i);
	}
	
	//system("pause");

	return 0;
}
