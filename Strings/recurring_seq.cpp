#include <bits/stdc++.h>
#define ll long long int

using namespace std;

string solve(int n , int d)
{
	int q = n/d;
	int rem = n%d;
	string ans = "";
	unordered_map <int,int> mp;

	ans += to_string(q);

	if(rem == 0)
	{
		return ans;
	}

	else
	{
		ans += ".";
		while(rem != 0)
		{
			if(mp.find(rem) != mp.end())
			{
				ans.insert(mp[rem] , "(");
				ans += ")";
				break;
			}

			else
			{
				mp[rem] = ans.length();
				rem = rem*10;
				q = rem/d;
				ans += to_string(q);
				rem = rem%d;
			}
		}
	}

	return ans;
}

int main()
{
	int n,d;
	cin >> n >> d;

	cout << solve(n , d);
	
}