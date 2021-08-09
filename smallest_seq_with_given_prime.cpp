#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(int a , int b , int c , int d)
{
	vector<int> arr;
	arr.push_back(1);

	int x = 0 , y = 0, z = 0;

	while(d--)
	{
		int mini = min(a*arr[x] , min(b*arr[y] , c*arr[z]));
		arr.push_back(mini);

		if(mini == a*arr[x])
		{
			x++;
		}

		if(mini == b*arr[y])
		{
			y++;
		}

		if(mini == c*arr[z])
		{
			z++;
		}
	}

	arr.erase(arr.begin());

	for(int i = 0;i<arr.size();i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;

	solve(a,b,c,d);	
}