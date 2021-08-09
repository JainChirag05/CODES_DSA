#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string solve(string s)
{
	int n = s.length();
	int i = 0;
	
	string res = "";

	while(i < n)
	{
		if(i < n-1 && s[i] == s[i+1])
		{
			while(i < n-1 && s[i] == s[i+1])
			{
				i++;
			}
		}

		else
		{
			res.push_back(s[i]);
		}

		i++;
	}

	return res;
}

string final(string s)
{
	string res = s;
	string temp = "";

	while(res.length() != temp.length())
	{
		temp = res;
		res = solve(res);
	}

	return res;
}

int main()
{
	string s;
	cin >> s;

	cout << final(s);
	
}