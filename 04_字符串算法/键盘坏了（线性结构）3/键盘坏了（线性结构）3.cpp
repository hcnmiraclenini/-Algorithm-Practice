#include <iostream>
#include<stack>
#include<list>
using namespace std;
char ch[100002];
int main()
{
    while (cin >>ch)
    {
        string result = "";
        string result2 = "";
        int len = strlen(ch);
        for (int i = len - 1; i >= 0; i--)
        {
            if (ch[i] == '[')//home
            {
              //  cout << (ch + i + 1) << endl;
                result = result + (ch+i+1);
                ch[i] = '\0';//切断
              //  cout << "此时的字符串1" << endl;
             //   cout << result << endl;
            }
           
            else if (ch[i] == ']')
            {
                result2 = (ch + i + 1) + result2;
                ch[i] = '\0';
               // cout << "此时的字符串2" << endl;
               // cout << result2 << endl;
            }
            else if(i==0)
            {
                result = result +ch;
             //   cout << "此时的字符串3" << endl;
             //   cout << result << endl;
            }
         

        } 
       cout << result << result2 << endl;

    }
    return 0;
}