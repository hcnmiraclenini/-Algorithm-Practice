#include <iostream>
#include<queue>
using namespace std;
class Node
{
public:
    char data;
    Node* l, * r;
    int w;//权值
    int layer;//第几层
    Node()
    {
        data = '0', r = l = NULL; w = layer = 0;
    }

};
queue<Node*>que;
queue<Node*>faque;
Node* buildtree(Node* h)
{
    Node* q;
    char a;
    cin >> a;
    if (a == '0')
    {
        q = NULL;
    }
    else
    {
        q = new Node;
        q->data = a;
        q->f = h;
        q->l = buildtree(q);
        q->r= buildtree(q);
    }
    return q;
}

void find(Node* h)
{
   if (h != NULL)
    {
       if (h->l == NULL && h->r == NULL)
       {
           que.push(h);
           faque.push(h->f);
        //   cout << h->data << endl;
       }
        find(h->l);
        find(h->r);
    }
  
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node* head = NULL;
        head=buildtree(head);//重点  ！！
      
        cout << endl;
    }
    return 0;
}

