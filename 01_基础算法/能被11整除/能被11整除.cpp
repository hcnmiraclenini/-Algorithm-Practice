#include <iostream>
#include<cstring>
using namespace std;
int main()
{
	int t;
	char a[10000];
	long long s1 = 0, s2 = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a;
		int len=strlen(a);
		for (int k = 0; k < len; k += 2)
		{
			cout <<"奇数"<< a[k] - '0' << endl;
			s1 += (a[k] - '0');

		}
		for (int p = 1; p < len; p += 2)
		{
			cout << "偶数" << a[p] - '0' << endl;
			s2 += (a[p] - '0');
		}
		if (11%(s1 - s2)  == 0)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}

