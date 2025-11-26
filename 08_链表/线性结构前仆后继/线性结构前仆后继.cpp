#include <iostream>
using namespace std;
//链表结点类定义
class ListNode
{
public:
	int data;
	ListNode* next;
	ListNode* pre;

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
	int LL_get(int i);//获取第i个元素的数据
	void set(int n);
	void find(int k);
	ListNode* LL_index(int i);

};
LinkList::LinkList()
{
	head = new ListNode();
	len = 0;
	head->next = NULL;
	head->pre = NULL;
}
LinkList::~LinkList()
{
	delete head;
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

int LinkList::LL_get(int i)
{
	if (i<1 || i>len)  // 下标合法不
	{

		return 0;
	}

	return LL_index(i)->data;
}

void LinkList::set(int n)
{
	len = n;
	
	ListNode* p = head;
	ListNode* q;
	while(len)
	{
		q = new ListNode;
		cin >> q->data;
		p->next = q;
		q->pre = p;
		len--;
	}
	p->next = NULL;

}

void LinkList::find(int k)
{
	head = head->next;
	
	
			if ((LL_index(k)->pre != head) && (LL_index(k)->next != NULL))
			
				cout << LL_index(k)->pre->data << " " << LL_index(k)->next->data << endl;
			
			else if ((LL_index(k)->pre == head) && (LL_index(k)->next != NULL))
			
				cout << LL_index(k)->next->data << endl;
			
			else  
			
				cout << LL_index(k)->next->data << endl;
			
		
		
	}




int main()
{
	int n, m;//n代表节点个数，m代表要找的关键字的个数
	int key;
	cin >> n >> m;
	while (m)
	{
		LinkList l;
		l.set(n);
		cin >> key;
		l.find(key);
		m--;
	}
	return 0;

}
