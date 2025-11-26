#include<iostream>
#include<queue>
using namespace std;
const int maxn = 50;
int g[maxn][maxn];
int visit[maxn];
int vnum;

void BFS(int start)
{
	int* a = new int[vnum];//存放与顶点start相连的其他顶点编号
	queue<int>q;
	q.push(start);
	visit[start] = true;
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < vnum;i++)
		{
			if (!visit[i] && g[now][i])
			{
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		//输入结点数量
		cin >> vnum;
		//访问标志数组的值全设为0
		for (int i = 0; i < vnum; i++)
		{
			visit[i] = 0;
		}
		//输入邻接矩阵
		for (int i = 0; i < vnum; i++)
		{
			for (int j = 0; j < vnum; j++)
			{
				cin >> g[i][j];
			}
		}
	}


	return 0;
}