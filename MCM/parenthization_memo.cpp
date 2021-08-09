#include <bits/stdc++.h>
#define ll long long int

using namespace std;

unordered_map <string,int> mp;

int solve(string s , int i , int j , bool flag)
{
	string key = to_string(i) + " " + to_string(j) + " " + (flag ? "T" : "F");

	if(mp.find(key) != mp.end())
	{
		return mp[key];
	}

	if(i >= j)
	{
		if(flag)
		{
			mp[key] = s[i] == 'T';
		}

		else
		{
			mp[key] = s[i] == 'F';
		}

		return mp[key];
	}

	int ans = 0;

	for(int k = i+1;k<j;k = k+2)
	{
		int lt = solve(s , i ,k-1 , true);
		int lf = solve(s , i ,k-1 , false);
		int rt = solve(s , k+1 ,j , true);
		int rf = solve(s , k+1 ,j , false);

		if(s[k] == '&')
		{
			if(flag == true)
			{
				ans = ans + lt*rt;
			}

			else
			{
				ans = ans + (lf*rt + lt*rf + rf*lf);
			}
		}

		else if(s[k] == '|')
		{
			if(flag == true)
			{
				ans = ans + (lf*rt + lt*rf + rt*lt);
			}

			else
			{
				ans = ans + rf*lf;
			}
		}

		else if(s[k] == '^')
		{
			if(flag == true)
			{
				ans = ans + (lf*rt + lt*rf);
			}

			else
			{
				ans = ans + (rf*lf + rt*lt);
			}
		}
	}

	return mp[key] = ans;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s , 0 ,s.length()-1 , true);
	
}