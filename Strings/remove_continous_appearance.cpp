#include <bits/stdc++.h>
#define ll long long int

using namespace std;


string solve(string s)
{
	int n = s.length();

	string res = "";

	for(int i = 0;i<n;i++)
	{
		if(s[i] == 'a' && res.back() == 'a')
		{
			continue;
		}

		else if(s[i] == 'b')
		{
			continue;
		}

		res += s[i];
	}

	return res;
}


int main()
{
	string s;
	cin >> s;

	cout << solve(s);
	
}