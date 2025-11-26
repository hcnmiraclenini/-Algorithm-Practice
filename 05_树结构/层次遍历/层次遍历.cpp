#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
typedef std::pair<int, int> pii;
const int maxn = 110;
int g[maxn][maxn], key[maxn];
bool vis[maxn];
int n;

int Prim()
{
    int start = 0;
    memset(key, 0x3f, sizeof(key));
    memset(vis, 0, sizeof(vis));
    key[start] = 0;
    vis[start] = true;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii> >q;
    q.push(pii(0, start));
    int res = 0;
    while (!q.empty())
    {
        pii now = q.top(); q.pop();
        if (key[now.second] != now.first)
            continue;
        int uu = now.second;
        int len = now.first;
        res += len;
        vis[uu] = true;
        for (int v = 0; v < n; v++)
        {
            if (g[uu][v] && g[uu][v] < key[v] && !vis[v])
            {
                key[v] = g[uu][v];
                q.push(pii(key[v], v));
            }
        }
    }
    return res;
}
int main()
{
    int a, b, c;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &g[i][j]);
        printf("%d\n", Prim());
    }
    return 0;
}