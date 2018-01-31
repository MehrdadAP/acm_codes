									/*ba yade oo */
//AC Code
//just for using PQ :D
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
typedef pair<pii,int> piii;
typedef long long int lli;


priority_queue<piii> pq;


int main ()
{

	string cmd;
	int x,y,K;
	while (cin>>cmd && cmd[0]=='R'){
		cin>>x>>y;
		pq.push(piii(pii(-y,-x),-y));
	}

	cin>>K;

	for (int i=0;i<K;i++){

		cout<<-pq.top().first.second<<endl;
		
		pq.push( piii(pii( pq.top().first.first+pq.top().second,pq.top().first.second) , pq.top().second) );
		pq.pop();
	}

	//system("pause");

	

	return 0;
}
