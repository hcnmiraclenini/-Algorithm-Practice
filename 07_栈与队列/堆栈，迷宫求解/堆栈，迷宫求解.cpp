#include<stack>
#include <iostream>
using namespace std;

class Node
{
public:
	int x; int y;
	Node() {};
	Node(int x_, int y_) 
	{
		x = x_, y = y_;
	}
};
int  a[1000][1000];
int x[4] = {1,0,-1,0};
int y[4] = {0,1,0,-1};
int main()
{
	int t;
	cin >> t;
	stack<Node>path;
	stack<Node>path1;

	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
			}
		}
		//0可通过  1不可通过
		if (a[0][0] == 1)
		{
			cout << "no path" << endl;
		}
		else
		{

			path.push(Node(0, 0));
			int nowx = 0, nowy = 0;
			while (nowx != n - 1 && nowy != n - 1)
			{
				int flag = 0;
				for (int i = 0; i < 4; i++)
				{
					if ((nowx + x[i] >= 0) && (nowx + x[i] < n) && (nowy + y[i] >= 0) && (nowy + y[i] < n) && (a[x[i]][y[i]] == 0))
					{
						path.push(Node(x[i], y[i]));
						nowx += x[i];
						nowy += y[i];
						a[x[i]][y[i]] = 1;
						flag = 1;
					} 

				}
				if (flag == 0)break;
			}
			if (!path.empty())
			{
				while (!path.empty())
				{
					Node* temp = new Node;
					temp->x = path.top().x;
					temp->y = path.top().y;
					path1.push(*temp);
				}
				int i = 0;
				while (!path1.empty())
				{
					Node t = path1.top();
					if ((++i) % 4 == 0)
						cout << "[" << t.x <<","<<t.y<< "]" << "--" << endl;
					else
						cout << "[" << t.x << "," << t.y << "]" << "--";
					path1.pop();

				}
				cout << "END" << endl;

			}
			else cout << "no path" << endl;
		}
	}
	return 0;
}

 