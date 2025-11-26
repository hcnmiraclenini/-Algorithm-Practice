#include <iostream>
#include<cstring>
using namespace std;
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
int cot = 0;
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

void print(Node* T)
{
    if (T)
    {
        print(T->left);
        cout << T->v << " ";
        print(T->right);
    }

}
//int a[1000], tp = 0;

int  find(Node*& T, int p)//p是当前数据从小到大排列的第p个数
{
    
    cot++;
   if (T)
    {
       
       find(T->left, p);
       cot++;
       find(T->right,p);
       if (cot == p)
       {
           return T->v;
           
       }
      
    }
   else
   {
       return -1;
   }
   
   
}
int main()
{
    int n;//表示有n个操作
    cin >> n;
    int opera, number,place;
    Node* T = NULL;
    
    while (n--)
    {
     
        cin >> opera;
        if (opera == 1)//插入一个新数据
        {
            cin >> number;
            build(T, number);
           // print(T);
            //cout << endl;
        }
        else if (opera == 2)
        {
            cin >> place;
            cot =0;
            int num = find(T, place);
            if (num==-1)
            {
                cout << "-1" << endl;
                
           
            }
           else
            {
                cout << "这个数是" << num << endl;
                deletefun(T, num);
              
            }
        }
    //输出当前数据从小到大排列的第 K个数，并删除这个数，不存在则输出 - 1
    }
    return 0;
}
