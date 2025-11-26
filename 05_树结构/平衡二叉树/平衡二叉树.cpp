#include<stdio.h>
#include<iostream>
using namespace std;
const int maxn = 100000;
//
/*1 D K 表示插入一个新数据，数据为D用于输出，关键值为K用于排序；
2 输出当前树中最大关键值所带的数据，并删除该数据，如果没有这个关键值，则输出0；
3 输出当前树中最小关键值所带的数据，并删除该数据，如果没有这个关键值，则输出0；
4 K 输出关键值为 K 的数据，并删除该数据，如果没有这个关键值，则输出0。
*/
struct Node
{
    int key;        // 关键值
    int data;       // 携带的数据
    int left;       // 左子树地址（数组下标）
    int right;      // 右子树地址（数组下标）
    int height;     // 当前结点为根的子树高度
    void Init() { data = key = left = right = height = -1; }
    void Init(int k_, int d_ = 0) { Init(); key = k_; data = d_; }
    Node() { Init(); }
    Node(int k_, int d_ = 0) { Init(k_, d_); }
};

Node tr[maxn];
int root, tp;  // root标记根节点位置，tp全局结点分配下标

inline int UpdateHeight(int now)
{
    // 更新 tr[now] 结点的子树高度，即tr[now].height的值
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return tr[now].height = (lh > rh ? lh : rh) + 1;
}
inline int HeightDiff(int now)
{
    // 计算 tr[now] 结点的平衡因子
    int lh = tr[now].left == -1 ? 0 : tr[tr[now].left].height;
    int rh = tr[now].right == -1 ? 0 : tr[tr[now].right].height;
    return lh - rh;
}
int LL(int an)
{
    int bn = tr[an].left;
    int dn = tr[bn].right;
    tr[bn].right = an;
    tr[an].left = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}
int RR(int an)
{
    int bn = tr[an].right;
    int dn = tr[bn].left;
    tr[bn].left = an;
    tr[an].right = dn;
    UpdateHeight(an);
    UpdateHeight(bn);
    return bn;
}
int LR(int an)
{
    tr[an].left = RR(tr[an].left);
    return LL(an);
}
int RL(int an)
{
    tr[an].right = LL(tr[an].right);
    return RR(an);
}
void Insert(int &now, int key, int data )
{
    if (now == -1)
    {
        // 传入指针为空，新建结点保存数据
        now = tp++;
        tr[now].Init(key, data);
    }
    // 判断插入哪个子树，插入数据，判断平衡因子，做正确旋转，更新高度
    else if (key < tr[now].key)
    {
        Insert(tr[now].left, key, data);
        if (HeightDiff(now) == 2)
            now = key < tr[tr[now].left].key ?
            LL(now) : LR(now);
    }
    else if (key > tr[now].key)
    {
        Insert(tr[now].right, key, data);
        if (HeightDiff(now) == -2)
            now = key > tr[tr[now].right].key ?
            RR(now) : RL(now);
    }
    UpdateHeight(now);
}
int cnt;
void Deletesth(int &now, int key)
{
   // cout << "调用了删除函数!!" << endl;
    if (now == -1) return;
    else if (key < tr[now].key) Deletesth(tr[now].left, key);
    else if (key > tr[now].key) Deletesth(tr[now].right, key);
    else 
    {
        if (cnt == 0)
            cnt = tr[now].data;
        if (tr[now].left == -1)
            now = tr[now].right;
        else if (tr[now].right == -1)
            now = tr[now].left;
        else 
        {
            int nd;
            for (nd = tr[now].left;; nd = tr[nd].right)
              if (tr[nd].right == -1)
                  break;
            tr[now].key = tr[nd].key;
            tr[now].data = tr[nd].data;
            Deletesth(tr[now].left, tr[nd].key);
         }
    }
        if (now == -1) return;
        UpdateHeight(now);
        if (HeightDiff(now) == 2)
        {
            now = HeightDiff(tr[now].left>= 0) ?
                LL(now) : LR(now);
        }
        else if (HeightDiff(now) == -2)
        {
            now = HeightDiff(tr[now].right <= 0) ?
                RR(now) : RL(now);
        }
        // 处理树平衡

    
}
void Deletemax(int& now)
{
    if (tr[now].right != -1) Deletemax(tr[now].right);
    else
    {
        cnt = tr[now].data;
        now = tr[now].left;
    }
    if (now == -1) return;
    UpdateHeight(now);
    if (HeightDiff(now) == 2)
        now = HeightDiff(tr[now].left) >= 0 ? LL(now) : LR(now);
    else if (HeightDiff(now) == -2)
        now = HeightDiff(tr[now].right) <= 0 ? RR(now) : RL(now);

}
void Deletemin(int& now)//左子树的值比根节点小
{
    if (tr[now].left != -1)
        Deletemin(tr[now].left);
    else
    {
        cnt = tr[now].data;
        now = tr[now].right;
    }
    if (now == -1)
        return;
    UpdateHeight(now);//更新高度
    if (HeightDiff(now) == 2)
        now = HeightDiff(tr[now].left) >= 0 ? LL(now) : LR(now);
    else if (HeightDiff(now) == -2)
        now = HeightDiff(tr[now].right) <= 0 ? RR(now) : RL(now);
    
}
/*void print()
{
    for (int i = 1; i <=tp; i++)
    {
        cout<<tr[i].key << " ";
    }
}*/
int main()
{
    int n, op, key, data;

    while (cin >> n)
    {
        for (root =-1,tp = 0; n--; )  // 初始化根结点和“内存指针”
        {
            cin >> op;
            if (op == 1)  //插入一个新数据，这里不需要输出
            {
                
               
                cin >> data >> key;
                Insert(root, key, data);
                
            //    cout << "打印一下树中所有的键值:" << " ";
               // print();
              //  cout << endl;
            }
            else if (op == 2)
            {
            
              //  int max = root;
         
               // cout << "tp是：" <<tp << endl;
                if (root == -1)
                {
                   // cout << "!";
                    cout << "0" << endl;
                }
                else  //有数据
                {
                  
                   /* while (tr[max].right != -1)
                    {
                        max = tr[max].right;
                    }*/
               
                        //cout << "!";
                       // cout << "最大值关键值所带的数据是：";
                       // cout << tr[max].data << endl;
                        Deletemax(root);
                        cout << cnt << endl;
                  }
                }
               
            else if (op == 3)
            {
              // int  min = root;
              
              //  cout << "tp是：" << tp << endl;
                if (root == -1)
                {
                    //cout << "!";
                    cout  << "0" << endl;
                }
                else
                {

                    /*while (tr[min].left != -1)
                    {
                        min = tr[min].left;
                    }
                
                  //  cout << "!";
                  //  cout << "输出最小键值所带的数据是：";
                    cout << tr[min].data << endl;*/
                    Deletemin(root);
                    cout << cnt << endl;
                }
            }
            else
            {
             
                cin >> key;
         
               /* for (int i = 0; i < tp; i++)
                {
                    if (tr[i].key == k)
                    {
                       // cout << "!";
                        cout << tr[i].data << endl;
                        Delete(root, k);
                        flag = 1;
                    }
                }*/
                cnt = 0;
                Deletesth(root, key);
                cout << cnt << endl;

            }
        }
        return 0;
    }
}