#include <iostream>
using namespace std;
class CStack
{
private:
	int* a;
	int size;
	int top;
public:
	CStack();
	CStack(int s);
	CStack(CStack& s);
	int get(int index);
	void push(int n);
	int isempty();
	int isfull();
	int pop();
	~CStack();

};
CStack::CStack()
{
	size = 10;
	a = new int[size];
	top = 0;
	cout << "我创建啦" << endl;
}
CStack::CStack(int s)
{
	size = s;
	a = new int[size];
	top = 0;
	cout << "我创建啦" << endl;
}
int CStack::get(int index)
{
	return a[index];
}
CStack::CStack(CStack& s)
{
	size = s.size;
	a = s.a;
	top = 0;
}

void CStack::push(int n)
{
	
	a[top]=n;
	top++;
	//a[top++]=n;
}
int CStack::isempty()
{
	return top == 0;
}
int CStack::isfull()
{
	return top == size;
}
int CStack::pop()
{
	top--;
	return a[top];
	
	//return a[--top];
}
CStack::~CStack()
{
	delete[]a;
	cout << "我析构啦" << endl;
}
int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size, i,n;
		cin >> size;
		CStack cs(size);
		
		while(!cs.isfull())//入
		{
			cin >> n;
			cs.push(n);
		}
		cout << cs.pop();
		while(!cs.isempty())//出
		{
			cout << ' ' << cs.pop();
		}
		cout << endl;


	}
	return 0;
}
