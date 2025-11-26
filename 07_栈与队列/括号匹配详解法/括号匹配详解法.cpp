#include <iostream>
#include<stack>//写上头文件
#include<cstring>
using namespace std;
int main()
{
    int t, len;
    cin >> t;
    string str;
    while (t--)
    {
        cin >> str;
        len = str.length();
        stack<char> s;//创建堆栈对象s
        int flag = 1;
        for (int i = 0; i < len; i++)
        {
            //收到左括号就进栈
            if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            {
                s.push(str[i]);
            }
            else if (str[i] == ']')
            {
                //匹配成功就将栈顶元素弹出
                if (!s.empty() && s.top() == '[')
                {
                    s.pop();
                }
                //匹配不成功，flag记为0
                else
                {
                    flag = 0;
                }
            }
            else if (str[i] == ')')
            {
                //匹配成功就将栈顶元素弹出
                if (!s.empty() && s.top() == '(')
                {
                    s.pop();
                }
                //匹配不成功，flag记为0
                else
                {
                    flag = 0;
                }

            }
            else if (str[i] == '}')
            {
                //匹配成功就将栈顶元素弹出
                if (!s.empty() && s.top() == '{')
                {
                    s.pop();
                }
                //匹配不成功，flag记为0
                else
                {
                    flag = 0;
                }
            }
        }
        //所有的输入的左括号都匹配成功，栈为空就输出"ok"
        if (s.empty() && flag == 1)
        {

            cout << "ok" << endl;


        }
        //否则输出"error"
        else
        {
            cout << "error" << endl;
        }
    }
    return 0;
}