#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void m1(string s)
{
	int n = s.length();
	string ans = "";

	for(int i = 0;i<n;i++)
	{
		ans = max(ans , s.substr(i));
	}

	cout << ans << endl;
}

void m2(string s)
{
	int n = s.length();
	string ans = "";
	vector<int> ind;
	char maxchar = 'a';

	for(int i = 0;i<n;i++)
	{
		if(s[i] >= maxchar)
		{
			maxchar = s[i];
			ind.push_back(i);
		}
	}

	for(int i = 0;i<ind.size();i++)
	{
		ans = max(ans , s.substr(ind[i] , s.length()));
	}

	cout << ans << endl;
}

int main()
{
	string s;
	cin >> s;

	m1(s);
	m2(s);
	
}