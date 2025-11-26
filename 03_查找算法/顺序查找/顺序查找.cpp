#include<iostream>
using namespace std;

int a[1000];
int n;
void print()
{
	cout << a[0];
	for (int i = 1; i <n; i++)
	{
		 cout << " "<<a[i];
	}
}
int main()
{
	
		
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
			{
				
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				
				
			}
			print();
			cout << endl;
		}
	

	return 0;
}