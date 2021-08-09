#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int n)
{
	int count[n+2];

	count[0] = 0;
	count[1] = 1;

	for(int i = 2;i<n;i++)
	{
		count[i] = count[i-1] + count[i-2];
	}

	cout << count[n];
}

int main()
{
	int n;
	cin >> n;

	solve(n);	
}