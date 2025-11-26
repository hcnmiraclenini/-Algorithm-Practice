#include <iostream>
#include<algorithm>
using namespace std;
long n;
int pos[1000000];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> pos[i];
	}
	sort(pos, pos + n);
	if (n % 2 != 0)
	{
		long long  sum = 0;
		for (int i = 0; i < n; i++)
		{
			int t = pos[n / 2] - pos[i];
			if (t >= 0)  sum += t;
			else sum += (-t);

		}
		cout << sum << endl;
	}
	else
	{
		long long sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++)
		{
			int t = pos[n / 2] - pos[i];
			if (t >= 0)  sum1 += t;
			else sum1 += (-t);

		}
		for (int i = 0; i < n; i++)
		{-+
			int t = pos[n/ 2-1] - pos[i];
			if (t >= 0)  sum2 += t;
			else sum2 += (-t);

		}
		long long r = sum1 > sum2 ? sum1 : sum2;
		cout << r << endl;
	}

	return 0;
}
