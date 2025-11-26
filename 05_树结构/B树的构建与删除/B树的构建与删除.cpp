#include <iostream>    
#include <queue> 
using namespace std;

int m;

class BTNode
{
public:
    int keyNum; // 关键字个数 
    BTNode* parent; // 指向双亲结点 
    int* keys; // 关键字向量 
    BTNode** ptr; // 子树指针向量 
    BTNode()
    {
        keyNum = 0;
        parent = NULL;
        keys = NULL;
        ptr = NULL;
        keys = new int[m + 1];
        ptr = new BTNode * [m + 1];
        for (int i = 0; i <= m; i++)
        {
            keys[i] = -1;
            ptr[i] = NULL;
        

        }
    }

    ~BTNode()
    {
        keyNum = 0;
        parent = NULL;
        keys = NULL;
        ptr = NULL;
    }
};

class Result
{
public:
    BTNode* pt; // 指向找到的结点
    int i;
    int tag;
    Result(BTNode* p, int m, int t)
    {
        pt = p;
        i = m;
        tag = t;
    }

    ~Result()
    {
        pt = NULL;
        i = 0;
        tag = 0;
    }
};

class BTree
{
private:
    BTNode* root;
    void insert(BTNode* t, int i, int k, BTNode* ap); // 将k和ap分别插入t->key[i+1]和t->ptr[i + 1] 
    int search(BTNode* t, int k); // 在p->key[1...keynum]中查找 k
    void split(BTNode* q, int s, BTNode*& ap); // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap 
    void newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap); // 生成含信息(t, x, ap)的新根结点t*ap, 原t和 ap为子树指针
    void insertBT(BTNode*& t, int k, BTNode* q, int i); // 在结点t的子结点q的key[i]与key[i+1]之间插入k 
    Result* searchBT(BTNode* t, int k); // 在结点t中查找k 
public:
    BTree();
    ~BTree();
    void insertBT(int key); // B-树插入操作 
    void searchBT(int key); // B-树查找操作 
    void levelOrder(); // B-树层次遍历 
};

void BTree::insert(BTNode* t, int i, int k, BTNode* ap)
{// 将k和ap分别插入t->key[i+1]和t->ptr[i + 1]
    if (t) {
        if (t->keys[i + 1] != -1) {
            for (int j = t->keyNum; j >= i + 1; j--) 
            {
                t->keys[j + 1] = t->keys[j];
                t->ptr[j + 1] = t->ptr[j];
            }

        }

        if (ap)
        ap->parent = t;
        t->keyNum++;
        t->ptr[i + 1] = ap;
        t->keys[i + 1] = k;
       

    }

}

int BTree::search(BTNode* t, int k)
{
    // 在p->key[1...keynum]中查找 k
    int i ;
    for (i=0; i < t->keyNum && k >= t->keys[i + 1]; i++);

    return i;
}

void BTree::split(BTNode* q, int s, BTNode*& ap)
{
    // 将q->key[s+1...m],q->ptr[s...m]移入新结点ap 
    ap = new BTNode;
    int i, j;
    for ( i = s + 2, j = 1; i <= m; i++, j++) {
        ap->keys[j] = q->keys[i];
        q->keys[i] = -1;
        ap->keyNum++;
        q->keyNum--;
    }
    for (i = s + 1, j = 0; i <= m; i++, j++) {
        ap->ptr[j] = q->ptr[i];
        q->ptr[i] = NULL;
    }

}

void BTree::newRoot(BTNode*& t, BTNode* q, int x, BTNode* ap)
{ // 生成含信息(t, x, ap)的新根结点t, 原t和 ap为子树指针
    if (t) {
        BTNode* p = new BTNode();
        p->ptr[0] = t;
        p->ptr[1] = ap;
        t->parent = ap->parent = p;
        p->keys[p->keyNum + 1] = x;
       
        p->keyNum++;
        t = p;
    }
    else {
        t = new BTNode();
        t->keyNum++;
        t->keys[1] = x;
        t->ptr[0] = ap;
    }
   
}

Result* BTree::searchBT(BTNode* t, int k)
{
    // 参考课本240页算法9.13
    BTNode* temp = t;
    BTNode* q = NULL;
    bool found = false;
    int i = 0;
    while (temp && !found)
    {
        i = search(temp, k);
        if (i > 0 && temp->keys[i] == k)
            found = true;//找到待查关键字
        else
        {
            q = temp;
            temp = temp->ptr[i];
        }

    }
    if (found)
    {
        Result* result = new Result(temp, i, 1);
        return  result;   //查找成功
    }
    else
    {
        Result* result = new Result(q, i, 0);
        return  result;              //查找不成功，返回k的插入位置信息
    }
}



void BTree::insertBT(BTNode*& t, int k, BTNode* q, int i)
{
    // 参考课本244页算法9.14
    /*思路：在m阶B - 树上结点 * q的key[i]和key[i + 1]之间插入关键字k
    若引起结点过大，则沿着双亲链进行必要的结点分裂调整，使这棵树仍然是m阶B-树。
    */
    int x = k; BTNode* ap = NULL;
    bool finished = false;
    while (q && !finished) {
        insert(q, i, x, ap);
        if (q->keyNum < m)
            finished = true;
        else {
            int s = (int)m / 2;  //向下取整
            split(q, s, ap);
            x = q->keys[s + 1];
            q->keyNum--;
            q->keys[s + 1] = -1;
            q = q->parent;
            if (q)
                i = search(q, x);
        }
    }
    if (!finished)newRoot(t, q, x, ap);
}

// B树初始化 
BTree::BTree()
{
    root = NULL;
}

BTree::~BTree()
{
    root = NULL;
}

// B-树插入操作
void BTree::insertBT(int key)
{
    Result* r = searchBT(root, key);
    if (!r->tag)
    {
        insertBT(root, key, r->pt, r->i);
    }
    return;
}

// B-树查找操作
void BTree::searchBT(int key)
{
    Result* r = searchBT(root, key);
    if (!r->tag)
    {
        cout << "-1" << endl;
    }
    else
    {
        BTNode* p = r->pt;

        cout << p->keys[1];
        for (int i = 2; i <= p->keyNum; i++)
        {
            cout << ':' << p->keys[i];
        }
        cout << ' ' << r->i << endl;

    }

    return;
}

// B-树层次遍历输出关键字 
void BTree::levelOrder()
{
    queue<BTNode*> tq;
    BTNode* p = root;
    // 首结点入队 
    if (p)
    {
        tq.push(p);
    }
    // 层次遍历树 
    int flag = 0;
    while (!tq.empty())
    {
        p = tq.front();
        tq.pop();
        // 输出结点p的key 
        cout << p->keys[1];
        for (int i = 2; i <= p->keyNum; i++)
        {
            if (p->keys[i] != -1)
            { 
                cout << ':' << p->keys[i];
            }
        }
        if (tq.size() == 0 && flag == 1);
        else cout << ' ';

        flag = 1;
        // 自结点入栈 
        for (int i = 0; i < m; i++)
        {
            if (!p->ptr[i])
            {
                break;
            }
            tq.push(p->ptr[i]);
        }
    }
    return;
}

int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m;
        int n, k, key;
        // 构建B-树 
        cin >> n;
        BTree bTree;
        while (n--)
        {
            cin >> key;
            bTree.insertBT(key);
        }
        // 按层次遍历输出B-树 
        bTree.levelOrder();
        cout << endl;
        // 查找B-树结点 
        cin >> k;
        while (k--)
        {
            cin >> key;
            bTree.searchBT(key);
        }
    }
    return 0;
}

