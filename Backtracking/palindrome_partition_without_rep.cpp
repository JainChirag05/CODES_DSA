#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool palin(string s)
{
	int i = 0;
	int j = s.length() - 1;

	while(i < j)
	{
		if(s[i] != s[j])
		{
			return false;
		}

		i++;
		j--;
	}

	return true;
}

void solve(vector<string> temp , set<vector<string>> &st , string s)
{
	int n = s.length();

	if(n == 0)
	{
		st.insert(temp);
		return;
	}

	for(int i = 1;i<=n;i++)
	{
		if(palin(s.substr(0,i)))
		{
			temp.push_back(s.substr(0 , i));
			solve(temp , st , s.substr(i));
			temp.pop_back();
		}
	}
}

void final(string s)
{
	set<vector<string>> st;
	vector<vector<string>> ans;
	vector<string> temp;

	solve(temp , st , s);

	for(auto i : st)
	{
		ans.push_back(i);
	}

	for(int i = 0;i<ans.size();i++)
	{
		for(int j = 0;j<ans[i].size();j++)
		{
			cout << ans[i][j] << " ";
		}

		cout << endl;
	}
}

int main()
{
	string s;
	cin >> s;

	final(s);
	
}