#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define MAX 1002

string word[MAX],wordS[MAX],ans[MAX];

void sort_string(string &s)
{
	for (int i=0;i<s.size()-1;i++)
		for (int j=i+1;j<s.size();j++)
			if (s[i]>s[j])
				swap(s[i],s[j]);

}

int main()
{
	int cnt=0;
	while (cin>>word[cnt],word[cnt]!="#")
	{
		string s=word[cnt];
		for (int i=0;i<s.size();i++)
			s[i]=(char)tolower(s[i]);
		sort_string(s);
		//cout<<s;
		wordS[cnt]=s;
		cnt++;
		
	}
	int res=0;
	for (int i=0;i<cnt;i++)
	{
		bool flag=false;
		for (int j=0;j<cnt;j++)
		{
			if (i==j)
				continue;
			if (wordS[i]==wordS[j])
			{
				flag=true;
				break;
			}
		}
		if (!flag)
			ans[res++]=word[i];
	}
	sort(ans,ans+res);
	for (int i=0;i<res;i++)
		cout<<ans[i]<<endl;
	


	//system("pause");
	return 0;

}
