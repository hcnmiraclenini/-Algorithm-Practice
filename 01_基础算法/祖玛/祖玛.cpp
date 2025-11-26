#include <iostream>
#include<cstring>
using namespace std;
class Listnode
{
public:
	char data;
	Listnode* next;
	Listnode* pre;
};
class Linklist
{
public:
	Listnode* head;
	int len;
	//操作定义
	Linklist();
	~Linklist();
	Listnode* LL_index(int i);//返回第i个结点的指针，如果不存在返回NULL
	int LL_get(int i);//获取第i个元素的数据
	int LL_insert(int i, int item);//把数值item插入第i个位置
	int LL_del(int i);//删除第i个结点
	void LL_display();//输出单链表的内容
	void game();
	void delete_(Linklist& L);
};
Linklist::Linklist()
{
	head = new Listnode;
}
Linklist::~Linklist()
{
	Listnode* p, * q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete q;
	}
	len = 0;
	head = NULL;
}
Listnode* Linklist::LL_index(int i)
{

	Listnode* p = head;
	while (i--)
	{
		p = p->next;
	}
	return p;
}
void Linklist::LL_display()
{
	Listnode* p;
	p = head->next;
	while (p && p->next != NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << p->data << endl;
}

int Linklist::LL_get(int i)
{
	if (i<1 || i>len)  // 下标合法不
	{

		return 0;
	}

	return LL_index(i)->data;
}
int Linklist::LL_insert(int i, int item)
{
	Listnode* p = LL_index(i - 1);
	Listnode* q = new Listnode;
	q->data = item;
	q->next = p->next;
	q->pre = p;
	if(p->next)
	p->next->pre = q;
	p->next = q;
	len++;

	return 1;
}
int Linklist::LL_del(int i)
{
	if (i<1 || i>len || head->next == NULL)  // 下标合法不

	{

		return 0;
	}
	Listnode* p = LL_index(i - 1);
	Listnode* q = p->next;
	p->next = q->next;
	delete q;
	len--;

	return 1;
}

void Linklist::delete_(Linklist& L)
{
	for (int i = 0; i < L.len; i++)
	{
		for (int j = i + 1; j <= L.len; j++)
		{
			if (L.LL_get(j) == L.LL_get(i))
			{
				L.LL_del(j);
				delete_(*this);
			}
		}
	}

}
void Linklist::game()
{
	int n, k,temp;//操作次数n  新珠子嵌入在轨道上的位置k  临时变量temp
	char ch;
	string s;
	cin >> s;
	Listnode* p = head;
	Listnode* q;
	int len = s.size();
	for (int i = 0; i < len; i++)
	{
		q = new Listnode;
		q->data = s[i];
        q->pre = p;
		p->next = q;
		p = q;
	}
	cin >> n;
	int count=0;
	while(n--)
	{
	
		cin >> k >> ch;
		p = head;
		temp = k;
		while (temp--)
		{
			p = p->next;
		}
		Listnode* q = new Listnode;
		q->data =ch;
		q->next = p->next;
		q->pre = p;
		if (p->next)
			p->next->pre = q;
		p->next = q;
		len++;
		for (int i = 0; i < len; i++)
		{
			if (p && p->next && p->pre && p->pre->data == p->data
				&& p->next->data == p->data)
			{
				char a = p->data;//四个消消乐的时候
				LL_del(i - 1);
				LL_del(i - 1);
				LL_del(i - 1);
				if (len != 0)
				{
					if (this->LL_index(i - 1)->data == a)
					{
						LL_del(i - 1);
					}
				}
				p = head;
				i = 0;
			}
			if (p)
				p = p->next;
		}
		if (len == 0)
		{
			cout << "-";
		}
		for (int i = 0; p && i < len; i++)
		{
			cout << p->data;
			p = p->next;
		}
		cout << endl;
	}
}
int main()
{
	
	Linklist l;
	l.game();
	return 0;
}



