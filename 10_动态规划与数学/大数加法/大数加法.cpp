#include <iostream>
#include<stack>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	stack<int>sta;
	stack<int>stb;
	stack<int>r;
	int la = a.size();
	int lb = b.size();
	for (int i = 0; i < la; i++)
	sta.push(a[i]-'0');
	for (int j = 0; j < lb; j++)
	stb.push(b[j]-'0');
	int flag = 0;
	while (!sta.empty() && !stb.empty())
	{	
		int temp = (sta.top() + stb.top()+flag)%10;
		//cout << "temp" << temp << endl;
		r.push(temp);
		if (sta.top() + stb.top() + flag >= 10) flag = 1;
		else flag = 0;
		sta.pop();
		stb.pop();
	}
	if (sta.empty() && stb.empty() && flag)
		r.push(flag);
	while (!sta.empty())
	{
		int temp =( sta.top() + flag)%10;
			r.push(temp);
			if (sta.top() + flag >= 10) flag = 1;
			else flag = 0;
		sta.pop();
	}
	while (!stb.empty())
	{
		int temp =( stb.top() + flag)%10;
		r.push(temp);
		if (stb.top() + flag >= 10) flag = 1;
		else flag = 0;
		stb.pop();
	}
	while (!r.empty())
	{
		int ch = r.top();
		cout << ch;
		r.pop();
	}
	cout << endl;
}

