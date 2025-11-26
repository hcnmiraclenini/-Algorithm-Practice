#include <iostream>
#include<stack>
#include<cstring>
using namespace std;
//当输入#字符，则执行退格
//前面没有字符可以退也不会报错
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		stack<char>st;
		stack<char>temp;
		for (int i = 0; i <s.size(); i++)
		{
			if(s[i] != '#')
			{
				st.push(s[i]);
				continue;
			}
			if(st.empty() && s[i] == '#')
				continue;
			if (!st.empty() && s[i] == '#')
				st.pop();

		}
		if (st.empty())
		{
			cout << "NULL" << endl;
		}
		else
		{
			while (!st.empty())
			{
				char ch = st.top();
				temp.push(ch);
				st.pop();
			}
			while (!temp.empty())
			{
				char ch = temp.top();
				cout << ch;
				temp.pop();
			}
			cout << endl;
		}
	
	}
}

