#include <bits/stdc++.h>
#define ll long long int
using namespace std;


void solve(string s , int n)
{
	unordered_map<char,int> mp;

	for(int i = 0;i<n;i++)
	{
		mp[s[i]]++;
	}

	int count = 0;

	unordered_set<int> st;

	for(auto it = mp.begin();it != mp.end(); it++)
	{
		if(st.find(it->second) != st.end())
		{
			while(st.find(it->second) != st.end())
			{
				it->second--;
				count++;
			}

			if(it->second != 0)
			{
				st.insert(it->second);
			}
		}

		else
		{
			st.insert(it->second);
		}
	}

	cout << count;
}

int main()
{
	string s;
	cin >> s;

	int n = s.length();

	solve(s , n);
}