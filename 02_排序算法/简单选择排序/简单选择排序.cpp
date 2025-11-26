#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int a[1000];
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n-1; i++)
		{
			int minindex = i;
			for (int j = i+1; j < n; j++)
			{
				minindex = a[j] < a[minindex] ? j : minindex;
				
			}
			if (minindex != i) swap(a[i], a[minindex]);
			for (int q = 0; q < n; q++)
			{
				if (q == n - 1)
					cout << a[q] << endl;
				else cout << a[q] << " ";
			}

		}
		for (int q = 0; q < n; q++)
		{
			if (q == n - 1)
				cout << a[q] << endl;
			else cout << a[q] << " ";
		}
		cout << endl;
	}
	return 0;
}

