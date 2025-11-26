#include <iostream>
#include<cstring>
#include<limits.h>
using namespace std;
long long a[10000000];
long long n;
double sum = 0;
void count(long long t)
{
	for (long long i = 0; i < t; i++)
	{
		cin >> a[i];
		if (a[i] % n == 0)
		{
			continue;
		}
		else { sum =sum+ a[i]; }

	}
}
int main()
{
	long long t;
	sum = 0;
	cin >> n;	
	cin >> t;
	memset(a, 0, sizeof(a));
	count(t);
	cout << (long long)sum << endl;
	return 0;
}

