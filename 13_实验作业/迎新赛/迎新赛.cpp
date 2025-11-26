#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    for (int i = 0; i <= 123456789; i++)
    {
        int t = i, a = 10;
        int flag = 1;
        while (t)
        {
            int b = t % 10;
            if (b >= a)
            {
                flag = 0;
                break;
            }
            a = b;
            t = t / 10;
        }
        if (flag)   v.push_back(i);
   }
    int k;
    cin >> k;
    int size = v.size();
    //cout << size << endl;
    cout << v[size - k]<<endl;
    return 0;
}
