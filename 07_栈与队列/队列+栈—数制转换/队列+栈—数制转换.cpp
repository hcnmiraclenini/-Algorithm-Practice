#include <iostream>
#include<stack>
#include<queue>
#include<iomanip>
using namespace std;
//整数用堆栈，小数部分用队列
char fn[18] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int main()
{
    int t;
    cin >> t;
    int a;
    double  b;
    stack<char>s;
    queue<char>q;
    while (t--)
    {
        int k;
        double n;
        cin >> n >> k;//n要转换的数值 ，k进制
        a = n;//取出整数部分
        b = n - a;//取出小数部分
        //cout << "小数部分：" << b << endl;
        int i;
        while (a / k != 0)
        {
           i = a % k;
            //cout <<"i"<< i << endl;
            s.push(fn[i]);
            a = a / k;
        }
        i = a % k;
        s. push(fn[i]);
        //小数
        for (int j = 0; j < 3; j++)
        {
            b = b * k;
            i = (int)b;
            q.push(fn[i]);
            if (b * k >= 1)
               b = b  - (int)b ;
        }
        while (!s.empty())
        {
            char ch = s.top();
            cout << ch;
            s.pop();
        }
        cout << ".";
        while (!q.empty())
        {
            char ch = q.front();
            cout << ch;
            q.pop();
        }
        
        cout << endl;
    }
    return 0;
}
