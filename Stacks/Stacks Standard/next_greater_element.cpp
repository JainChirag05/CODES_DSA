#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n)
{
	stack <int> st;
	unordered_map <int,int> mp; // if order is to be maintained
	

	st.push(arr[0]);

	for(int i = 1;i<n;i++)
	{
		while(!st.empty() && st.top() < arr[i])
		{
			mp[st.top()] = arr[i];
			st.pop();
		}

		st.push(arr[i]);
	}

	while(!st.empty())
	{
		mp[st.top()] = -1;
		st.pop();
	}

	for(int i = 0;i<n;i++)
	{
		cout << mp[arr[i]] << " ";
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
	
	solve(arr , n);
}