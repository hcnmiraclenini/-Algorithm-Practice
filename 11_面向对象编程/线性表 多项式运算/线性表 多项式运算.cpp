#include <iostream>
#include<list>
#include<algorithm>
using namespace std;
class node
{
public:
    int co;//系数
    int exp;//指数

    node()
    {
        co = 0, exp = 0;
    }
    void init(int c = 0, int e = 0)
    {
        co = c; exp = e;
    }
    node(int c, int e)
    {
        co = c; exp = e;
    }

};
bool cmp(node*& n, node*& m)
{
    return m->exp > n->exp;
}
node* a[1000];
node* b[1000];
node* re1[1000];//两个多项式相加的结果
node* re2[1000];//两个多项式相减的结果
node* re3[1000];//两个多项式相乘的结果


void  newnode()
{
    for (int i = 0; i < 500; i++)
    {
        a[i] = new node;
        b[i] = new node;
        re1[i] = new node;
        re2[i] = new node;
        re3[i] = new node;
    }
}

void print(node* t[], int len)
{
  //  cout << len << endl;
    if (len == 0)
        cout << "0";
    else  if (len == 1 && (t[0]->co == 0))
        cout << "0";
    else
    {

        for (int i = 0; i < len; i++)
        {
            //系数等于0 不输出
            if (t[i]->co == 0)
                continue;
            //指数等于0，只输出系数

            else if (t[i]->exp == 0 && i == 0)
                cout << t[i]->co;

            else if (t[i]->exp == 0 && i > 0 && (t[i]->co > 0))

                cout << "+" << t[i]->co;

            else if (t[i]->exp == 0 && i > 0 && t[i]->co < 0)
                cout << "-" << (-t[i]->co);
            else
            {

                if ((i != 0) && (t[i]->co > 0))
                {
                    // cout << "&&";
                    cout << "+";
                }
                if (t[i]->exp)
                {
                    if (t[i]->co != 1 && t[i]->co != -1)
                        cout << t[i]->co;
                    else if (t[i]->co == -1)
                        cout << "-";
                    else if (t[i]->co == 1)
                        cout << "";
                    else  cout << t[i]->co;
                       


                    //输出指数部分
                    if (t[i]->co && t[i]->exp)
                    {
                        cout << "x";
                        if (t[i]->exp > 1)
                            cout << "^" << t[i]->exp;
                        if (t[i]->exp < 0)
                            cout << "^(" << t[i]->exp << ")";
                    }
                }

            }
        }
    }
    cout << endl;
}
void add(node* a1[], node* b1[], int n_, int m_)
{
    int p = 0;
    // cout << "调用了add函数" << endl;
    for (int i = 0, j = 0; i < n_ || j < m_;)
    {
        if (i < n_ && j < m_ && (a1[i]->exp == b1[j]->exp))
        {
            int t1 = a1[i]->co + b1[j]->co;
            if (t1)
                re1[p++]->init(t1, a1[i]->exp);
            i++, j++;

        }
        else if (i < n_ && j < m_ && a1[i]->exp < b1[j]->exp)
        {
            if (a1[i]->co) re1[p++]->init(a1[i]->co, a1[i]->exp);
            i++;

        }
        else if (i < n_ && j < m_ && (a1[i]->exp > b1[j]->exp))
        {
            if (b1[j]->co) re1[p++]->init(b1[j]->co, b1[j]->exp);
            j++;
        }
        else if (i < n_)
        {
            if (a1[i]->co) re1[p++]->init(a1[i]->co, a1[i]->exp);
            i++;
        }
        else if (j < m_)
        {
            if (b1[j]->co) re1[p++]->init(b1[j]->co, b1[j]->exp);
            j++;
        }
    }
    print(re1, p);

}
void subtract(node* a1[], node* b1[], int n_, int m_)
{
    int q = 0;
    //cout << "调用了subtract函数" << endl;
    for (int i = 0, j = 0; i < n_ || j < m_;)
    {
        if (i < n_ && j < m_ && a1[i]->exp == b1[j]->exp)
        {
            int t1 = a1[i]->co - b1[j]->co;
            if (t1)
                re2[q++]->init(t1, a1[i]->exp);
            i++, j++;
        }
        else if (i < n_ && j < m_ && a1[i]->exp < b1[j]->exp)
        {
            re2[q++]->init(a1[i]->co, a1[i]->exp);
            i++;

        }
        else if (i < n_ && j<m_ && a1[i]->exp>b1[j]->exp)
        {
            re2[q++]->init((-b1[j]->co), b1[j]->exp);
            j++;
        }
        else if (i < n_)
        {
            re2[q++]->init(a1[i]->co, a1[i]->exp);
            i++;
        }
        else if (j < m_)
        {
            re2[q++]->init((-b1[j]->co), b1[j]->exp);
            j++;

        }
    }
    print(re2, q);
}

void multiply(node* a1[], node* b1[], int n_, int m_)
{

    int p = 0;
    int t = 0; int t2 = 0;
    for (int i = 0; i < n_; i++)
    {
        for (int j = 0; j < m_; j++)
        {
            t = a1[i]->co * b1[j]->co;
            t2 = a1[i]->exp + b1[j]->exp;
            int flag = 0;
            if (t)
            {
                for (int l = 0; l < p; l++)
                {
                    if (re3[l]->exp == t2)
                    {
                        re3[l]->co += t;
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    re3[p++]->init(t, t2);
                }
                //  print(re3, p);
                  //cout << "输出此时re3的项数" << p << endl;
            }
            else continue;

        }
    }

    sort(re3, re3 + p, cmp);
    print(re3, p);
}
int main()

{
    int t;
    cin >> t;
    int n, m;
    newnode();
    while (t--)
    {
        int co, exp;
        //输入第一个多项式
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> co >> exp;
            a[j]->init(co, exp);//系数为0不放入
        }
       // cout << "输出第一个多项式" << endl;
        print(a, n);

        //输入第二个多项式
        cin >> m;
        for (int k = 0; k < m; k++)
        {
            cin >> co >> exp;
            b[k]->init(co, exp);
        }
       // cout << "输出第二个多项式" << endl;
        print(b, m);

        //加减乘操作
       // cout << "输出相加之后的结果" << endl;
        add(a, b, n, m);
       // cout << "输出相减之后的结果" << endl;
        subtract(a, b, n, m);
       // cout << "输出相乘之后的结果" << endl;
        multiply(a, b, n, m);

        //重新初始化d
        for (int k = 0; k < n; k++) a[k]->init();
        for (int j = 0; j < m; j++) b[j]->init();
        cout << endl;
    }

    return 0;
}