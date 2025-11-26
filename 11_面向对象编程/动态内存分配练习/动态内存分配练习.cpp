#include<iostream>
using namespace std;
int main()
{
    int t, i, j, n;
    cin >> t;
    char a;


    for (i = 1; i <= t; i++)
    {
        cin >> a;
        cin >> n;
        if (a == 'I')
        {
            int* p;
            int sum = 0, average = 0;
            p = new int[n];
            for (j = 0; j < n; j++)
            {
                cin >> p[j];
                sum = sum + *(p + j);

            }
            average = sum / n;
            cout << average << endl;

            delete[]p;
        }
        else if (a == 'C')
        {

            char* p = new char[n];
            for (j = 0; j < n; j++)
            {
                cin >> *(p + j);
            }

            char max = *p;
            for (j = 1; j < n; j++)
            {

                if (*(p + j) > max)
                {
                    max = *(p + j);
                }
            }
            cout << max << endl;
            delete[]p;
        }
        else if (a == 'F')
        {
            float* p;

            p = new float[n];
            for (j = 0; j < n; j++)
            {
                cin >> *(p + j);
            }
            float min = *p;
            for (j = 1; j < n; j++)
            {
                if (*(p + j) < min)
                {
                    min = *(p + j);
                }

            }
            cout << min << endl;
            delete[]p;
        }

    }
}