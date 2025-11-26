#include<iostream>
using namespace std;



char ch[1000];
inline int HeightDiff(int now)
{
    // 计算 结点的平衡因子
    if (ch[now] == '0')
        return 0;
    int lh = HeightDiff(2 * now + 1);
    int rh = HeightDiff(2 * now + 2);
    return lh > rh ? (lh + 1) : (rh + 1);

}


void print(int n,int now)
{
        if (ch[now] == '0')
            return;
        print(n,2 * now + 1);//左子树
        print(n, 2 * now + 2);//右子树
        cout << ch[now] << " " <<( HeightDiff(2*now+1)-HeightDiff(2*now+2)) << endl;
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,i;
        cin >> n;
        for (i = 0; i < 999; i++)
        {
            ch[i]='0';

        }
        for ( i = 0; i < n; i++)
        {
            cin >> ch[i];
            
        }
        print(n,0);
    }
        return 0;
    
}