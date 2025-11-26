#include <iostream>
#include<cstring>
#include<queue>
using namespace std;
string c;
queue<char>q;

long long len = c.size();
int main()
{
	
	
	long long  a, b, d, e;
	while (cin >> a >> b >> d >> e)
	{
       long long ans = a * b % d;
		cin >> c;
		
		for (long long i = 0; i < len; i++)
		{
			q.push(c[i]);
		}
		for (long long i = 0; i < e; i++)
		{
			q.pop();
		}
		for (long long i = e; i <= ans; i++)
		{
			char temp = q.front();
			cout << temp;
			q.pop();
		}
		cout << endl;
		while (!q.empty())q.pop();
	}
	return 0;
}
