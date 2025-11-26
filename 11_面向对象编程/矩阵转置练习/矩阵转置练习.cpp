#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int** array1 = new int* [2];
		for (int i = 0; i < 3; ++i)
		{
			array1[i] = new int[3];
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> array1[i][j];
			}

		}
		for (int i = 2; i >= 0; --i)
		{
			for (int j = 0; j < 2; ++j)
			{
				cout << *(*(array1 + j) + i) << " ";
			}
			cout << endl;
		}
	
	}

}