#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , int k)
{
	int n = s.length();
	int i = 0;
	string res = "";

	while(i < n)
	{
		string temp = "";
		int freq = 0;

		while(s[i] >= 'a' && s[i] <= 'z')
		{
			temp.push_back(s[i]);
			i++;
		}

		while(s[i] >= '1' && s[i] <= '9')
		{
			freq = freq*10 + s[i] - '0';
			i++;
		}

		for(int j = 0;j<freq;j++)
		{
			res.append(temp);
		}
	}

	cout << res[k-1];
}

int main()
{
	string s;
	cin >> s;

	int k;
	cin >> k;

	solve(s , k);
	
}