#include<iostream>
#include<stack>
#include<queue>
#include <vector>
#include<cstring>
#define ok 1;
#define error -1;
using namespace std;
class Node
{
public:
    int parent, lchild, rchild;
    int id;
    int weight;
    char value;
    //int code[10000];//每个结点的编码
    Node(int w, int i, char c)
    {
        weight = w;  parent = lchild = rchild = -1;
        id = i;//存入的顺序
        value = c;
    }
    Node()
    {
        weight = parent = lchild = rchild = -1;
    }

};

struct cmp
{
    bool operator()(const Node& a, const Node& b)const//优先级队列重载运算符
    {
        if (a.weight != b.weight) return a.weight > b.weight; //优先对列的排序还要加入一个序号
        return a.id > b.id;                                   //看数据我们会发现同样两个4第一个4在左边，第二个在右边。
    }
};
int cnt = 0;
class Tree
{
public:
    int n, len;
    Node* tr;//创建树的指针
    string* code;  //动态分配 多少个结点就多少个码
    void  bulidtree()
    {
        priority_queue<Node, vector<Node>, cmp>q;  //创建优先队列 排列权值
        cin >> n;  //结点数
        int  a[1000];   //输入权值
        char ch[1000];
        int i = 0;
        tr = new Node[2 * n];
        len = 2 * n - 1;
        code = new string[n * 2];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> ch[i];
        }
        for (i = 0; i < n; i++)
        {

            tr[i] = Node(a[i], i, ch[i]);
            q.push(tr[i]);
        }
        while (q.size() > 1) //要保证优先队列里必须要有两个及以上的结点，因为一次要弹两个
        {
            Node l = q.top(); q.pop();
            Node r = q.top(); q.pop();
            tr[l.id].parent = tr[r.id].parent = i;
            tr[i].lchild = l.id;
            tr[i].rchild = r.id;
            tr[i].id = i;
            tr[i].weight = tr[l.id].weight + tr[r.id].weight;
            q.push(tr[i]);
            i++;
        }
        len = i - 1; //len = i - 1,你的len的意思是根节点，所以应该是 i - 1
    }
    void findcode()
    {
        int start, fa, j, i;  //start 从哪里开始求编码 fa该结点父亲 j，i循环变量
        char co[100000];
        co[len - 1] = '0';
        for (i = 0; i < n; i++)
        {
            start = len - 1;
            for (j = i, fa = tr[i].parent; fa >= 0; j = fa, fa = tr[fa].parent) //fa不是！=0 而是要大于-1因为你的根结点是-1
            {                                                                   //j初始值不是等于0而是等于i,因为你的j代表的是最开始的结点编号
                                                                                //tr[fa].lchild == j才不会出错
                if (tr[fa].lchild == j)
                {
                    co[--start] = '0';
                }
                else
                {
                    co[--start] = '1';
                }
            }
            code[i].assign(&co[start]);  //求出来该结点的编码
        }
    }

    //输入编码串codestr，输出解码串txtstr
    //解码成功则返回ok，解码失败则返回error
    int  Decode(const string codestr, char txtstr[])
    {
        //编码0表示往左孩子移动，编码1表示往右孩子移动
        int a = len, i = 0;
        int  j = 0;
        int codestr_len = codestr.length();
        char letter;
        for (i = 0; i < codestr_len; i++)
        {
            letter = codestr[i];  //letter不应该是单纯等于codestr[0] 每次都要更新
            if (letter == '0')
                a = tr[a].lchild;
            else if (letter == '1')
                a = tr[a].rchild;
            else
                return error;//无找到编码
            if (tr[a].lchild == -1 && tr[a].rchild == -1)
            {
                txtstr[j++] = tr[a].value;
                a = len;
                continue;
            }
            else  letter = '\0';
        }
        if (letter == '\0')
        {
            return error;
        }
        else
        {
            txtstr[j] = '\0';
        }
        return ok;

    }
};


int main()
{
    int t, k;
    cin >> t;
    while (t--)
    {
        Tree tree;
        tree.bulidtree();
        tree.findcode();
        string code;//原码
        char r[10000];//解码
        cin >> k; //表示要输入k个编码串
        while (k--)
        {
            cin >> code;
            if (tree.Decode(code, r) == 1)
            {
                cout << r << endl;
            }
            else
            {
                cout << "error" << endl;
            }
        }


    }
    return 0;
}