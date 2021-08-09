#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(string s , int k)
{
	int n = s.length();
	int ans = 0;
	int count[26];

	for(int i = 0;i<n;i++)
	{
		int dist = 0;
		memset(count , 0 , sizeof(count));

		for(int j = i;j<n;j++)
		{
			if(count[s[j] - 'a'] == 0)
			{
				dist++;
			}

			count[s[j] - 'a']++;

			if(dist == k)
			{
				ans++;
			}

			if(dist > k)
			{
				break;
			}
		}
	}

	cout << ans;
}

long long int atMostK(string& A, int K) 
{
    long long int i = 0, res = 0;
    int count[26]={0};
        
    for (long long int j = 0; j < A.size(); ++j) 
    {
        if (!count[A[j]-'a']++) 
        {
            K--;
        }
            
        while (K < 0) 
        {
            if (!--count[A[i]-'a'])
            {
                K++;
            }
 
            i++;
        }
            
        res += j - i + 1;
    }
       
    return res;
}

void better(string s , int k)
{
	cout << atMostK(s,k)-atMostK(s,k-1);
}

int main()
{
	string s;
	cin >> s;

	int k;
	cin >> k;

	solve(s,k);
	cout << endl;
	better(s,k);
}