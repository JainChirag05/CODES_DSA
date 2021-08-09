#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool solve(string s1 , string s2)
{
	int n1 = s1.length();
	int n2 = s2.length();

	if(n1 == 1 && n2 == 1)
	{
		return s1[0] == s2[0];
	}

	string temp = s1 + s1;

	return (temp.find(s2) == 2 || n1 - temp.find(s2) == 2);
}

int main()
{
	string s1 , s2;
	cin >> s1 >> s2;

	cout << solve(s1 , s2);	
}