#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string &str , int st , int len , vector<string>& ans)
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

	solve(str , st+1 , len , ans);
	str.insert(st+1 , "_");
	solve(str , st+2 , len+1 , ans);
	str.erase(st+1 , 1);
}

int main()
{
	string s;
	cin >> s;

	int n = s.length();

	vector<string> ans;

	solve(s , 0 , n , ans);

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
	
}