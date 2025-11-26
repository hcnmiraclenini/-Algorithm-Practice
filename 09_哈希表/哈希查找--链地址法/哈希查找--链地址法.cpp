#include <iostream>
#include<cstring>
using namespace std;
//给出一个数据序列，建立哈希表，采用求余法作为哈希函数，模数为11，
//哈希冲突用链地址法和表头插入
class Node
{
public:
	int data;
	Node* last;
	Node* next;
	Node()
	{
		data = 0;
		last = next = NULL;
	}
	Node(int d)
	{
		data = d;
		last = next = NULL;
	}
};
Node* node[40];
void insert(int nu)
{
	Node* q = new Node;
	q->data = nu;
	q->next = node[nu % 11];
	node[nu % 11] = q;
}
	

int main()
{
	int n;
	int number;
	while (cin >> n)//需要考虑多轮数据输入的情况
	{
		while (n--)
		{
			cin >> number;
			insert(number);
		}
		int t;
		int count = 1;
		cin >> t;
		while(t--)
		{
			cin >> number;
			count = 1;
			Node* q = node[number % 11];
			while (q)
			{
				if (q->data == number)
					break;
				q = q->next;
				count++;
			}
			if (q)
			{
				cout << (number % 11) << " " << count << endl;
			}
			else
			{
				cout << "error" << endl;
				insert(number);
			}
		}
	}
	return 0;
}
