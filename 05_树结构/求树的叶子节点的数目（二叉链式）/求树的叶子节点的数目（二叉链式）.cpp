#include <iostream>
using namespace std;
//建立该二叉树的二叉链式存储结构
class Node
{
public:
    char data;
    Node* lChild;
    Node* rChild;
    Node()
    {
        lChild = NULL;
        rChild = NULL;

    }
};
Node* CreateTree(Node* N)//必须用引用：改变传入指针自身的值
{
    
    char ch;
    cin >> ch;
    if (ch == '0')
    {
      Node*p = NULL;
      return p;
    }
    else
    {
        Node* p = new Node;
        p->data = ch;
        p->lChild=CreateTree(p);
        p->rChild=CreateTree(p);
        return p;
    }

}
int num = 0;
void findleaf(Node* N)
{

    if (N)
    { 
        if (!N->lChild && !N->rChild)
        {
            num++;
        }
        else
        {
            findleaf(N->lChild);
            findleaf(N->rChild);
        }
    }
    return ;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        num = 0;
        Node* p = NULL;
        p=CreateTree(p);
        cout << num << endl;
    }
    return 0;
}
