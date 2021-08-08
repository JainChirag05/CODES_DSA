#include <bits/stdc++.h>

using namespace std;

bool isOperator(char x) 
{
  switch (x) 
  {
  	case '+':
  	case '-':
  	case '/':
  	case '*':
    
    return true;
  }

  return false;
}

string convert(string s)
{
	int n = s.length();

	stack <string> st;
	//string res = "";

	for(int i = n-1;i>=0;i--)
	{
		if(isOperator(s[i]))
		{
			string temp1 = st.top();
			st.pop();
			string temp2 = st.top();
			st.pop();

			string temp = "(" + temp1 + s[i] + temp2 + ")"; 

			st.push(temp);
		}

		else
		{
			string res = string(1 , s[i]);
			st.push(res);
		}
	}

	return st.top();
}

int main() 
{
	stack <string> st;
  	string input = "*-A/BC-/AKL";
  	cout << convert(input) << endl;
  return 0;
}