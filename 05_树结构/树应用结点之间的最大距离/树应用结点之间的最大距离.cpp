#include <iostream>
using namespace std;
class node 
{
public:
    char data;//数据域
    node* l;
    node* r;
    int layer;//记录层数
    node()
    {
        l = r = NULL;
    }
    
};


node*  build()
{
    char ch;
    cin >> ch;
    if (ch == '#')
       return  NULL;
    else
    {
        node* p = new node;
        p->data = ch;
        p->l = build();
        p->r = build();
        return p;
    }
}/*
int height(node* q)
{
    if (q == 0)
        return 0;
    else
        return 1 + max(height(q->l), height(q->r));

}*/
int maxh = 0;
char ch;
char lch, rch;
int maxdis=0;
void  findmaxd(node* p,int h)
{
    if (p->l == NULL && p->r == NULL)
    {
        if (h > maxh)
        {
            maxh = h;
            ch = p->data;
        }
    }
    if (p->l)  findmaxd(p->l, h + 1);
    if (p->r)   findmaxd(p->r, h + 1);

}
void findch(node* p)
{
    if (p == NULL) return;
    int d = 0;
    char a = 'A';
    char b = 'A';
    if (p->l)
    {
        findmaxd(p->l, 1);
        a = ch;
    }
    d += maxh;
    maxh = 0;
    if (p->r)
    {
        findmaxd(p->r, 1);
         b= ch;
    }
    d += maxh;
    maxh = 0;
    if (d > maxdis)
    {
        maxdis = d;
        lch = a;
        rch = b;
    }
    findch(p->l);
    findch(p->r);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        maxh = 0;
       maxdis = 0;
        node* head ;
        head=build();
      //  cout << "最长距离" << endl;
        findch(head);
        if (maxdis)  cout << maxdis << ":" << lch << " " << rch << endl;
        else cout << "0:" << endl;
   
    }



    return 0;
}

