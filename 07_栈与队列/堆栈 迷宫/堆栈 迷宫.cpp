#include <iostream>
#include<stack>
#include<cstring>
using namespace std;
stack<char> s;//堆栈对象s
class place
{
public:
    int xp, yp;
    place()
    {
        xp = 0;
        yp = 0;
    }
    place(int x, int y)
    {
        xp = x;
        yp = y;
    }
};
int main()
{
    int t, n;//迷宫的大小n   
    cin >> t;
    int a[100][100];
    stack <place> path;

    while (t--)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }

        }
        int i = 0, j = 0;
        if (a[0][0] == 1)
        {
            cout << "no path" << endl;

        }
        else
        {
            path.push({ 0,0 });
            a[0][0] = 1;//已经走过
            while (1)
            {

                if (j + 1 <= n - 1 && a[i][j + 1] == 0)
                {
                    a[i][j + 1] = 1;//已经走过
                    path.push({ i ,++j });

                }
                else if (i + 1 <= n - 1 && a[i + 1][j] == 0)
                {
                    a[i + 1][j] = 1;
                    path.push({ ++i,j });

                }
                else if (j - 1 >= 0 && a[i][j - 1] == 0)
                {
                    a[i][j - 1] = 1;
                    path.push({ i ,--j });

                }
                else if (i - 1 >= 0 && a[i - 1][j] == 0)
                {
                    a[i - 1][j] = 1;
                    path.push({ --i,j });

                }
                else
                {
                    i = path.top().xp;
                    j = path.top().yp;
                    if (!((j + 1 <= n - 1 && a[i][j + 1] == 0) || (i + 1 <= n - 1 && a[i + 1][j] == 0) || (j - 1 >= 0 && a[i][j - 1] == 0) || (i - 1 >= 0 && a[i - 1][j] == 0)))
                    {
                        path.pop();
                    }
                }
                if (path.empty() || (i == n - 1 && j == n - 1))
                {
                    break;
                }

            }


            i = 0;
            place cpos;
            if (!path.empty()) //找到路径
            { //实现path的数据导入path1
                stack<place>path1;
                while (!path.empty()) //找到路径
                {
                    path1.push(path.top());
                    path.pop();
                }

                //以下是输出路径的代码

                while (!path1.empty())

                {
                    cpos = path1.top();

                    if ((++i) % 4 == 0)

                        cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--" << endl;

                    else

                        cout << '[' << cpos.xp << ',' << cpos.yp << ']' << "--";

                    path1.pop();

                }

                cout << "END" << endl;

            }
            else
            {
                cout << "no path" << endl; //找不到路径输出no path
            }
        }
    }

    return 0;

}