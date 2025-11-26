#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int classify(int o)
{
   
        if (o == '*' || o == '/')
        {
            return 2;
        }
        if (o == '+' || o == '-')
        {
            return 3;
        }
        if (o == '(' || o == ')')
            return 1;
        return 0;
  
}
bool polandop(char op1, char op2)
{
    if (op1 == '+' || op1 == '-') return op2 == '+' || op2 == '-';
    return true;
}

bool antipolandop(char op1, char op2)
{
    if (op1 == '*' || op1 == '/') return op2 != '*' || op2 != '/';
    return false;
}

 int main()
    {
            int t;
            cin >> t;
            while (t--)
            {
                stack <char> pre;  //存取字符串的 (逆波兰式）
                string s;
                stack<string> nums;
                stack<char> op;
                cin >> s;

                int f = 0;
                /*求波兰式*/
                int len = s.size();
                /*逆序遍历字符串*/
                for (int i = len - 1; i >= 0; i--)
                {
                    //判断数字
                    if (s[i] >= '0' && s[i] <= '9')
                    {
                        string num = "";
                        num = num + s[i];

                        //数字不止一位
                        while (i - 1 >= 0 && s[i - 1] >= '0' && s[i - 1] <= '9')
                        {
                            num = s[--i] + num;
                        }

                        nums.push(num);
                    }
                    else if (op.empty() || s[i] == ')' || op.top() == ')')
                    {
                        op.push(s[i]);
                    }
                    else if (s[i] == '(')
                    {
                        while (!op.empty() && op.top() != ')')
                        {
                            string ops = "";
                            ops += op.top();
                            nums.push(ops);
                            op.pop();
                        }
                        op.pop();
                    }
                    else if (polandop(s[i], op.top()))
                    {
                        op.push(s[i]);
                    }
                    else
                    {
                        /*操作符转入数字栈*/
                        while (!op.empty() && !polandop(s[i], op.top()))
                        {
                            string ops = "";
                            ops += op.top();
                            nums.push(ops);
                            op.pop();
                        }
                        op.push(s[i]);
                    }
                }

                while (!op.empty())
                {
                    string ops = "";
                    ops += op.top();
                    nums.push(ops);
                    op.pop();
                }

                string a = "";
                while (!nums.empty())
                {
                    if (nums.size() > 1)
                    {
                        a = a + nums.top() + " ";
                    }
                    else
                    {
                        a = a + nums.top();
                    }
                    nums.pop();
                }
                cout << a << endl;

                
                    //遇到（括号就把pre里面的都附近符号栈直到遇到）括号
                    //最后顺序扫完了就把pre里面剩下的全部放入符号栈
                    //    然后按相对顺序输出就好了
       
        /*逆波兰式*/
        for (int i = 0; i < s.length(); i++) //顺序扫一遍
        {

            if (s[i] >= '0' && s[i] <= '9') //遇到数字
            {

                string num = "";
                num = num + s[i];
                //数字不止一位
                while (i +1 >= 0 && s[i + 1] >= '0' && s[i+ 1] <= '9')
                {
                    num =  num + s[++i] ;
                  
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
        cout << endl;
    }
}