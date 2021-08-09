#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(vector<vector<int>> arr)
{
	int n = arr.size();

	if(n == 0)
	{
		cout << 0 << endl;
	}

	int red = arr[0][0];
	int blue = arr[0][1];
	int green = arr[0][2];

	for(int i = 1;i<n;i++)
	{
		int newr = min(blue,  green) + arr[i][0];
		int newb = min(red,  green) + arr[i][1];
		int newg = min(blue,  red) + arr[i][2];

		red = newr;
		blue = newb;
		green = newg;
	}

	cout << min(red , min(blue , green));
}

int main()
{
	int n;
	cin >> n;

	vector<vector<int>> arr(n , vector<int>(3,0));

	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<3;j++)
		{
			cin >> arr[i][j];
		}
	}
	
	solve(arr);
}