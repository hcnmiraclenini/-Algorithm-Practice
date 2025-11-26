#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
//输出每棵二叉树的最大路径权值，如果最大路径权值有重复，只输出1个
int w[1000];
class Node
{
public:
    char data;
    Node* left;
    Node* right;
    int weight;
    int layer;
    // int len_road;
    Node()
    {
        left = NULL; right = NULL;
    }
};
int pos = 0;
int len = 0;
int maxn;

class Tree
{
public:
    Node* root;//这棵树的根节点
    int count = 0;  int sum[1000];
    void createtree(Node*& root, int lay)//创建数
    {
        char ch;
        cin >> ch;
        if (ch == '0')//空树用字符‘0’表示
            root = NULL;
        else
        {
            root = new Node();
            root->data = ch;
            root->layer = lay;
            createtree(root->left, lay + 1);
            createtree(root->right, lay + 1);
        }

    }

    void create()
    {
        createtree(root, 0);
    }
    void  setweight(Node*& r)
    {
        if (r)
        {
            if (r->data >= 'A' && r->data <= 'Z')
            {
                r->weight = w[pos++];
            }
            if (r->left != NULL)
            {
                setweight(r->left);
            }
            if (r->right != NULL)
            {
                setweight(r->right);
            }
        }

    }
    void  setw()
    {
        setweight(root);
    }

    void getlen(Node* p, int road)
    {


        if (p)
        {
            p->weight = p->weight + road;

            if (p->left) getlen(p->left, p->weight);
            if (p->right)getlen(p->right, p->weight);
            if (p->left == NULL && p->right == NULL)
            {
                //cout << "每个叶子的所在路径长度为：" << p->len_road << endl;

                if (p->weight > maxn)
                {
                    maxn = p->weight;
                }
            }

        }

    }

    void getmax()
    {
        getlen(root, 0);
        //cout << "最大路径:" << endl;
        cout << maxn << endl;
    }



};
int main()
{

    int t, n;
    cin >> t;
    while (t--)
    {
        maxn = 0;
        pos = 0;
        len = 0;
        Tree tree;
        tree.create();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> w[i];
        }
        tree.setw();
        tree.getmax();


    }
    return 0;
}