#include <bits/stdc++.h>
#define ll long long int

using namespace std;


string solve(string a , string b, int x , int y)
{
	int t[x+1][y+1];

	for(int i = 0;i<=x;i++)
	{
		for(int j = 0;j<=y;j++)
		{
			if(i == 0 || j == 0)
			{
				t[i][j] = 0;
			}
		}
	}

	for(int i = 1;i<=x;i++)
	{
		for(int j = 1;j<=y;j++)
		{
			if(a[i-1] == b[j-1])
			{
				t[i][j] = 1 + t[i-1][j-1];
			}

			else
			{
				t[i][j] = max(t[i-1][j] , t[i][j-1]);
			}
		}
	}

	int i = x;
	int j = y;
	string ans = "";

	while(i > 0 && j > 0)
	{
		if(a[i-1] == b[j-1])
		{
			ans += a[i-1];
			i--;
			j--;
		}

		else
		{
			if(t[i-1][j] > t[i][j-1])
			{
				i--;
			}

			else
			{
				j--;
			}
		}
	}

	reverse(ans.begin() , ans.end());

	return ans;
}


int main()
{
	string a;
	cin >> a;
	
	string b;
	cin >> b;

	int x = a.length();
	int y = b.length();

	cout << solve(a,b,x,y) << endl;
}