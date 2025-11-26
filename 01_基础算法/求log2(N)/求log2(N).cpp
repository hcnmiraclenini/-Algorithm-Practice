#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    long long n;
    while (cin >> n)
    {
        for (int i = 1; i < n; i++)
        {
            if ((pow(2, i) <= n) && (pow(2, i + 1) > n))
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}
