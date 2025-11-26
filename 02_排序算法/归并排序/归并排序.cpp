#include <iostream>
using namespace std;
int a[1100];
int mergetemp[100];
inline int min(int a, int b) { return a < b ? a : b; }
void mergesort(char a[], int n)
{
    for (int pace = 2; pace < 2 * n; pace = pace * 2)
    {
        for (int s = 0; s < n; s += pace)
        {
            int left = s, right = min(n, s + pace);
            int mid = left + (pace >> 1);
            int i, j, k;
            for (i = k = left, j = mid; i < mid && j < right;)
                mergetemp[k++] = a[i] <= a[j] ? a[i++] : a[j++];
            while (i < mid) mergetemp[k++] = a[i++];
            while (j < right) mergetemp[k++] = a[j++];
            memcpy(a + left, mergetemp + left, sizeof(a[0] * (right - left));
        }
    }
}

int main()
{
    std::cout << "Hello World!\n";
}
