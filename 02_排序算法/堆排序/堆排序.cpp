#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class f
{
public:
    int key;
    int num;
    int pos;
    f(int k,int n, int p)
    {
        k = key, num = n, pos = p;
    }
    f()
    {
        key = 0, num = 0, pos = 0;
    }

};
bool rule(f f1, f f2)
{
    //按第一个关键值从小到大排序后输出，要求第一关键值相同情况下不改变原数组次序
    if (f1.key == f2.key)
        return f1.pos < f2.pos;
    else
        return f1.key < f2.key;
}
f  a[1000000];
int main()
{
   
        int n;
        while (cin >> n)
        {
            int number, cnt;
            for (int i = 1; i <= n; i++)
            {
                cin >> cnt >> number;
                a[i].key = cnt;
                a[i].num = number;
                a[i].pos = i;
            }
            sort(a+1, a + n+1, rule);
            for (int i = 1; i <= n; i++)
            {
                cout << a[i].key << " " << a[i].num << endl;
            }

        }
       
    return 0;
}