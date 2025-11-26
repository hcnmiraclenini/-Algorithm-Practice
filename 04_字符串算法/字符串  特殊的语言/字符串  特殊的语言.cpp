#include <iostream>
#include<cstring>
using namespace std;
int nex[100000];
void buildnex(string  m)
{
    nex[0] = -1;
    for (int i = 0, j = -1; m[i];)
    {
        if (j == -1 || m[j] == m[i])
        {
            nex[++i] = ++j;
        }
        else j = nex[j];
    }

}
int cnt = 0;
void kmp(string s, string m)//s长串  m短串
{
    cnt = 0;
    int len = m.size();
    for (int i = 0, j = 0; s[i];)
    {
        if (j == -1 || s[i] == m[j])
        {
            if (j == len - 1 && ((i-len+1) % 2 == 0))
            {
                cnt++;
                j = nex[j];
            }
            else i++, j++;
        }
        else j = nex[j];
    }
    
}
int main()
{
    string s, ms;
    while (cin >> s >> ms)
    {
        buildnex(ms);
        kmp(s, ms);
         cout << cnt << endl;
      

    }
    return 0;
}

