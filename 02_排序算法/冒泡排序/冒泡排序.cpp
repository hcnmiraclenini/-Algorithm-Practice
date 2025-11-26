#include <iostream>
using namespace std;

int a[5000];
int main()
{
       int n;
       while( cin >> n)
       {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++)
        {
            for(int j = i + 1; j <=n; j++)
            {
                if (a[i] > a[j])
                {
                    swap(a[i], a[j]);
                    count++;
                }
            }
        }
        cout <<count << endl;
    }




    return 0;
}
