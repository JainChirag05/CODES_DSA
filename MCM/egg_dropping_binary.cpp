#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int t[101][101];

int solve(int e , int f)
{
	if(t[e][f] != -1)
	{
		return t[e][f];
	}

	if(e == 0 || f == 0 || f == 1)
	{
		return t[e][f] = f;
	}

	int ans = INT_MAX;
	int h = f;
	int l = 1;

	while(l <= h)
	{
		int m = l + (h-l)/2;

		int b = solve(e-1 , m - 1);
		int top = solve(e , f - m);

		int temp = 1 + max(b,top);

		if(b < top)
		{
			l = m+1;
		}

		else
		{
			h = m-1;
		}

		ans = min(ans , temp);
	}

	return ans;
}

int main()
{
	int f,e;
	cin >> f >> e;

	memset(t , -1 , sizeof(t));

	cout << solve(e , f) << endl;	

	return 0;
}