#include <iostream>
#include<cstring>
using namespace std;
//链表结点类定义

class ListNode
{
public:
	int data;
	string name;
	ListNode* next;
	ListNode() { next = NULL; }
};


//带头结点的单链表类定义
class LinkList
{
public:
	ListNode* head;
	int len;
	//操作定义
	LinkList();
	~LinkList();
	ListNode* LL_index(int i);//返回第i个结点的指针，如果不存在返回NULL
	int LL_get(int i);//获取第i个元素的数据
	int LL_insert(int i, int room, string name);//把数值room,name插入第i个位置
	int LL_del(int i);//删除第i个结点
	void LL_display();//输出单链表的内容
	void set(int n);
	int push_back(int nu, string na = " ")
	
	{
		ListNode* p = new ListNode;
		ListNode* q = LL_index(len);
		p->data = nu;
		p->name = na;
		q->next = p;
		len++;
		return 1;
	}
	void display_used();
	void display_free();
	
};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
LinkList::~LinkList()
{
	ListNode* p, * q;
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
ListNode* LinkList::LL_index(int i)
{
	if (i > len || i < 0)
		return NULL;
	ListNode* p = head;
	while (i--)
	{
		p = p->next;
	}
	return p;
}
void LinkList::LL_display()
{
	ListNode* p;
	p = head->next;
	while (p)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

int LinkList::LL_get(int i)
{
	if (i<1 || i>len)  // 下标合法不
	{
		
		return 0;
	}

	
	return LL_index(i)->data;
}
int LinkList::LL_insert(int i, int room, string na)
{
	if (i<1 || i>len + 1)  // 下标合法不
	{
		cout << "error" << endl;
		return 0;
	}

	ListNode* p = LL_index(i - 1);
	ListNode* q = new ListNode;
	q->data = room;
	q->name = na;


	if (i == len)
	{
		q->next = NULL;
	}
	else
	{
		q->next = p->next;
	}

	p->next = q;
	len++;

	return 1;
}
int LinkList::LL_del(int i)
{
	if (i<1 || i>len || head->next == NULL)  // 下标合法不

	{
		cout << "error" << endl;
		return 0;
	}
	ListNode* p = LL_index(i - 1);
	ListNode* q = p->next;
	p->next = q->next;
	delete q;
	len--;
	
	return 1;
}
void LinkList::set(int n)
{
	ListNode* p = head;
	ListNode* q;
	while (n--)
	{
		q = new ListNode;
		cin >> q->data;
		p->next = q;
		p = p->next;
		len++;
	}

}

void LinkList::display_free()
{
	ListNode* p = head->next;
	while (p != NULL)
	{
		cout << p->data;
		if (p->next != NULL)
		{
			cout << "-";
		}
		p = p->next;
	}
	cout << endl;

}
void LinkList::display_used()
{
	ListNode* p = head->next;
	while (p != NULL)
	{
		cout << p->name << "(" << p->data << ")";
		if (p->next != NULL)
		{
			cout << "-";
		}
		p = p->next;

	}
	cout << endl;
}
int main()
{

	LinkList free, used;
	int n, m, room;//已用宿舍n间,操作次数m
	string name;
	cin >> n;
	for (int i = 101; i <= 120; i++)
	{
		free.push_back(i, "0");
	}
	while (n--)
	{
		cin >> name >> room;
		used.push_back(room,name);
		for (int i = 0; i < free.len; i++)
		{
			if (room == free.LL_get(i))
			{
				free.LL_del(i);

			}
		}
	}
	cin >> m;
	string opera;
	while (m--)
	{
		cin >> opera;
		if (opera == "assign")
		{
			cin >> name;
			room = free.LL_get(1);
			free.LL_del(1);
			for (int i = 0; i < used.len; i++)//升序
			{
				if (used.LL_get(i) > room)
				{
					used.LL_insert(i, room, name);
					break;
				}
			}
		}
		else if (opera == "return")
		{
			cin >> room;
			for (int i = 0; i <=used.len; i++)
			{
				if (room == used.LL_get(i))
				{
					used.LL_del(i);
				}
			}
			free.push_back(room);
		}
		else if (opera == "display_free")
		{
			free.display_free();

		}
		else if (opera == "display_used")
		{
			used.display_used();
		}

	}

	return 0;

}
