#include<iostream>
#include<queue>
using namespace std;

const int Maxlen = 20;
//给出一个图的邻接矩阵，对图进行深度优先搜索，从顶点0开始
//注意：图n个顶点编号从0到n - 1
class Map
{
private:
    bool Visit[Maxlen];//标志节点是否被访问过
    int Matrix[Maxlen][Maxlen];//邻接矩阵
    int Vexnum;//顶点数量
    void BFS(int v);
public:
    void SetMatrix(int vnum, int mx[Maxlen][Maxlen]);
    void BFSTraverse();
};
void Map::SetMatrix(int vnum, int mx[Maxlen][Maxlen])
{
    int i, j;
    Vexnum = vnum;
    for (i = 0; i < Maxlen; i++)
    {
        Visit[i] = 0;

    }
    for (i = 0; i < Vexnum; i++)
    {
        for (j = 0; j < Vexnum; j++)
        {
            Matrix[i][j] = mx[i][j];
        }
    }
}
void Map::BFSTraverse()
{
    BFS(0);
}
void Map::BFS(int v)
{
    int w, u, i;
    int* AdjVex = new int[Maxlen];
    queue<int>Q;
    int k = 0;
    for (i = 0; i < Vexnum; i++)
    {
        Visit[i] = false;
    }
    for (int i = 0; i < Maxlen; i++)
    {
        AdjVex[i] = -1;
    }
    for (v = 0; v < Vexnum; ++v)
    {
        if (!Visit[v])
        {

            //cout << v << " ";
            Visit[v] = true;
            Q.push(v);
            while (!Q.empty())
            {
                k = 0;
                u = Q.front();
                cout << u << " ";
                Q.pop();
                for (int j = 0; j < Vexnum; j++)
                {

                    if (Matrix[u][j])
                    {
                        AdjVex[k++] = j;
                    }
                }
                i = 0;
                w = AdjVex[i];
                while (w >= 0)
                {
                    if (Visit[w] == false)
                    {
                        Visit[w] = true;
                        Q.push(w);
                    }
                    w = AdjVex[++i];
                }

            }
        }
    }
    cout << endl;
}
int main()
{
    int t, n;
    cin >> t;
    int m[20][20];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Map map;

        map.SetMatrix(n, m);
        map.BFSTraverse();
    }
}