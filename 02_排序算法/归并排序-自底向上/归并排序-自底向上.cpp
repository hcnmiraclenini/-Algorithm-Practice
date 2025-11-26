#include <iostream>
#include<cstring>
using namespace std;

//用2 - 路归并排序按字典顺序进行降序排序。
string str[10000];
string mergetemp[11000];
inline int Min(int a, int b)
{
    return a < b ? a : b;
}
void MergeSort(string a[], int n)
{
    for (int pace = 2; pace >> 1 < n; pace <<= 1)
    {
        for (int s = 0; s < n; s += pace)
        {
            int left = s, right = Min(n, s + pace);
            int mid = left + (pace >> 1);
            int i, j, k;
            for (i = k = left, j = mid; i < mid && j < right;)
                mergetemp[k++] = a[i] >= a[j] ? a[i++] : a[j++];
            while (i < mid) mergetemp[k++] = a[i++];
            while (j < right) mergetemp[k++] = a[j++];
            int le = sizeof(a[0]) * (right - left);
            for (int i = left; i <right; i++)
            {
                a[i] = mergetemp[i];
             }
            
          
        }
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1) cout << mergetemp[i] << endl;
            else cout << mergetemp[i] << " ";


        }
    }

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        MergeSort(str, n);
        cout << endl;
    }
    return 0;
}
