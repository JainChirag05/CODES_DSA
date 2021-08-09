#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string &str, int st , int len ,vector<string>& ans)
{
	set<string> s;

	if(st == len-1)
	{
		if(s.find(str) == s.end())
		{
			ans.push_back(str);
			s.insert(str);
			return;
		}
	}

	for(int i = st;i<len;i++)
	{
		swap(str[st] , str[i]);
		solve(str , st+1 , len , ans);
		swap(str[st] , str[i]);
	}
}

int main()
{
	string s;
	cin >> s;

	int n = s.length();
	vector<string> ans;

	solve(s, 0 , n, ans);

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}	
}