#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define Num(A) (A[3]+10*A[2]+100*A[1]+1000*A[0])
#define Inc(a) ((a+1)%10)
#define Dec(a) ((a+9)%10)

typedef pair<int,int> Pair;
vector<int> List[10000];

int BFS(bool F[], int S, int D)
{
	queue<Pair> Q;
	int level, current;
	Q.push(Pair(S,0));

	while (!Q.empty())
	{
		current = Q.front().first;
		level = Q.front().second;
		Q.pop();
		for (int i = 0; i<List[current].size(); ++i)
		{
			if (List[current][i] == D) return level+1;
			if (!F[List[current][i]])
			{
				F[List[current][i]] = true;
				Q.push(Pair(List[current][i],level+1));
			}
		}
	}
	return -1;
}

void init()
{
	int A[4], B[4], x;
	for (int i = 0; i<10000; ++i)
	{
		x = i;
		A[3] = B[3] = x%10; x/=10;
		A[2] = B[2] = x%10; x/=10;
		A[1] = B[1] = x%10; x/=10;
		A[0] = B[0] = x%10;
		for (int j = 0; j<4; ++j)
		{
			B[j] = Inc(A[j]);
			x = Num(B);
			List[i].push_back(x);
			List[x].push_back(i);
			B[j] = A[j];
		}
	}
}

int main()
{
	int N, S, D, Start[4], Dest[4], Ban[4], T;
	init();
	scanf("%d", &T);
	for (int t = 0; t<T; ++t)
	{
		scanf("%d%d%d%d", &Start[0], &Start[1], &Start[2], &Start[3]);
		scanf("%d%d%d%d", &Dest[0], &Dest[1], &Dest[2], &Dest[3]);
		S = Num(Start);
		D = Num(Dest);
		bool F[10000] = {false};
		F[S] = true;
		scanf("%d", &N);
		for (int i = 0; i<N; ++i)
		{
			scanf("%d%d%d%d", &Ban[0], &Ban[1], &Ban[2], &Ban[3]);
			F[Num(Ban)] = true;
		}
		if (S == D)
			printf("0\n");
		else if (F[D])
			printf("-1\n");
		else
			printf("%d\n", BFS(F, Num(Start), Num(Dest)));
	}
//	system("PAUSE");
	return 0;
}
