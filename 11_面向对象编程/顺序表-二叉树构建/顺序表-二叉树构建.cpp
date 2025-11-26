#include <iostream>
#include<string>
using namespace std;

class Node
{
public:
    char d;
    Node* left, * right;
    Node()
    {
        left = right = NULL;
        
    }
};
string str;
int pos;
void buildtree(Node *&now,char ch)
{
    
        if (ch == '#') now=NULL;
        else
        {
            Node* p = new Node();
            p->d = ch;
            now=p;
            buildtree(now->left, str[++pos]);
            buildtree(now->right, str[++pos]);
        }
}
void front(Node *now)
{
    if (now != NULL)
    {
        cout << now->d;
        front(now->left);
        front(now->right);
    }
}
void in(Node *now)
{
    if (now != NULL)
    {
        in(now->left);
        cout << now->d;
        in(now->right);
    }
}
void leter(Node *now)
{
    if (now != NULL)
    {
        leter(now->left);
        leter(now->right);
        cout << now->d;
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node* head = new Node();
        cin >> str;
        pos = 0;
        buildtree(head,str[pos]);
    
        front(head);
        cout << endl;
        in(head);
        cout << endl;
        leter(head);
        cout << endl;
    }
    return 0;
}
