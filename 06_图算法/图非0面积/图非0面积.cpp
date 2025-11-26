#include <iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
//面积："1"所围成的闭合曲线中"0"点的数目。
//假设一定有1组成的闭合曲线，但不唯一。
const int maxn = 110;
int dx[4] = { -1,1,0,0 };//上下左右
int dy[4] = { 0,0,-1,1 };//上下左右
int map[1000][1000];
class Map
{
public:

	int m, n;
	void setvalue()
	{
		cin >> m >> n;
		//外围再围一圈0，防止出现第一个是0，前后左右都堵死了；
		for (int i = 0; i < n; i++)
		{
			map[0][i] = 0;
			map[m + 1][i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			map[i][0] = 0;
			map[i][n + 1] = 0;
		}
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> map[i][j];
			}

		}
	}
	void BFS()
	{
		queue<int>qx, qy;
		int x = 0, y = 0;
		qx.push(x);
		qy.push(y);
		map[x][y] = 1;
		while (!qx.empty())
		{
			for (int i = 0; i < 4; i++)
			{
				if ((qx.front() + dx[i] >= 0) && (qx.front() + dx[i] <= m+1) && (qy.front() + dy[i] >= 0) && (qy.front() + dy[i] <= n+1) && (map[(qx.front() + dx[i])][(qy.front() + dy[i])] == 0))
				{
					qx.push(qx.front() + dx[i]);
					qy.push(qy.front() + dy[i]);
					map[(qx.front() + dx[i])][(qy.front() + dy[i])] = 1;
				}
			}
			qx.pop();
			qy.pop();
		}

	}
	void print()//打印数组看看对不对
	{
		cout << "变化后数组：" << endl;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{

				cout << map[i][j] << " ";

			}
			cout << endl;
		}
	}

	void  gets()//得到面积 ：  统计0数目
	{
		int s = 0;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!map[i][j])
					s++;
			}

		}
		cout << s << endl;
	}
};


int main()
{
	int t;
	cin >> t;
	while (t--)
	{

		Map ma;
		ma.setvalue();
		ma.BFS();
		//ma.print();
		ma.gets();



	}
	return 0;
}

