#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<long long >v;
    int n, k;
    cin >> n >> k;
    long long  a, b;
    long long  sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        sum += a;
        long long  t = a - b;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < k; i++)
    {
        sum -= v[i];
    }
    cout << sum << endl;
    return 0;
}

