#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(int arr[] , int n , int sum)
{
	set <int> s;

	for (int i =0;i<n;i++)
	{
		s.insert(arr[i]);

		int temp = sum - arr[i];

		if(s.find(temp) != s.end())
		{
			cout << arr[i] << " " << temp;
			break;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i =0;i<n;i++)
	{
		cin >> arr[i];
	}

	int sum;
	cin >> sum;

	solve(arr , n , sum);
	
}