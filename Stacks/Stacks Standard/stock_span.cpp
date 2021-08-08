#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector <int> v)
{
	int n = v.size();
	vector <int> ans;
	stack <int> st;

	st.push(0);

	ans.push_back(1);

	for(int i = 1;i<n;i++)
	{
		while(!st.empty() && v[st.top()] <= v[i])
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

	for(int i = 0;i<ans.size();i++)
	{
		cout << ans[i] << " ";
	}
}

int main()
{
	int n;
	cin >> n;

	vector <int> v;

	for(int i = 0;i<n;i++)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	
	solve(v);
}