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

	if(e == 1 || f == 0 || f == 1)
	{
		t[e][f] = f;
		return f;
	}

	int ans = INT_MAX;

	for(int i = 1;i<=f;i++)
	{
		int top , b;

		if(t[e-1][i-1] != -1)
		{
			top = t[e-1][i-1];
		}

		else
		{
			top = solve(e-1 , i-1);
		}

		if(t[e][f-i] != -1)
		{
			b = t[e][f-i];
		}

		else
		{
			b = solve(e , f-i);
		}

		int temp = 1 + max(top,b);

		ans = min(temp , ans);
	}

	return t[e][f] = ans;
}

int main()
{
	int f,e;
	cin >> f >> e;

	memset(t , -1 , sizeof(t));

	cout << solve(e , f) << endl;	

	return 0;
}