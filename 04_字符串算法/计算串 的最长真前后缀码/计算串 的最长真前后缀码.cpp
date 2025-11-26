#include <iostream>
#include<cstring>
using namespace std;

string matched_Prefix_Postfix(string str)
{
	string result = "0";
	int len = str.length();
	int flag = 0;
	if(len!=1)
	{
		
		string m1 , m2 ;
		int i = 0;
		while (i < len - 1)
		{
			m1 = str.substr(0, i + 1);
			m2 = str.substr(len - 1 - i, len - 1);
			i++;
			if (m1 == m2)
			{
				result = m1;
				flag = 1;
			}
		}
	}
	if (flag == 1)
	{
		cout << result << endl;
		return "0";
	}
	else
	{
	  cout << "empty" << endl;
	  return "0";
	}
	
}
int main()
{
	int t;
	string s;
	cin >> t;
	while (t--)
	{
		cin>>s;
		 matched_Prefix_Postfix(s);
	}
	return 0;
}
