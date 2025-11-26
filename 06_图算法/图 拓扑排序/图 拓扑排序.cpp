#include <iostream>
using namespace std;
int m[1000][1000];
//int visit[1000];
int in[1000];
int u[1000], v[1000], w[1000],nex[1000],fst[1000];
int tp;

void addEdge(int s, int e, int c)
{
    nex[tp] = fst[s];
    u[tp] = s;
    v[tp] = e;
    w[tp] = c;
    fst[s] = tp;
    tp++;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 1000; i++)
        {
            fst[i] = -1;
            in[i] = 0;
       }
        int n;//顶点从0开始编号
        tp = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
                if (m[i][j]) 
                {
                    addEdge(i, j, 1);
                    in[j]++;
                }
            }
        }
   
        for (int i = 0; i < n; i++)
        {
            int j;
          for (j = 0; j <n&&in[j]; j++);
            cout << j<<" ";
            in[j] = -1;
            for (int k = fst[j]; k != -1; k = nex[k])
            {
                in[v[k]]--;
            }
        }
        cout << endl;


    }
    return 0;
}

