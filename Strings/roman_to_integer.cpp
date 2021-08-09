#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int roman(char c)
{
    if(c == 'I')
    {
        return 1;
    }

    else if(c == 'V')
    {
        return 5;
    }

    else if(c == 'X')
    {
        return 10;
    }

    else if(c == 'L')
    {
        return 50;
    }

    else if(c == 'C')
    {
        return 100;
    }

    else if(c == 'D')
    {
        return 500;
    }

    else if(c == 'M')
    {
        return 1000;
    }

    return -1;
}

int solve(string s)
{
	int n = s.length();
	int i = 0;
	int num = 0;
	int ans = 0;

	while(i < n)
	{
		if(i < n-1 || roman(s[i]) >= roman(s[i+1]))
		{
			num = roman(s[i]);
			i++;
		}

		else
		{
			num = roman(s[i+1]) - roman(s[i]);
			i += 2;
		}

		ans += num;
	}

	return ans;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s);
	
}