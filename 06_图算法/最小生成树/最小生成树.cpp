#include <iostream>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 1e3+ 10;
const int maxm = 1e3 + 10;
int fst[maxn], nex[maxm];
int key[maxn];
int tp = 0;
int g[maxn][maxn];
bool vis[maxn];
typedef pair<int, pair<int, int> > pii;
int p[110];
struct node {
    int u, v, w;
}idx[1005];
int n, m, Q;
string str[100];
void addedge(int s, int e, int c) //邻接矩阵存图，还有单独存边。
{
    g[s][e] = c;
    g[e][s] = c;
    idx[tp].u = s, idx[tp].v = e, idx[tp++].w = c;
}
bool cmp(node a, node b)
{
    return a.w < b.w;
}
int fa(int  x)
{
    return p[x] = (p[x] == x ? x : fa(p[x]));
}
// kruskal 是得对边进行排序，所以你应该搞一个存边的结构体
// 前面那个结构体node，一开始的代码没有存边即对边长排序。
void Kruskal(int start)
{
    int ret = 0, cnt = 0;
    for (int i = 0; i < n; i++)
        p[i] = i;
    sort(idx, idx + tp, cmp); //排序
    for (int i = 0; i < tp; i++)
    {
        int uu = idx[i].u, vv = idx[i].v, ww = idx[i].w; //uu起点, vv终点
        if (fa(uu) == fa(vv))  continue;                 //ww权值
        p[fa(uu)] = fa(vv);
        //如果不在一个集合里就直接输出，并且合并到一个集合
        //这里要取min和max是因为题目要求要升序。
        cout << str[min(uu, vv)] << " " << str[max(uu, vv)] << " " << ww << endl;
        cnt++;
        if (cnt == n - 1) break;
    }
}
//想要能先输出总价值，就加个k标记，如果k = 0就输出总价值，不输出边
//k = 1,就输出边不输出价值。
void prim(int sta, int k)
{
    memset(key, 0x3f, sizeof(key));
    memset(vis, 0, sizeof(vis));
    key[sta] = 0;
    //sta不能先标记，不然下面没办法跑
    priority_queue<pii, vector<pii>, greater<pii>>q; //pii进行了一个修改，还记录了父亲
    q.push(pii(0, { 0, sta }));  //first是权值， second.first 是父亲， second.second是要到的点
    int res = 0;
    while (!q.empty())
    {
        pii now = q.top(); q.pop();
        if (key[now.second.second] != now.first)continue;
        int uu = now.second.second;
        int vv = now.second.first;
        int len = now.first;
        if (vis[uu]) continue; //这一步是防止重复，一开始没加
        if (uu != sta && k == 1)
            cout << str[vv] << " " << str[uu] << " " << len << endl;
        res += len;
        vis[uu] = true;
        for (int v = 0; v < n; v++)
        {
            if (g[uu][v] && g[uu][v] < key[v] && !vis[v])
            {

                key[v] = g[uu][v];
                q.push({ key[v], {uu, v} });
            }
        }
    }
    if (k == 0) cout << res << endl;
}
int main()
{
    cin >> n;//顶点数n
    for (int i = 0; i < n; i++)//n个顶点
    {
        cin >> str[i];
    }
    string v1, v2, start;
    int  m, weight;
    cin >> m;
    int a, b;
    for (int i = 0; i < m; i++)
    {

        cin >> v1 >> v2 >> weight;
        for (int k = 0; k < n; k++)
        {
            if (v1 == str[k]) a = k;
        }
        for (int p = 0; p < n; p++)
        {
            if (v2 == str[p]) b = p;
        }
        addedge(a, b, weight);//传入两个字符串下标和权值
    }
    cin >> start;
    int st = 0;
    for (int k = 0; k < n; k++)
    {
        if (start == str[k]) st = k;
    }
    prim(st, 0);
    cout << "prim:" << endl;
    prim(st, 1);
    cout << "kruskal:" << endl;
    Kruskal(st);
    return 0;
}