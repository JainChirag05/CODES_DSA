#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int n)
{
	if(n == 1)
	{
		cout << "1";
		return;
	}

	if(n == 2)
	{
		cout << "11";
		return;
	}

	string s = "11";

	for(int i = 3;i<=n;i++)
	{
		string temp = "";
		int count = 1;
		s += '&';

		for(int j = 1;j<s.length();j++)
		{
			if(s[j] == s[j-1])
			{
				count++;
			}

			else
			{
				temp += to_string(count);
				temp += s[j-1];
				count = 1;
			}
		}

		s = temp;
	}

	cout << s;
}

int main()
{
	int n;
	cin >> n;

	solve(n);	
}