#include <iostream>
using namespace std;
//从0开始存储，那么第i个结点的左孩子就是2*i+1，右孩子就是2*i+2。
void tree(int i,int* q, int len)
{
    
    if (i < len && q[i] != 0)
    {
        cout << q[i] << " ";
       tree(2 * i + 1, q, len);
       tree(2 * i + 2, q, len);
    }
}
int main()
{
    int t;
    cin >> t;//t个二叉树
    while (t--)
    {
        int len;
        cin >> len;
        int* p = new int[len];
        for (int i = 0; i < len; i++)
        {
            cin >> p[i];
        }
        int i = 0;
        tree(i, p, len);
        cout << endl;
        delete[]p;
    }
    return 0;
}
