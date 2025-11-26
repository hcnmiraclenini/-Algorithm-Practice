#include <iostream>
#include<queue>
using namespace std;


//用二叉链表存储树，用先序遍历的结果创建树
//对树做个镜面反转：所有非叶结点的左右孩子对换
//输出反转后树的先序、中序、后序遍历和层次遍历的序列
char s[100000];
int pos = 0;
class node
{
public:
	char data;
	node* l;
	node* r;
	node()
	{
		l = r = NULL;
	}
};

node* buildtree()
{
	char ch = s[pos++];
	if (ch == '#')
		return NULL;
	else
	{
		node* p = new node;
		p->data = ch;
		p->l = buildtree();
		p->r = buildtree();
		return p;
	}

}
//镜面反转函数  把非叶节点的左孩子和右孩子互换 
//从根节点开始，对左子树调用函数，在对右子树调用函数，最后交换左右子树
void exchange(node* p)
{
	if (p)
	{
	    exchange(p->l);
		 exchange(p->r);
			node* temp = p->l;
			p->l = p->r;
			p->r = temp;
	}

}
void pre(node* t)
{
	if (s[0] == '#')
		cout << "NULL";
	else
	{
		if (t)
		{
			cout << t->data << " ";
			pre(t->l);
			pre(t->r);
		}
	}
}
void in(node* t)
{
	if (s[0] == '#')
		cout << "NULL";
	else
	{
		if (t)
		{

			in(t->l);
			cout << t->data << " ";
			in(t->r);
		}
	}
}
void post(node* t)
{
	if (s[0] == '#')
		cout << "NULL";
	else
	{
		if (t)
		{

			post(t->l);
			post(t->r);
			cout << t->data << " ";
			
		}
	}
}
void level(node* t)
{
	if (s[0] == '#')
		cout << "NULL";
	else
	{
		queue<node*>qu;
		
		node* p=t;
		qu.push(t);
		while (1)
		{
			p = qu.front();
			qu.pop();
			cout << p->data << " ";
			if (p->l)
				qu.push(p->l);
			if (p->r)
				qu.push(p->r);
			if (qu.empty())
				break;
		}

	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		pos = 0;
		node* head;
		head=buildtree();
		exchange(head);
		pre(head);
		cout << endl;
		in(head);
		cout << endl;
		post(head);
		cout << endl;
		level(head);
		cout << endl;
	}




	return 0;
}


