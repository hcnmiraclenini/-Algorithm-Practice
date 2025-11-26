
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
const int maxn = 1e3 + 10;
class Node
{
public:
    int v;
    int left, right;
    void Init() { left = right = v = -1; }//初始化
    Node() { Init(); }
};
Node bt[maxn];
char buf[maxn];
int p, tp;
void Build(int now) //构建二叉树
{
    if (buf[p] == '\0') return;
    bt[now].v = buf[p];
    if (bt[now].v == '#') return;
    if (bt[now].left == -1)
    {
        bt[now].left = tp;
        bt[tp++].Init();
    }
    p++;
    Build(bt[now].left);
    if (bt[now].right == -1)
    {
        bt[now].right = tp;
        bt[tp++].Init();
    }
    p++;
    Build(bt[now].right);
}
void Pre(int now)   //前序遍历
{
    if (bt[now].v == '#')return;
   cout<< (char)bt[now].v;
    Pre(bt[now].left);
    Pre(bt[now].right);
}
void In(int now)     //中序遍历
{
    if (bt[now].v == '#')return;
    In(bt[now].left);
    cout<< (char)bt[now].v;
    In(bt[now].right);
}
void Post(int now)    //后序遍历
{
    if (bt[now].v == '#')return;
    Post(bt[now].left);
    Post(bt[now].right);
    cout<< (char)bt[now].v;
}
int main()
{
    int t;
    for (cin>>t; t--; )
    {
        cin >> buf;
        p = tp = 0;
        bt[tp++].Init();
        Build(0);
        Pre(0);
        cout << endl;
        In(0);
        cout << endl;
        Post(0);
        cout << endl;
    }
    return 0;
}