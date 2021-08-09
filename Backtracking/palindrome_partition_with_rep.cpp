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

void solve(vector<vector<string>> &ans , vector<string> temp , string s)
{
	int n = s.length();

	if(n == 0)
	{
		ans.push_back(temp);
		return;
	}

	for(int i = 1;i<=n;i++)
	{
		if(palin(s.substr(0 , i)))
		{
			temp.push_back(s.substr(0,i));
			solve(ans,temp,s.substr(i));
			temp.pop_back();
		}
	}
}

void final(string s)
{
	vector<vector<string>> ans;
	vector<string> temp;

	solve(ans,temp,s);

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