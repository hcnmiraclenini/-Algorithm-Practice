#include <iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

//const int maxm = 2e4 + 10;
class Map
{
private:
    int Visit[100];//标志节点是否被访问过
    double g[100][100];//邻接矩阵
    string money[100];
    int n;//顶点数量
    double result;
    void DFS(int v);//深度优先
    int flag=0;//看看可以兑换不
    int count = 0;
    int l[100];
public:
    void SetMatrix();
    void DFSTraverse();//公有函数
    void print();
 
};
void Map::SetMatrix()
{
    int m ;
    
    int temp1 = 0, temp2 = 0;
    int i, j;
    cin >>n >> m;//n种货币和m种不同的货币兑换率。
   
    for (i = 0; i < n; i++)
    {
        Visit[i] = 0;
        l[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        cin >> money[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            g[i][j] = 0;
        }
    }
    while (m--)
    {
        double ex;//汇率exchange
        string a, b;
        cin >> a >> ex >> b;
        for (j = 0; j < n; j++)
        {
              if (a == money[j])  
                {  
                    temp1 = j;
                    break;
                 }
        }
        for (int k = 0; k <n; k++)
        {
            if (b == money[k])
            {
                temp2 = k;
                break;
            }
        }
       g[temp1][temp2] = ex;
    }
}
void Map::DFSTraverse()
{
    int i, j, k;
    for ( i = 0; i < n; i++)
    {
        count = 0;
        DFS(i);
        for (j = 0; j < count; j++)
        {
            if (g[l[j]][i])
            {
                result = 1.00;
                for (k = 0; k < j; k++)
                {
                    result *= g[l[k]][l[k + 1]];
                }
                result *= g[l[k]][l[0]];
                if (result > 1.0)
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                }
            }

        }
      
    }
    
    
}
//深度优先搜索
void Map::DFS(int v)//从第v个顶点出发递归地深度优先遍历图G
{
   
    if (Visit[v])  return;
    Visit[v] = 1;
    l[count++] = v;//走过的点
    for (int i = 0; i < n; i++)
    {
        if (g[v][i]&&!Visit[i])
        {
             //result *= g[v][i];
                DFS(i);
            
        }
    }
            
}


void Map::print()
{
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << g[i][j] << "  ";
        }
        cout << endl;
    }*/
    if (flag ==1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
  // cout << result << "!!" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Map map;
        map.SetMatrix();
        map.DFSTraverse();
        map.print();
    }
    return 0;
}
