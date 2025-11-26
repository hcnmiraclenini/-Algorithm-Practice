#include <iostream>
using namespace std;
class node
{
public:
    char data;
    node* l;
    node* r;
    node()
    {
        l = r = NULL;
    }
    ~node()
    {
        delete l; delete r;
    }
};
int lmax = 0;
int rmax = 0;
node* buildtree(node *root)
{
    char a;
    cin >> a;
    node* p;
    if (a == '#') return NULL;
    else
    {
        p = new node;
        p->data = a;
        root = p;
        buildtree(root->l);
        buildtree(root->r);
        return;
    }
}
int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        node* root = NULL;
        buildtree(root);
    }



    return 0;
}

