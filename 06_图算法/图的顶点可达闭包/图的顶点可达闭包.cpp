#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int p[1000][1000];

bool vis[1000];
//可达闭包：
int r[1000][1000];
int fst[1000];
int nex[1000];
int u[1000], v[1000], w[1000];
int tp;

void addege(int  s, int e, int c)
{
    nex[tp] = fst[s];
    u[tp] = s;
    v[tp] = e;
    w[tp] = c;
    fst[s] = tp;
    tp++;
}
void Floyd(int n)
{
    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (p[i][k] && p[k][j])
                    p[i][j] = 1;
            }
        }
    }
}
int main()
{



    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j]; 
        }

    }
    Floyd(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n-1) cout << p[i][j] << endl;
            else cout << p[i][j] << " ";
        }
      
    }

    return 0;
}