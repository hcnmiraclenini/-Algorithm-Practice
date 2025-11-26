#include <iostream>
using namespace std;
string zhuang[100000];
string suan[100000];
string code[100000];
string can[10000];
int main()
{
	long long a = 20211016;
	long long  b = 20221002;
	int n, m, k;
	cin >> n >> m >> k;
	
	for (int i = 0; i < n; i++)
	{
		cin >>zhuang[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> suan[i];
	}
	for (int i = 0; i < k; i++)
	{
		cin >> code[i];
	}
	int w;
	cin >> w;
	for (int i = 0; i < w; i++)
	{
		cin >> can[i];
		for (int j = 0; j < k; j++)
		{
			if (can[i] == code[j])
			{
				//cout << a << " " << b << endl;
				a++, b++;
			//	cout << a << " " << b << endl;
			}
		}
		for (int q = 0;q < m; q++)
		{
			if (can[i] ==suan[q])
			{
				//cout << a << " " << b << endl;
				a--; b++;
				//cout << a << " " << b << endl;
			}
		}
	}
	cout << a << " " << b << endl;
	return 0;
	//刷codeforces: 能力强度和能力广度都能上升一个点
	//学算法：能力广度上升一个点

}

