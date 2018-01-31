									/*ba yade oo */
//AC Code
//Greedy approache , also can be solved by BT

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
#define MAX 10
#define MODE 1000000007

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long int lli;

vector<int> sp;
vector<int> cham[MAX];

int main ()
{
	int C,S,TC=0;
	double bal,avg;
	while (cin>>C>>S){
		avg=0;bal=0;
		sp.clear();
		sp.resize(S+10);
		for (int i=0;i<S;i++){cin>>sp[i];avg+=sp[i];}
		for (int i=0;i<C;i++)cham[i].clear();
		
		avg/=(double)C;
		sort(sp.rbegin(),sp.rend());
		int i;
		for (i=0;i<min(S,C);i++)
			cham[i].push_back(sp[i]);
		if(S>C)
			for (int k=C-1;i<S;k--,i++)
				cham[k].push_back(sp[i]);


		printf("Set #%d\n",++TC);

		for (i=0;i<C;i++){

			printf(" %d:",i);
			if (cham[i].size()==1){cout<<" "<<cham[i][0]<<endl;bal+=fabs(cham[i][0]-avg);}
			else if (cham[i].size()==2) {cout<<" "<<cham[i][0]<<" "<<cham[i][1]<<endl;bal+=fabs(cham[i][0]+cham[i][1]-avg);}
			else {cout<<endl;bal+=fabs(avg);}

		}
		printf("IMBALANCE = %.5lf\n\n",bal);

	}

	return 0;
}
