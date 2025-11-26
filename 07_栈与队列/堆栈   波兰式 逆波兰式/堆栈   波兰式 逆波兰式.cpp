#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int getdigit(int a, int i)
{

}
int main()
{
    int t;
    cin >> t;
    string s;
 
    while (t--)
    {

       
        cin >> s;
        stack <char> pre;  //存取字符串的
        int f = 0;
        for (int i = 0; i < s.length(); i++) //顺序扫一遍
        {

            if (s[i] >= '0' && s[i] <= '9') //遇到数字
            {

                string num = "";
                num = num + str[i];
              //数字不止一位
                while (i - 1 >= 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
                {
                    num = s[--i] + num;
                }
                if (!f) f = 1;
                else cout << " ";
                cout << num;
                continue;
            }
            if (pre.empty()) //遇到字符 栈为空
            {
                pre.push(s[i]);
                continue;
            }
            if (s[i] == '+' || s[i] == '-') //遇到字符栈不为空,运算符是加号或者减号的情况
            {
                while (!pre.empty() && pre.top() != '(')
                {
                    if (!f) f = 1;
                    else cout << " ";
                    cout << pre.top();
                    pre.pop();
                }
                pre.push(s[i]);
                continue;
            }
            if (s[i] == '*' || s[i] == '/') //遇到字符栈不为空,运算符是乘号或者除号的情况
            {
                while (!pre.empty() && pre.top() != '(' && pre.top() != '+' && pre.top() != '-')
                {
                    if (!f) f = 1;
                    else cout << " ";
                    cout << pre.top();
                    pre.pop();
                }
                pre.push(s[i]);
                continue;
            }
            if (s[i] == '(') pre.push(s[i]); //遇到左括号直接进栈
            if (s[i] == ')') //遇到右括号把到左括号栈里还有的运算符全部输出
            {
                while (!pre.empty() && pre.top() != '(')
                {
                    if (!f) f = 1;
                    else cout << " ";
                    cout << pre.top();
                    pre.pop();
                }
                pre.pop();
            }
        }
        while (!pre.empty()) //字符串扫一遍了，栈里还有的东西也要弹掉
        {
            if (!f) f = 1;
            else cout << " ";
            cout << pre.top();
            pre.pop();
        }
        cout << endl;
     }
}