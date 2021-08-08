#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n , int k)
{
	stack <int> st;
	st.push(arr[0]);

	int count = 0;

	for(int i = 1;i<n;i++)
	{
		while(!st.empty() && st.top() < arr[i] && count < k)
		{
			st.pop();
			count++;
		}

		st.push(arr[i]);
	}

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}

}

int main()
{
	int n;
	cin >> n;

	int arr[n];

	for(int i = 0;i<n;i++)
	{
		cin >> arr[i];
	}

	int k;
	cin >> k;

	solve(arr , n , k);
	
}