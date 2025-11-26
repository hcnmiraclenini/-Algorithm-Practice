#include <iostream>
#include<cstring>
using namespace std;
class CVector
{
private:
	int* data;//存储n维向量
	int n; //向量维数
	static int sum;
public:
	CVector();
	CVector(int n1, int da[]);
	void print();
	~CVector();
	static int sum1();
};
int CVector::sum = 0;
CVector::CVector()
{

	n = 5;
	int i;
	data = new int[5];
	for (i = 0; i < 5; i++)
	{
		*(data + i) = i;
	}


}
CVector::CVector(int n1, int da[])
{
	n = n1;
	data = new int[n1];
	for (int i = 0; i < n; i++)
	{
		*(data + i) = da[i];
		sum = sum + data[i];
	}


}
void CVector::print()
{
	int i;
	for (i = 0; i < n - 1; i++)
	{
		cout << *(data + i) << " ";
	}
	cout << *(data + i) << endl;
}
int CVector::sum1()
{
	return sum;
}
CVector::~CVector()
{
	delete data;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int m;
		cin >> m;
		while (m--)
		{
			int n = 0;
			cin >> n;
			int c[20];
			for (int i = 0; i < n; i++)
			{
				cin >> c[i];
			}
			CVector cvector(n, c);
			cvector.print();

		}
		cout << CVector::sum1();
	}


}