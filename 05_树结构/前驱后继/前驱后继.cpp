#include <iostream>
#include<list>
using namespace std;
int n, m;
int main()
{
   
    cin >> n >> m;
    int num;
    list<int>l;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        l.push_back(num);
    }
    
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        if (num == l.back())
         {
            list<int>t = l;
             t.pop_back();
            
             cout << t.back() << endl;
          }
        else if (num == l.front())
            {
                list<int>t = l;
                t.pop_front();
                cout << t.front() << endl;
            }
        else
        {
            list<int>::iterator it;
            for (it = l.begin(); it != l.end(); it++)
            {
                if (*it == num)
                {
                    cout << *it - 1 << " " << *it + 1 << endl;

                }

            }
        }
    }
    return 0;
}
