#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node* nex;
    Node(int k) { key = k; nex = NULL; }
    Node() { key = -1; nex = NULL; }
};
Node* nd[10000];
void Hash(int key, int m)
{
    int temp = key % 11;
    while (nd[temp] != 0)
    {
        temp = (temp + 1) % m;
    }
    Node* p = new Node;
    p->key = key;
    p->nex = nd[temp];
    nd[temp] = p;
}

int main()
{
    int n, m;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;//哈希表长m、关键字个数n
        for (int i = 0; i < m; i++)
        {
            nd[i] = NULL;
        }
        int key;
        for (int i = 0; i < n; i++)
        {
            cin >> key;
            Hash(key, m);
        }

        if (nd[0])
        {
            cout << nd[0]->key;
        }
        else
        {
            cout << "NULL";
        }
        for (int i = 1; i < m; i++)
        {
            if (nd[i])
            {
                cout << " " << nd[i]->key;
            }
            else
            {
                cout << " " << "NULL";
            }
        }
        cout << endl;
        int result[100];
        for (int i = 0; i < m; i++)
        {
            if (nd[i])
                result[i] = nd[i]->key;
            else
                result[i] = 0;
        }
        /*  for (int i = 0; i < m; i++)
          {
              cout << result[i]<<" ";
          }
          cout << endl;*/
        int k;
        cin >> k;
        while (k--)
        {
            cin >> key;
            int flag = 0;
            int cnt = 0;
            int t = key % 11;
            for (int i = 0; i < m; i++)//遍历次数为哈希表长度
            {
                cnt++;
                if (result[t] == key)//找到
                {
                    flag = 1;
                    break;

                }
                else if (result[t] == 0)//找不到
                {
                    break;
                }
                else
                {
                    t = (t + 1) % m;
                }
            }

            if (flag == 1)
            {
                cout << 1 << " " << cnt << " " << t + 1 << endl;;
            }
            else
            {
                cout << 0 << " " << cnt << endl;
            }

        }
    }

    return 0;
}