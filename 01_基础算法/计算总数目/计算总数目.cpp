#include <iostream>
#include<cstring>
using namespace std;
int main()
{
    
    char s[100];
    int flag = 1;
    while (cin >> s)
    {
        flag = 1;
        int len =strlen(s);
        if (len < 8)
        {
         cout << "NO" << endl;
        }
        else
        {
            int o = 0, p = 0, q = 0, z = 0;
            for (int i = 0; s[i] != '\0'; i++)
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    o = 1;
                }

                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    p = 1;
                }


                if (s[i] >= '0' && s[i] <= '9')
                {
                    q = 1;
                }


                if (s[i] == '~' || s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%' || s[i] == '^')
                {
                    z = 1; 
                }
            }
            if (o + p + q + z >= 3)flag = 1;
            else flag = 0;

            if (flag == 1)
                cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    } return 0;
}  
