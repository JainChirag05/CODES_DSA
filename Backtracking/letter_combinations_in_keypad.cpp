#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , int i , unordered_map<char,string> mp, string &str , vector<string> &ans)
{
	if(i == s.length())
	{
		ans.push_back(str);
		return;
	}

	string curr = mp[s[i]];

	for(int j = 0;j<curr.length();j++)
	{
		str.push_back(curr[j]);
		solve(s,i+1,mp,str,ans);
		str.pop_back();
	}
}

int main()
{
	string s;
	cin >> s;

	if(s.length() == 0)
	{
		cout << "None";
	}

	unordered_map<char , string> mp;

	mp['2'] = "abc";
	mp['3'] = "def";
	mp['4'] = "ghi";
	mp['5'] = "jkl";
	mp['6'] = "mno";
	mp['7'] = "pqrs";
	mp['8'] = "tuv";
	mp['9'] = "wxyz";

	vector<string> ans;
	string str = "";

	solve(s , 0 , mp , str , ans);

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
	
}