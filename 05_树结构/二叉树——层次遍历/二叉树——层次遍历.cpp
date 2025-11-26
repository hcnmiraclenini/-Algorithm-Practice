#include <iostream>
#include<queue>

using namespace std;
class Node
{
public:
    char data;
    Node* l, *r;
   
    Node() { data='0',r = l = NULL; };
};
string mod1;
string mod2;
class tree
{
public:
    Node* head;
    int i = -1;
    void pre(Node* &h)
    {
             i++;
             int len = mod2.size();
             if (i < len)
             {
                 if (mod2[i] == '#')
                 {
                     Node* t = new Node;
                     t->data = '#';
                     h = t;
                     h->l = NULL;
                     h->r = NULL;
                 }
                 else
                 {
                     Node* t = new Node;
                     t->data = mod2[i];
                     h = t;
                     pre(h->l);
                     pre(h->r);
                 }
             }
   }
  int  LevelOrder(Node* h)
    {
        Node* p;
        queue<Node*>q;
        q.push(h);
        int len = mod1.size();
        for(int i=0;i<len;i++)
        {
            p = q.front();
            q.pop();
            if(p!=NULL)
            {
                if (p->data != mod1[i])
                {
                    cout << "NO" << endl;
                    return 0;
                }
                q.push(p->l);
               q.push(p->r);
               
            }
        }
        cout << "YES" << endl;
        return 1;
    }
  
   

};


/*void build(Node*& p)
{
    char a;
    cin >> a;
    if (a == '#') p = NULL;
    else
    {
        Node* q = new Node;
        q->data = a;
        p = q;
        build(p->l);
        build(p->r);
    }
}
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> mod1 >> mod2;
        tree tr;
        Node* head = NULL;
        tr.pre(head);
        tr.LevelOrder(head);
    }


    return 0;
}

