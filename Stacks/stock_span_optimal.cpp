#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector <int> sol(int price[] , int n)
{
	stack <int> st;
	vector<int> ans;

	st.push(0);
	ans.push_back(1);

	for(int i = 1;i<n;i++)
	{
		while(!st.empty() && price[i] >= price[st.top()])
		{
			st.pop();
		}

		if(st.empty())
		{
			ans.push_back(i+1);
		}

		else
		{
			ans.push_back(i-st.top());
		}

		st.push(i);
	}

	return ans;
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

	vector <int> ans = sol(arr , n);

	for(int i = 0;i<n;i++)
	{
		cout << ans[i] << " ";
	}
	
}