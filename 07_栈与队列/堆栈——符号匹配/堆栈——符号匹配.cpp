#include <iostream>
#include<stack>
using namespace std;



int main()
{
	int t;
	string str;
	stack<char>s;
	int flag = 1;
	while (cin>>str)
	{
		flag = 1;
		int cnt = 0;
		if (str[0] == '}' ||  str[0] == ']' ||  str[0] == ')')
		{
			//cout << "只有右半边" << endl;
			cnt++;
			flag = 0;
			
		}
		if( (str.size()==1)&&(str[0] == '{' || str[0] == '['  || str[0] == '(' ))
		{
			//cout << "只有左半边" << endl;
			flag = 0;
			cnt++;
		}
		else
		{
			int len = str.size();
			for (int i = 0; i < len; i++)
			{
				if (str[i] == '(' || str[i] == '[' || str[i] == '{')
				{
					//cout << "~" << endl;
					s.push(str[i]);
					continue;
				}
				else if (s.empty() && ((str[i] == '}') || (str[i] == ']') || (str[i] == ')')))
				{
					flag = 0; cnt++;
				}
				else if (!s.empty())
				{
					//cout << "!" << endl;
					char ch = s.top();
					if ((ch == '(' && str[i] == ')') || ((ch == '[') && str[i] == ']') || (ch == '{' && str[i] == '}'))
					{

						//cout << "匹配" << endl;
						s.pop();
						continue;
					}
					if (ch == '(' && ((str[i] == '}') || (str[i] == ']')))
					{
						//	cout << "不匹配" << endl;

						flag = 0; cnt++;
					}
					else if (ch == '{' && ((str[i] == ')') || (str[i] == ']')))
					{
						//cout << "不匹配" << endl;
						flag = 0; cnt++;
					}
					else if (ch == '[' && ((str[i] == '}') || (str[i] == ')')))
					{
						//cout << "不匹配" << endl;
						flag = 0; cnt++;
					}

					else
					{
						continue;
					}

				}
				else
				{
					continue;
				}
			
				
			}
			
		}
		while(!s.empty())
		{
		//	cout << "栈非空" << endl;
			flag = 0;
			cnt++;
			s.pop();
		}
			if (!flag) cout << cnt<< endl;
			else cout << "SZTU_WOD YYDS!" << endl;

			if (!s.empty()) s.pop();
	}
	return 0;
}