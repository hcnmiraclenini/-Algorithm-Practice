#include <iostream>

using namespace std;
class Node
{
public:
	int exp;//指数
	int coe;//系数
	Node(int c = 0, int e = 0)
	{
		coe = c; exp = e;
	}
};
Node* a[100];//第一个式子
Node* b[100];//第二个式子
Node* result[100];//存放结果
int n, m;
int be=0;//记录结果第一个单项式的级数
void print(Node* t[],int len)
{
	for (int i = 0; i < len; i++)
	{
		if (i > 0)
			cout << " + ";
		//系数为0不输出
		if (t[i]->coe == 0) continue;
		//指数是0 只输出系数
		else if (t[i]->exp == 0 && t[i]->coe > 0) cout << t[i]->coe;
		 else if (t[i]->exp == 0 && t[i]->coe < 0) cout << "(" << t[i]->coe << ")";
		
		//输出各个项
		if (t[i]->coe > 0 && t[i]->exp > 0)
			cout << t[i]->coe << "x^" << t[i]->exp;
		else if (t[i]->coe < 0 && t[i]->exp > 0)
			cout << "(" << t[i]->coe << ")" << "x^" << t[i]->exp;
		if (t[i]->coe > 0 && t[i]->exp < 0)
			cout << t[i]->coe << "x^(" << t[i]->exp << ")";
		if (t[i]->coe < 0 && t[i]->exp < 0)
			cout << "(" << t[i]->coe << ")" << "x^(" << t[i]->exp << ")";
	}
}
void add(Node* a1[], Node* b1[])
{
	int p = 0;
	for (int i = 0, j = 0;i<n||j<m;)
	{
		if (i<n&&j<m&&a1[i]->exp == b1[j]->exp)
		{
			int temp1 = a1[i]->coe + b1[j]->coe;
			 if(temp1)result[p++] = new Node(temp1, a1[i]->exp);
			i++, j++;
		}
		else if (i < n && j < m && a1[i]->exp < b1[j]->exp)//取a1
		{
			result[p++] = new Node(a1[i]->coe, a1[i]->exp);
			i++;
		}
		else if (i < n && j<m && a1[i]->exp > b1[j]->exp)//取b1
		{
			result[p++] = new Node(b1[j]->coe, b[j]->exp);
			j++;
		}
		else if (i < n)
		{
			result[p++] = new Node(a1[i]->coe, a1[i]->exp);
			i++;
		}
		else if (j < m)
		{
			result[p++] = new Node(b1[j]->coe, b[j]->exp);
			j++;
		}
	}
	print(result, p);
	cout << endl;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		int co, ex;//系数coeffic  指数exponet
		//第一组
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> co>> ex;
			a[i] = new Node(co, ex);
		
		}
		print(a, n); cout << endl;
		//第二组
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> co >> ex;
			b[i] = new Node(co, ex);
		}
		print(b, m); cout << endl;
		add(a, b);
	}
	return 0;
}






