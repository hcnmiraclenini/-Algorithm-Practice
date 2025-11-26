#include <iostream>
#include<algorithm>
using namespace std;

class Node
{public:
    int a;
    int b;
    Node(int x_=0,int y_=0)
    {
        a = x_;
        b = y_;
    }
   void  print()
    {
        cout << a <<" "<< b << endl;
    }
   bool operator < (const Node &p)const
   {
       return a>p.a;
   }
};

Node* s[100000];
int main()
{
    int t;
    while (cin >> t)
    {
        for (int i = 0; i < t; i++)
        {
            int x, y;
            cin >> x >> y;
            s[i] = new Node(x, y);

        }
        sort(s, s + t);
        for (int j = 0; j < t; j++)
        {
           cout<< s[j]->a<<" "<<s[j]->b<<endl;
        }
    }
    return 0;
}
