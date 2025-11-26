#include <iostream>
#include<set>
using namespace std;
int main()
{
    set<int> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int nu;
        cin >> nu;
        s.insert(nu);
    }
    s.find(2);
  
}
