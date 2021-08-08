#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<vector<int>> v = {{0, 0, 0, 0},
                   		 {1, 0, 1, 0},
                    	 {1, 0, 0, 0},
                    	 {1, 0, 1, 0}};


bool check(int a  ,int b)
{
	return v[a][b];
}

void solve(vector<vector<int>> arr)
{
	int n = arr.size();
	int m = arr[0].size();

	stack <int> st;

	for(int i = 0;i<n;i++)
	{
		st.push(i);
	}

	while(st.size() > 1)
	{
		int a = st.top();
		st.pop();

		int b = st.top();
		st.pop();

		if(check(a,b))
		{
			st.push(b);
		}

		else
		{
			st.push(a);
		}
	}

	if(st.empty())
	{
		cout << "None";
	}

	int maybe = st.top();
	st.pop();

	int flag = 0;

	for(int i = 0;i<m;i++)
	{
		if(arr[maybe][i] != 0)
		{
			flag = 1;
			break;
		}
	}

	int count = 0;

	for(int i = 0;i<n;i++)
	{
		if(arr[i][maybe] == 1)
		{
			count++;
		}
	}

	if(count < n-1 || flag == 1)
	{
		cout << "None";
	}

	else
	{
		cout << maybe;
	}
}

int main()
{
	
    solve(v);
	
}