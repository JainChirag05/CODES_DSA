#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int lcs(string a , string b , int x , int y)
{
	int t[x+1][y+1];

	for(int i = 0;i<=x;i++)
	{
		for(int j = 0;j<=y;j++)
		{
			t[i][j] = -1;
		}
	}

	if(x == 0 || y == 0)
	{
		return 0;
	}

	if(t[x][y] != -1)
	{
		return t[x][y];
	}

	else
	{
		if(a[x-1] == b[y-1])
		{
			t[x][y] =  1+lcs(a,b,x-1,y-1);
		}

		else
		{
			t[x][y] =  max(lcs(a,b,x-1,y) , lcs(a,b,x,y-1));
		}

		return t[x][y];
	}
}

int main()
{
	string a;
	cin >> a;
	
	string b;
	cin >> b;

	int x = a.length();
	int y = b.length();

	cout << lcs(a,b,x,y);
}