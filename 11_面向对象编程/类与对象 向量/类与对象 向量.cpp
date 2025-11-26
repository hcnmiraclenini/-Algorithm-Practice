#include <iostream>
#include<cstring>
using namespace std;
class CVector
{
private:
    int* data;//存储n维向量
    int n; //向量维数
public:
    CVector();
    CVector(int n1, int da[]);
    void print();
    ~CVector();
    friend CVector add(const CVector v11, const CVector v22);
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
    data = new int[n1];
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
CVector::~CVector()
{
    delete data;
}
CVector add(const CVector v11, const CVector v22)
{
    int i;
    for (i = 0; i < v11.n; i++)
    {
        v11.data[i] = v22.data[i] + v11.data[i];
        return v11;
    }
}
int main()
{
    int t;
    cin >> t;
    int c1[20], c2[20];
    for (int i = 1; i <= t; i++)
    {
        int n1;
        cin >> n1;
        for (int j = 0; j < n1; j++)
        {
            cin >> c1[j];
        }
        CVector v1(n1, c1);
        v1.print();
        for (int k = 0; k < n1; k++)
        {
            cin >> c2[k];
        }
        CVector v2(n1, c2);
        v2.print();
        add(v1, v2).print();
    }


}