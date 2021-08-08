#include <bits/stdc++.h>

using namespace std;

bool isoperator(char x)
{
	if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
	{
		return true;
	}

	return false;
}

string convert(string s)
{
	stack <string> st;

	int n = s.length();

	for(int i = 0;i < n;i++)
	{
		if(isoperator(s[i]))
		{
			string temp1 = st.top();
			st.pop();
			
			string temp2 = st.top();
			st.pop();		

			string res = s[i] + temp2 + temp1;

			st.push(res);	
		}

		else
		{
			st.push(string(1 , s[i]));
		}
	}

	return st.top();
}

int main()
{
    string input = "ABC/-AK/L-*";
    cout << convert(input) << endl;
    return 0;
}