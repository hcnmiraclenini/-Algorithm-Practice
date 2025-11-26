#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int maxm = 11000;
int mat[maxn][maxn];//邻接矩阵
//int a[maxm], b[maxm];//已有的边
int fst[maxn];// key[maxn];//某顶点发出的第一条边的编号
int nex[maxm], u[maxm], v[maxm], w[maxm];
int tp, m, n;
void AddEdge(int s, int e, int c)//添加边
{
	nex[tp] = fst[s];
	u[tp] = s;
	v[tp] = e;
	w[tp] = c;
	fst[s] = tp;
	tp++;
}

int p[maxn], idx[maxm];
int fa(int x)//并查集
{
	return p[x] = (p[x] == x ? x : fa(p[x]));
}
bool cmp(const int& a, const int& b)
{
	return w[a] < w[b];
}
int ret = 0, cnt = 0;
int Kruskal()
{
	
	for (int i = 0; i < n; i++)//初始化并查集
	{
		p[i] = i;//祖先是自己
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	//将已有的边祖先更新为同一祖先
	{
		int c, d;
		cin >> c >> d;
		p[c-1] = fa(d-1);
	
	}
	for (int i = 0; i < tp; i++)//tp为边数
	{
		idx[i] = i;//存下标
	}
	sort(idx, idx + tp, cmp);
	for (int i = 0; i < tp; i++)
	{
		int uu = u[idx[i]];//权重最小
		int vv = v[idx[i]];
		int ww = w[idx[i]];
		if (fa(uu) == fa(vv)) continue;
		p[fa(uu)] = fa(vv);
		ret += ww;
		cnt++;
		if (cnt == n-1 ) break;
	}
	return ret;
}

int main()
{
	while (cin >> n)
	{
		ret = 0, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				mat[i][j] = 0;
			}
		}
		//memset(a, -1, sizeof(a));
		//memset(b, -1, sizeof(b));
		memset(fst, -1, sizeof(fst));
		memset(p, -1, sizeof(p));
		memset(idx, -1, sizeof(idx));
		
		tp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> mat[i][j];
				if (mat[i][j])
				{
					AddEdge(i, j, mat[i][j]);
				}
			}
		}
		/*cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a[i] >> b[i];
		}*/
		//int res = Kruskal();
		cout <<  Kruskal() << endl;
	}
	return 0;
}