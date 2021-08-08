 #include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int arr[] , int n , int k)
{
	priority_queue <int , vector<int>, greater<int>> minh;

	for(int i = 0;i<n;i++)
	{
		minh.push(arr[i]);

		if(minh.size() > k)
		{
			minh.pop();
		}
	}

	while(!minh.empty())
	{
		cout << minh.top() << " ";
		minh.pop();
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