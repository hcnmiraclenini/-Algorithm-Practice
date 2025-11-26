#include <iostream>
#include<cstring>
#include<queue>
using namespace std;
#define max 1000000
//输入顶点v，用迪杰斯特拉算法求顶点v到其它顶点的最短路径
string v[100];//顶点信息
int m[100][100];//邻接矩阵
int fix[100];//是否能到达
int dis[100];//路径长度
int result = 0;
void dijkstra(int n)
{
    int i, j;
    
    for (int i = 0; i < n; i++)  //初始化,是起点到所有点的距离
    {
        dis[i] = m[n][i];
        fix[i] = 0;
    }
   
       fix[n] = 1;
   

    int mindisnode, mindis;

    for (i = 0; i < n; i++)
    {
        mindisnode = -1;
        mindis = max;
        for (j = 0; j < n; j++)
        {
            if (!fix[j] && dis[j] < mindis)
            {
                mindis = dis[j];
                mindisnode = j;

            }

        }
        if (mindisnode != -1)
        {
            fix[mindisnode] = 1;

            for (j = 0; j < n; j++)
            {
                if (!fix[j] && m[mindisnode][j] < dis[j]) //不用加上dis[mindisnode],因为在之间建了条道路相当于距离变为0
                {
                    dis[j] = m[mindisnode][j];
                }
            }
        }
    }
    //输出
    for (i = 0; i < n; i++)
    {
        result += dis[i];

    }
    cout <<result << endl;
    
    

}

int main()
{
    
    int n, i, j;
    while (cin >> n)
    {
        result = 0;
        for (i = 0; i < n; i++)
        {
            v[i] = i;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                m[i][j] = 0;
            }
        }

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> m[i][j];

            }
        }
        int t, a, b;
        cin >> t;
        while (t--)  //从0 到 n - 1
        {
            cin >> a >> b;
            m[a - 1][b - 1] = 0;
            m[b - 1][a - 1] = 0;
        }
       
        dijkstra(n - 1); //要n - 1
    }

}