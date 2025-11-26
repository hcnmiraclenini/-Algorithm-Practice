#include <iostream>
using namespace std;
//建立该二叉树的二叉链式存储结构
char child[1000];
char father[1000];
int i = 0;
class Node
{
public:
    char data;
    Node* lChild;
    Node* rChild;
    Node* father;
    Node()
    {
        lChild = NULL;
        rChild = NULL;
        father = NULL;
    }
};
Node* CreateTree(Node* N)//必须用引用：改变传入指针自身的值
{

    char ch;
    Node* q ;
    cin >> ch;
    if (ch == '0')
    {
        q = NULL;
    }
    else
    {
        q = new Node;
        q->data = ch;
        q->father = N;
        q->lChild=CreateTree(q);
       q->rChild=CreateTree(q);
    }
    return q;
}
int findleaf(Node* N)
{

    if (N && !N->lChild && !N->rChild)//叶子
    {
        //cout << '8';
        child[i] = N->data;
        father[i] = N->father->data;
        i++;
        return 1;
    }
    else if (N)
    {
       // cout << "666";
        int l = findleaf(N->lChild);
        int r = findleaf(N->rChild);
        return l + r;
    }
    return 0;


}


int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {

        Node* p = NULL;
        p =CreateTree(p);
      //cout << findleaf(p, child, father) << endl;
        i = 0;
        int num = findleaf(p);
     
        for (int i = 0; i < num; i++) {
            cout << child[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < num; i++) {
            cout << father[i] << ' ';
        }
        cout << endl;
    }
   
    return 0;
}