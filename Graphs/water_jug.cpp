#include <bits/stdc++.h>
#define ll long long int
#define pi pair<int,int>

using namespace std;

bool solve(int a , int b , int target)
{
	if(a+b < target)
	{
		return 0;
	}

	queue<pi> q;
	set<pi> st;

	st.insert({a,b});
	q.push({a,b});

	while(!q.empty())
	{
		pi curr = q.front();
		q.pop();

		int x = curr.first;
		int y = curr.second;

		if(x+y == target)
		{
			return 1;
		} 

		int new_x , new_y;

		new_x = x - min(x , b-y); 	//trasfer from jug a to jug b
		new_y = y + min(x , b-y);

		if(st.find({new_x ,new_y}) == st.end())
		{
			st.insert({new_x , new_y});
			q.push({new_x , new_y});
		}

		new_x = x + min(y , a-x); 	//trasfer from jug b to jug a
		new_y = y - min(y , a-x);

		if(st.find({new_x ,new_y}) == st.end())
		{
			st.insert({new_x , new_y});
			q.push({new_x , new_y});
		}

		new_x = a; 	//fill jug a completely
		new_y = y;

		if(st.find({new_x ,new_y}) == st.end())
		{
			st.insert({new_x , new_y});
			q.push({new_x , new_y});
		}

		new_x = x; 	//fill jug b completely
		new_y = b;

		if(st.find({new_x ,new_y}) == st.end())
		{
			st.insert({new_x , new_y});
			q.push({new_x , new_y});
		}

		new_x = 0;	//empty jug a
		new_y = y;

		if(st.find({new_x ,new_y}) == st.end())
		{
			st.insert({new_x , new_y});
			q.push({new_x , new_y});
		}

		new_x = x;	//empty jug b
		new_y = 0;

		if(st.find({new_x ,new_y}) == st.end())
		{
			st.insert({new_x , new_y});
			q.push({new_x , new_y});
		}
	}

	return false;
}

int main()
{
	int a,b,target;
	cin >> a >> b >> target;

	cout << solve(a,b,target);
	
}