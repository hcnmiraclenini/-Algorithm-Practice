#include <iostream>
using namespace std;
const int maxn = 1000;
class Node
{
public:
    int v;
    Node* left;
    Node* right;
    Node()
    {
        Init();
    }
    void Init()
    {
        v = 0; left = right = NULL;
    }
};
//建立一棵树
void build(Node*& T, int num)
{

    if (!T)
    {
        T = new Node;
        T->v = num;
    }

    if (num == T->v)
        return;
    if (num < T->v)
    {
        build(T->left, num);
    }

    else
    {
        build(T->right, num);
    }

}

//删除函数
void deletefun(Node*& T, int num)
{
    if (!T) return;
    if (num > T->v)
    {
       // cout << "big" << endl;
        deletefun(T->right, num);
    }
    if (T->v == num)
    {
      //  cout << "!!!" << endl;
        if (T->left == NULL)
        {

            T = T->right;//第一处

        }
        //要删除的结点只有一颗右子树
        else if (T->right == NULL)
        {
            T = T->left;//第二处
        }
        //要删除的结点左右子树都有
        //直接前继：要删除的结点的左子树的最右下结点
        //直接后继：要删除的结点的右子树的最左下结点
        else
        {
            Node* pre = T;
            Node* nex = T->left;
            while (nex->right)
            {
                pre = nex;
                nex = nex->right;
            }
            T->v = nex->v;
            if (pre == T) pre->left = nex->left;
            else pre->right = nex->left;
            delete nex;
        }
    }
        else
        {
        //    cout << "small" << endl;
            deletefun(T->left, num);
        }
   
}
    //删除结点是叶节点就直接删除掉
    //if (now == T)
    //{
    //    delete now;//第三处：此处把整棵树都删了
    //}
    //要删除的结点只有一颗左子树


void print(Node* T)
{
    if (T)
    {
        print(T->left);
        cout << T->v << " ";
        print(T->right);
    }

}
int main()
{
    int t, n, m;
    cin >> t;
    int number;

    while (t--)
    {
        Node* tree = NULL;
        cin >> n;
        //这颗数有多少个结点
        while (n--)
        {
            cin >> number;
            build(tree, number);

        }
        print(tree);
        cout << endl;

        //m是要删除多少个结点
        cin >> m;
        while (m--)
        {
            cin >> number;
  
            deletefun(tree, number);
            print(tree);
            cout << endl;
        }
    }
    return 0;
}
