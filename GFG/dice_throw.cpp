#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int recur(int d , int f ,int target) // f is the range
{
	if(d == 0 && target == 0)
	{
		return 1;
	}

	if(target <= 0 || d <= 0)
	{
		return 0;
	}

	int count = 0;

	for(int i = 1;i<=f;i++)
	{
		count += recur(d-1 , f , target - i);
	}

	return count;
}

int better(int d , int f , int target)
{
	int dp[d+1][target+1];

	for(int i = 0;i<=d;i++)
	{
		for(int j = 0;j<=target;j++)
		{
			if(i == 0 && j == 0)
			{
				dp[i][j] = 1;
			}

			else if(i == 0 || j == 0)
			{
				dp[i][j] = 1;
			}

			int count = 0;

			for(int x = 1;x<=f;i++)
			{
				if(x <= f && j >= x)
				{
					count += dp[i-1][j-x];
				}
			}

			dp[i][j] = count;
		}
	}

	return dp[d][target];
}

int main()
{
	int d,f,target;

	cin >> d >> f >> target;

	cout << recur(d,f,target) << endl;
	cout << better(d,f,target);
	
}