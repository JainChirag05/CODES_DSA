#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int open , int close , string &op , vector<string> &ans)
{
	if(open == 0 && close == 0)
	{
		ans.push_back(op);
		return;
	}

	if(open != 0)
	{
		string op1 = op;
		op1.push_back('(');

		solve(open-1 , close , op1 , ans);
	}

	if(open < close)
	{
		string op2 = op;
		op2.push_back(')');

		solve(open , close-1 , op2 ,ans);
	}
}

int main()
{
	int n;
	cin >> n;

	int open = n;
	int close = n;

	string op = "";
	vector<string> ans;

	solve(open , close , op , ans);

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
}