#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int solve(int e , int f)
{
	if(e == 1)
	{
		return f;
	}

	if(f == 1 || f == 0)
	{
		return f;
	}

	int ans = INT_MAX;

	for(int k = 1;k<=f;k++)
	{
		int temp = 1 + max(solve(e-1 , k-1) , solve(e , f-k));

		ans = min(temp , ans);
	}

	return ans;
}

int main()
{
	int f,e;
	cin >> f >> e;

	cout << solve(e , f) << endl;	

	return 0;
}