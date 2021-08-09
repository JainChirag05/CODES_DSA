#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string solve(string s)
{
	int n = s.length();

	string ans = "";

	int mid = n/2 - 1;

	string first = s.substr(0 , mid+1);
	string prev = first;

	next_permutation(first.begin() , first.end());

	if(first <= prev)
	{
		return "-1";
	}

	ans += first;

	if(n%2 == 1)
	{
		ans += s[n/2];
	}

	string second = first;

	reverse(second.begin()  ,second.end());

	ans += second;

	return ans;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s);	
}