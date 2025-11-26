#include <iostream>
#include<cstring>
using namespace std;
void print(string s, int i, int n)
{
    if (s[i] != '0')
        cout << s[i];
    if ((2 * i + 1) < n)
        print(s, 2 * i + 1, n);
    if ((2 * i + 2) < n)
        print(s, 2 * i + 2, n);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int len = s.size();
        print(s, 0, len);
        cout << endl;
    }
}

