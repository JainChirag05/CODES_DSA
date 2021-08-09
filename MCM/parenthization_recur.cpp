#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(string s, int i , int j , bool flag)
{
	if(i >= j)
	{
		if(flag)
		{
			return s[i] == 'T';
		}

		else
		{
			return s[i] == 'F';
		}
	}

	int ans = 0;

	for(int k = i+1; k<j; k=k+2)
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

	return ans;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s , 0 ,s.length()-1 , true);
	
}