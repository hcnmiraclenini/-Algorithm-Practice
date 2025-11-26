#include<iostream>
#include<stack>
#include<queue>

using namespace std;
class Node//存储
{
public:
	int parent, lchild, rchild;
	int weight;
	//int code[10000];
	Node(int w)
	{
		weight = w;  parent = lchild = rchild = 0;
	}
	Node()
	{
		weight = parent = lchild = rchild = 0;
	}
	bool operator<(const Node& that)const
	{
		return weight > that.weight;
	}
};
class Tree
{
public:
	int n,len;//len总结点树
	Node* tr;
	string* code;
	void  bulidtree()
	{
		priority_queue<Node>q;
		int  a;
		cin >> n;
		tr = new Node[2 * n];
		
		
		code = new string[len + 1];
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			q.push(Node(a));
		}
		for (int i =n; i < len&& !q.empty();i++)
		{
			int l = q.top().weight; q.pop();
			int r = q.top().weight; q.pop();
			tr[l].parent = tr[r].parent = i;
			tr[i].lchild = l;
			tr[i].rchild = r;
			tr[i].weight = tr[l].weight + tr[r].weight;

		}
		
		
	}
	void findcode()
	{
		int start,fa,j,i;
		char co[100000];
		for (i = 0; i < len; i++)
		{
			start = len - 1;
			for (j = 0, fa = tr[i].parent; fa != 0; j = fa, fa = tr[fa].parent)
			{
				if (tr[fa].lchild == j)
				{
					co[--start] = '0';
				}
				else
				{
					co[--start] = '1';
				}
			}
			code[i].assign(&co[start]);
		}
	}
	void print()//格式如下：权值 - 编码
	{
		for (int i = 0; i < n; i++)
		{
			cout << tr[i].weight << "-" << code[i] << endl;
		}
	}
 };


int main()
{
	int t, n_;
	cin >> t;
	int w[1000];//权值
	while (t--)
	{
		Tree tree;
		tree.bulidtree();
		void print();
	}
	return 0;
}