#include <bits/stdc++.h>
#define ll long long int

using namespace std;

//#define n 4;

int m[4][4] = {{0,0,1,0},
			  {0,0,1,0},
			  {0,0,0,0},
			  {0,0,1,0}};

bool check(int a , int b)
{
	return m[a][b];
}

int solve()
{
	stack <int> st;

	for(int i = 0;i<4;i++)
	{
		st.push(i);
	}

	int j = 0;

	while(j < 3)
	{
		int a = st.top();
		st.pop();

		int b = st.top();
		st.pop();

		if(check(a , b))
		{
			st.push(b);
		}

		else
		{
			st.push(a);
		}

		j++;
	}

	int maybe = st.top();

	int flag = 0;

	for(int i = 0;i<4;i++)
	{
		if(m[maybe][i] != 0)
		{
			flag = 1;
			break;
		}
	}

	int count = 0;
	
	for(int i = 0;i<4;i++)
	{
		if(m[i][maybe] == 0)
		{
			count++;
		}
	}

	if(count > 1 || flag == 1)
	{
		return -1;
	}

	else
	{
		return maybe;
	}
}


int main()
{
	cout << solve() << endl;
}