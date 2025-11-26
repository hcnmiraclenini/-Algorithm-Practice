#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
//建立该二叉树的二叉链式存储结构
int w[1000];
int len[1000];
class Node
{
public:
    char data;
    Node* left;
    Node* right;
    int weight;
    Node()
    {
        left = NULL; right = NULL;
    }
};
int pos = 0;
class Tree
{
public:
    Node* root;//这棵树的根节点
    void createtree(Node*& root)//创建数
    {
        char ch;
        cin >> ch;
        if (ch == '0')//空树用字符‘0’表示
            root = NULL;
        else
        {
            root = new Node();
            root->data = ch;
            createtree(root->left);
            createtree(root->right);
        }

    }

    void create()
    {
        createtree(root);
    }
    void  setweight(Node*& r)
    {
        if (r)
        {
            if (r->data)
            {
                r->weight = w[pos++];
            }
            if(r->left!=NULL)
                setweight(r->left);
            if (r->right != NULL)
                setweight(r->right);
        }

    }
    void  setw()
    {
        setweight(root);
    }

    void getmaxlen(Node* p)
    {
        int i = 0;
        int number = 0;//统计路径数
  
        if (p->left == NULL && p->right == NULL)
        {
            number++;
            Node* q = root;
            while (q != p)
            {
                len[i++] += q->data;
                if (q->left)q = q->left; continue;
                if (q->right)q = q->right; continue;
            }
        }
        else if (p->left)  p = p->left;
        else  p = p->right;
        int  max = len[0];
        for (int i = 1; i < number; i++)
        {
            if (len[i] > max)   max = len[i];
        }
        cout <<"叶子数"<< number << endl;
        cout << max << endl;
    }

    void sum()
    {
        getmaxlen(root);
    }

};
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        pos = 0;
        
        Tree tree;
        tree.create();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        tree.setw();
        tree.sum();
     

    }
    return 0;
}