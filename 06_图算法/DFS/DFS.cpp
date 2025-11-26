#include<iostream>
using namespace std;
const int maxn = 50;//假定图最多包含50个顶点
int g[maxn][maxn];//图的邻接矩阵
int visit[maxn];//访问标志数组，标识每个结点是否已经访问过,1表示访问过，0表示未访问过
int vnum;//结点数量
void DFS(int now)//now表示当前结点
{
	cout << now << " ";
	visit[now] = 1;
	int* a = new int[vnum];//存放与当前结点相连（有边）的结点编号
	for (int i = 0; i < vnum; i++)
	{
		a[i] = -1;
	}
	int k = 0;
	for (int i = 0; i < vnum; i++)
	{
		if (g[now][i])//编号为i的结点与当前结点相连（有边）
		{
			a[k++] = i;//存放到数组里
		}
	}
	int i = 0;
	for (int w = a[i]; w != -1; w = a[++i])
	{
		if (!visit[w])
		{
			DFS(w);
		}
	}
	delete[]a;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> vnum;
		for (int i = 0; i < vnum; i++)
			visit[i] = 0;
		//输入邻接矩阵，1表示结点之间相连，0表示结点之间没有相连
		for (int i = 0; i < vnum; i++)
		{
			for (int j = 0; j < vnum; j++)
				cin >> g[i][j];
	     }
		for (int v = 0;v< vnum;v++)
		{
			if (!visit[v])
			{
				DFS(v);
			}

		}
		cout << endl;
	}



	return 0;
}