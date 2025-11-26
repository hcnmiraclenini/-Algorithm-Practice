#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int flag = 1;
	int cnt = 0;
	for (int i = a; i <= b; i++)
	{
		if (i == 1||i==0)
			continue;
		else
		{
			flag = 1;
			int c = sqrt(i) + 1;
			for (int j = 2; j < c; j++)
			{
				if (i % j == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag && cnt == 0) { cout << i; cnt++; }
			else if (flag && cnt >= 1) cout << " " << i;
		}

	}
	if (cnt<1) cout << "-1" << endl;
	cout << endl;
	return 0;

}


