#include <iostream>
#include<stack>
using namespace std;
//若用户输入#，表示将#之前的字符替换为@，
//#本身不算字符输入。
int main()
{
	int t;
	cin >> t;
	stack<char>s;
	while (t--)
	{
		string st;
		cin >> st;
		for (int i = 0; i < st.size(); i++)
		{
			
			if (st[i + 1] != '#') s.push(st[i]);
			if (s.top() != '@' && st[i + 1] == '#')
			{
				s.pop();
				s.push('@');
			
			}
			if (s.top() == '@' && st[i + 1] == '#')
			{
				s.pop();
			}
			if (st[i] == '#')
				continue;
	
		}
		stack<char>temp;
		while (!s.empty())
		{
			char ch = s.top();
			temp.push(ch);
			s.pop();
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

