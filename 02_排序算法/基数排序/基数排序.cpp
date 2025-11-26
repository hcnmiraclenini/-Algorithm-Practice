#include <iostream>
#include<cmath>
#include<list>
#include<algorithm>
#include<queue>
using namespace std;

//基数升序排序
//对每组测试数据，输出每趟分配、收集的结果。
//若分配中该位没有数字，输出NULL。
int a[1000];
list<int> l[10];
int flag = 1;
int add;
int num[1000];
void RadixSortIth(int a[], int n, int ith)//ith第几幂次
{
	for (int i = 0; i < 10; i++)//每次都要清空桶
		l[i].clear();
	for (int i = 0; i < n; i++)
	{
		int tmp = a[i];
		for (int j = 1; j <= ith; j++)
			tmp /=10;
		l[tmp % 10].push_back(a[i]);
	}
	
}

void RadixSort(int a[], int n)
{
	//求所有元素最大值
	int maxa = a[0];
	for (int i = 0; i < n; i++)
		maxa = maxa > a[i] ? maxa : a[i];
	//求最大值位数
	int maxDigit = 1;
	for (; maxa; maxa /= 10, maxDigit++);//最大值的位数maxDigit
	for (int i = 0; i < maxDigit-1; i++)//最大位数是多少就进行多少次排序
	{
		RadixSortIth(a, n, i);
		int p = 0;
		
		if (flag == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				if (!l[j].empty())
				{
					cout << j << ":->";
					while (!l[j].empty())
					{
						cout << (l[j].front() - add) << "->";
						a[p++] = l[j].front() - add;
						
						l[j].pop_front();
					}

					cout << "^" << endl;
				}
				else cout << j << ":NULL" << endl;
			}
		
		}
		else
		{
			for (int j = 0; j < 10; j++)
			{
				if (!l[j].empty())
				{
					cout << j << ":->";
					while (!l[j].empty())
					{
						cout << l[j].front() << "->";
						a[p++] = l[j].front();
						l[j].pop_front();
					}
					l[j].clear();
					cout << "^" << endl;
				}
				else cout << j << ":NULL" << endl;
			}		
		}
		

		//输出
		for(int j=0;j<n;j++)
		{
			if (j != n - 1)
			{
				cout << a[j] << " ";

			}
			else cout << a[j] << endl;
		}
	}
}
int main()
{
	
	int t;
	cin >> t;
	while (t--)
	{
		flag = 1;
		int n;
		cin >> n;
		int minx=0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			minx = min(minx, a[i]);
		}
		if (minx < 0)
		{
			for (int i = 0; i < n; i++)
				a[i] += (-minx);
		}

		RadixSort(a, n);
		cout << endl;
	}
	return 0;
}

