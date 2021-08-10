#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int recur(int n , int k)
{
	if(n == 1)
	{
		return 1;
	}

	else
	{
		return (recur(n-1, k) + k-1)%n + 1;
	}
}

int main()
{
	int n;
	cin >> n;

	int k;
	cin >> k;

	cout << recur(n , k);	
}