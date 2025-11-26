#include <iostream>
using namespace std;
class CMatrix;
//向量类
class CVector
{
private :
	int* data;
	int n;
public:
	CVector();
	CVector(int n1，int * a);
	CVector(const CVector& v1);//拷贝构造函数
	void print();
	friend class CMatrix; //将CMatrix定义为CVector的友元类
	~CVector();
};
//矩阵类
class CMatrix
{
	int** data;
	int n;
	CVector multi(const CVector& v1);//计算n阶矩阵与n维向量v1的乘积
	int ismulti(const CVector& v1);//判定矩阵与向量v1是否可计算乘积
	CMatrix();
	~CMatrix();
};
CVector::CVector()
{
	n = 5;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = i;
	}
}
CVector::CVector(int n1，int * a)//指针传进来什么？？
{
	n = n1;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = a[i];//a在主函数里已动态分配
	}
}
CVector::CVector(const CVector& v1)
{
	n = v1.n;
	data = new int[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = v1.data[i];
	}
}
void CVector::print()
{
	int i;
	for ( i = 0; i < n - 1; i++)
	{
		cout << data[i] << ' ';
	}
	cout << data[i] << endl;
}
CVector::~CVector()
{
	delete[]data;
}
CMatrix::CMatrix()
{
	cin >> n;
	data = new int* [n];//二级指针！！
	for (int i = 0; i < n; i++)
	{
		data[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> data[i][j];

		}
	}
}

CVector CMatrix::multi(const CVector& v1)
{
	int* a = new int[n];
	for(int i=0;i<n;i++）
		{
			a[i]=0;
			for (int j = 0; j < n; j++)
			{
				a[i]+=data[i][j]*v1.data[j];
			}
		}
		CVector cv(n,a);
			delete []a;
			return cv;

}
int CMatrix::ismulti(const CVector& v1)
{
	return n = v1.n;

}
CMatrix::~CMatrix()
{
	for (int i = 0; i < n; i++)
	{
		delete[] data[i];

	}
	delete[]data;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		CMatrix cm;//矩阵
		int n;
		cin >> n;
		int* a = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		CVector cv(n, a);
		if (cm.ismulti(cv))
		{
			cm.multi(cv).print();
		}
		else
		{
			cout << "error" << endl;
		}
		delete[]a;

	}
	return 0;
}



