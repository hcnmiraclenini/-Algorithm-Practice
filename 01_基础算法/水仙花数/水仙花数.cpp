#include <iostream>
#include<queue>
using namespace std;
int main()
{
    int m, n;
    queue<int>q;
    while (cin >> m >> n)
    {
        int flag = 0;
        for (int i= m; i <= n; i++)
        {
           int a = i / 100;
            int b = i % 100 / 10;
            int c = i % 10;
            if (i == a * a * a + b * b * b + c * c * c)
            {
                q.push(i);
                flag = 1;
            }
        }
        if (!flag)  cout << "no" << endl;
        else
        {
           cout<< q.front();
            q.pop();
            while (!q.empty())
            {
                cout << " " << q.front();
                q.pop();
            }
            cout << endl;
        }     
    }
    return 0;
}

