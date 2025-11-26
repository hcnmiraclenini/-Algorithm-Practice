
#include <iostream>
#include<algorithm>
using namespace std;
int w[10000000];
int main()
{
	
	long long n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	sort(w, w + n);
	if (n % 2 != 0)//奇数
	{
		long long sum = 0;
		long long tar = n / 2;
		for (long long i = 0; i < n; i++)
		{
			long long temp = w[i] - w[tar];
			if (temp >= 0)  sum += temp;
			else  sum =sum+(-temp);
		}
		cout << sum << endl;
	}
	else
	{
		long long sum1 = 0;
		long long sum2 = 0;
		long long tar1 = n / 2;
	//	cout << "ta1" << endl;
		//cout << "ta2" << endl;
		long long tar2 = n / 2 + 1;
		for (long long i = 0; i < n; i++)
		{
			long long t1 = w[i] - w[tar1];
			if (t1 >= 0)  sum1 += t1;
			else  sum1 = sum1 -t1;
		}
		for (long long i = 0; i < n; i++)
		{
			long long t2 = w[i] - w[tar2];
			if (t2 >= 0)  sum2 += t2;
			else  sum2 = sum2 -t2;
		}
		
		long long len = sum1< sum2 ? sum1 : sum2;
		cout << len << endl;
	}
	return 0;
}
