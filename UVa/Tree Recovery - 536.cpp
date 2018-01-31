#include <iostream>
#include <string>

using namespace std;
#define MAX 28



void post(string pre,string in)
{
	if (in.size()==0)
		return ;
	if (in.size()==1)
	{
		cout<<in;
		return ;
	}
	string Lin;
	string Rin;
	string Lpre;
	string Rpre;
	int i;
	for (i=0;in[i]!=pre[0];i++)
	{
		Lin[i]=in[i];
		Lpre[i]=pre[i+1];
	}
	for (int k=0;k<pre.size()-i;k++)
	{
		Rin[k]=in[i+1];
		Rpre[k]=pre[i+1];
		i++;
	}
	post(Lpre,Lin);
	post(Rpre,Rin);
	cout<<pre[0];
	return ;
}



int main()
{
	string in,pre;
	while (cin>>pre)
	{
		cin>>in;
		post(pre,in);
		cout<<endl;
	}

	return 0;
}