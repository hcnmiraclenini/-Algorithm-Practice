#include <iostream>
#include<cstring>
using namespace std;
class CVector
{
private:
    int* data=NULL;//存储n维向量
    int n; //向量维数
public:
    CVector();
    CVector(int n1, int da[]);
    void print();
    ~CVector();
    friend CVector add(CVector v11, CVector v22);
    CVector(const CVector& c);
};

CVector::CVector()
{

    n = 5;
    int i;
    data = new int[5];
    for (i = 0; i < 5; i++)
    {
        *(data + i) = i;
    }

}
CVector::CVector(int n1, int da[])
{
    n = n1;
    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        *(data + i) = da[i];
    }


}
void CVector::print()
{
    int i;
    for (i = 0; i < n - 1; i++)
    {
        cout << data[i] << " ";
    }
    cout << data[i] << endl;
}
CVector::CVector(const CVector& c)
{
    n = c.n;
    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = c.data[i];
    }

}
CVector::~CVector()
{
    delete data;
}
CVector add(CVector v11, CVector v22)
{
    int i;
    int a[20];
    int* data = new int[v11.n];
    for (i = 0; i < v11.n; i++)
    {
        data[i] = v22.data[i] + v11.data[i];

    }
    CVector v3(v11.n,data);
    return v3;
   
}
int main()
{
    int t;
    cin >> t;
   
    for (int i = 1; i <= t; i++)
    {
        int n1;
        cin >> n1;
        int* a = new int[n1];
        for (int j = 0; j < n1; j++)
        {
            cin >> a[j];
        }
        CVector v1(n1, a);
        v1.print();
        int* b = new int[n1];
        for (int k = 0; k < n1; k++)
        {
            cin >> b[k];
        }
        CVector v2(n1, b);
        v2.print();
       
       add(v1,v2).print();
    }
    
    return 0;

}