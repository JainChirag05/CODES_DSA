#include <bits/stdc++.h>
#define ll long long int

using namespace std;


//O(n^3)

bool palin(string s , int i , int j)
{
	while(i < j)
	{
		if(s[i] != s[j])
		{
			return false;
		}

		i++;
		j--;
	}

	return true;
}

int solve(string s, int i , int j)
{
	int ans = INT_MAX , temp;

	if(i >= j || palin(s , i , j))
	{
		return 0;
	}

	for(int k = i;k<j;k++)
	{
		temp = solve(s , i , k) + solve(s ,k+1 , j) + 1;

		ans = min(temp , ans);
	}

	return ans;
}


int main()
{
	string s;
	cin >> s;

	int n = s.length();

	cout << solve(s , 0 , n-1) << endl;
	
}