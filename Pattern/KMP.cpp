#include <bits/stdc++.h>

int reset[100005];

using namespace std;

void resettable(string pat)
{
	int i = 0,j=-1;
	
	reset[0] = -1;
	
	int len = pat.size();
	
	while(i < len)
	{
		if(j >= 0 && pat[i] != pat[j])
		{
			j = reset[j];
		}
		
		i++;
		j++;
		reset[i] = j;
	}
}

void match(string str , string pat)
{
	resettable(pat);
	int i = 0,j = 0;
	
	int stlen = str.size();
	int patlen = pat.size();
	
	while(i < stlen)
	{
		if(j >= 0 && str[i] != pat[j])
		{
			j = reset[j];
		}
		
		i++;
		j++;
		
		if(j == patlen)
		{
			cout << "Pattern at " << i-j << endl;
		}
	}
}

int main()
{
	string str , pat;
	cin >> str >> pat;
	
	match(str , pat);	
}
