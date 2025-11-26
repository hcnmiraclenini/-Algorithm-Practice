#include <iostream>
using namespace std;
//链表结点类定义
class ListNode
{
public:
	int data;
	ListNode* next;
	
};

//带头结点的单链表类定义
class LinkList
{
public:
	ListNode* head;
	int len;
	int N, K, S;
	//操作定义
	LinkList();
	~LinkList();
	//int LL_get(int i);//获取第i个元素的数据
	//void LL_display();//输出单链表的内容
	void set(int n,int s,int k);
	void delete_(LinkList& L);
	void game();

};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
}
LinkList::~LinkList()
{
	delete head;
}
/*ListNode* LinkList::LL_index(int i)
{
	if (i > len || i < 0)
		return NULL;
	ListNode* p = head;
	while (i--)
	{
		p = p->next;
	}
	return p;
}*/
/*void LinkList::LL_display()
{
	ListNode* p;
	p = head->next;
	while (p&&p->next!=NULL)
	{
		cout << p->data << ' ';
		p = p->next;
	}
	cout << p->data << endl;
}*/

/*int LinkList::LL_get(int i)
{
	if (i<1 || i>len)  // 下标合法不
	{
		
		return 0;
	}

	return LL_index(i)->data;
}*/

void LinkList::set(int n,int k,int s)
{
	len = n;
	N = n;
	K = k;
	S = s;
	ListNode* p = head;
	ListNode* q;
	for(int i=1;i<=N;i++)
	{
		q = new ListNode;
		 q->data=i;
		p->next = q;
		p = p->next;
	
	}
	p->next = head;

}

void LinkList::game()
{
	ListNode* p = head;
	for (int i =0; i < S - 1; i++)
	{
		p = p->next;
	}
	while(len)
	{
		if (p->next == head)
		{
			p = p->next;
		}
		for (int j= 0; j < K - 1; j++)
		{
			p = p->next;
			if (p->next == head)
			{
				p = p->next;
			}

		}
		
		if (len == 1)
		{
			cout << p->next->data << endl;
		}
		else
		{
            cout << p->next->data <<' ';
		}
		
		p->next = p->next->next;
		
		len--;
		
	}
	
}
/*从第S个人开始报数，
数到K的人出列，
后面的人重新从1开始报数。
问最后剩下的人的编号。*/

/*输出
出列的人的编号*/
int main()
{
	int n,k,s;
	
	while (cin >> n>>k >> s)
	{
		LinkList l;
		l.set(n, k, s);
		l.game();
	}
	return 0;

}
