#include <iostream>
#include<queue>
using namespace std;
long long a;
int fn[10] = { 6,2,5,5,4,5,6,3,7,6 };
int main()
{
	int n;
	cin >> n;
	queue<int>q;
	while (n--)
	{
		cin >> a;
		if (a <= 1)cout << "-1" << endl;
		else
		{
			if (a % 2 == 0)
			{
				while (a % 2 != 0)
				{
					q.push(1);
					a -= 2;
				}
			}
				
			else
			{
				while (a % 2 ==1)
				{
					q.push(1);
				}
			}

			while (!q.empty())
			{
				int temp = q.front();
				q.pop();
				cout << temp;
			}
			cout << endl;
		}
	}
	return 0;
}

