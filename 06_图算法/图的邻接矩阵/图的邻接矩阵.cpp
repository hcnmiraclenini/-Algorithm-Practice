#include <iostream>
#include<cstring>
using namespace std;

//图的邻接矩阵存储及度计算
//并计算各顶点的入度、出度和度
//并输出图中的孤立点（度为0的顶点)

string v[1000];
int v_num;//点个数
int e_num;//边数
int biao[1000][1000];
int inp[1000];//inp[i]第i个点的入度
int outp[1000];
int p[1000];//用于无向图
class Node
{
public:
    int pos;//顶点在数组的位置下标
    Node* nex;//顶点在数组的位置下标

    Node(int p)
    {
        pos = p;  nex = NULL;
    }
    Node()
    {
        nex = NULL;
    }

};

class list
{
public:
    Node* head;
    char type;
    int getpos(string ch)
    {
        for (int i = 0; i < v_num; i++)
        {
            if (ch == v[i])
                return i;
        }
        return 0;
    }

    list(int a, string v_[], int b, char ty)//a点个数  b边个数
    {
        int i = 0;
        v_num = a;
        e_num = b;
        type = ty;
        head = new Node[v_num];
        for (int i = 0; i < v_num; i++)
        {
            v[i] = v_[i];
        }
        for (i = 0; i < e_num; i++)
        {
            string ch1, ch2;
            cin >> ch1 >> ch2;
            int a = this->getpos(ch1);
            Node* q = &head[a];
            while (q->nex)
                q = q->nex;
            Node* now = new Node;
            now->pos = getpos(ch2);
            q->nex = now;
            

        }
        //初始化邻接表
        for (int i = 0; i < v_num; i++)
        {
            for (int j = 0; j < v_num; j++)
            {
                biao[i][j] = 0;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < v_num; i++)
        {
            for (int j = 0; j < v_num; j++)
            {
                Node* q = head[i].nex;
                while (q)
                {
                    biao[i][q->pos] = 1;
                    q = q->nex;
                }

            }
        }
        for (int i = 0; i < v_num; i++)
        {
            for (int j = 0; j < v_num; j++)
            {
                cout << biao[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
        int i = 0;
        if(type=='D')
        { 
          for (i = 0; i < v_num; i++)
          {
             for (int j = 0; j < v_num; j++)
            {
                if (biao[i][j])
                {
                    outp[i]++;
                  
                    inp[j]++;
               
                }

            }
           }
          for (i = 0; i < v_num; i++)
          {
            if (outp[i] + inp[i])
                cout << v[i] << ": " << outp[i] << " " << inp[i] << " " << outp[i] + inp[i] << endl;
          }
          for (i = 0; i < v_num; i++)
          {
              int sum = outp[i] + inp[i];
              if (sum == 0)
              {
                  cout << v[i] << " ";
              }
          }
       }
         
            else  if(type =='U')
            {
            
                for (i = 0; i < v_num; i++)
                {
                    for (int j = 0; j < v_num; j++)
                    {
                        if (biao[i][j]&&biao[j][i])
                        {
                            p[i]++;
                            p[j]++;

                        }
                    }
                }
                for (i = 0; i < v_num; i++)
                {
                    if (p)
                        cout << v[i] << ": " << p << endl;
                }
          

              }
               
                if (p== 0)
                {
                    cout << v[i] << " ";
                }

            }

       
 
};

//给一个有向图，构建该图对应的邻接表

int main()
{
    int t, n, k;//t个图,n个顶点,k条弧
    cin >> t;
    char type;
   string v[10000];
    while (t--)
    {
        cin >> type;//图类型 （D—有向图，U—无向图）
        cin >> n;//顶点数
        for (int i = 0; i < n; i++)//顶点信息
        {
            cin >> v[i];
        }
        cin >> k;//边数
        list l(n, v, k, type);
        l.print();
       
    }
    return 0;
}
