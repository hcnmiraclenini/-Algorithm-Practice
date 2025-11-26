#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;
//小学二年级还没学负数
class Group
{
public:

    virtual int add(int x, int y) = 0; // 输出加法的运算结果
    virtual int sub(int x, int y) = 0; // 输出减法的运算结果
};
class GroupA :public Group
{
public:
    int add(int x, int y);
    int sub(int x, int y);
};
int GroupA::add(int x, int y)
{
    return (x + y);
}
int GroupA::sub(int x, int y)
{
    return(x - y);
}
//正确地完成加法运算，但对于减法运算来说，总是忘记借位的处理
class GroupB :public Group
{
public:
    int add(int x, int y);
    int sub(int x, int y);
};
int GroupB::add(int x, int y)
{
    return (x + y);
}
int GroupB::sub(int x, int y)
{

    int a[8] = { 0,0,0,0,0,0,0,0 };//结果的个位,十位,百位，千位，万，十万，百万；
    int i, n = 0;
    //统计该数的个数
    if (x / 10 == 0) n = 1;
    if (x / 100 == 0)n = 2;
    if (x / 1000 == 0)n = 3;
    if (x / 10000 == 0)n = 4;
    if (x / 100000 == 0)n = 5;
    if (x / 1000000 == 0)n = 6;
    if (x / 1000000 == 0)n = 7;
    if (x / 1000000 == 0)n = 8;
    
       int j = 0,b,c;
    for (i = 1; i <= n; i++)
    {
        //从个位开始
       
        b = pow(10, i);
        c = pow(10, i - 1);
        if ((x % b) / c - (y % b) / c < 0)
        {
            a[j] = (x % b) / c + 10 - (y % 10) / c;
        }
        else
        {
            a[j] = (x % b) / c - (y % b) / c;
        }
        j++;
    }
    int result = a[7] * pow(10, 7) + a[6] * pow(10, 6) + a[5] * pow(10, 5) + a[4] * pow(10, 4) + a[3] * pow(10, 3) + a[2] * pow(10, 2) + a[1] * pow(10, 1) + a[0];
    return result;
}
//总是忘记加法的进位，也总是忘记减法的借位
class GroupC :public Group
{
public:
    int add(int x, int y);
    int sub(int x, int y);
};
int GroupC::add(int x, int y)
{
    int a[8] = { 0,0,0,0,0,0,0,0 };//结果的个位,十位,百位，千位，万，十万，百万；
    int i, n = 0;
    //统计该数的个数
    if (x / 10 == 0) n = 1;
    if (x / 100 == 0)n = 2;
    if (x / 1000 == 0)n = 3;
    if (x / 10000 == 0)n = 4;
    if (x / 100000 == 0)n = 5;
    if (x / 1000000 == 0)n = 6;
    if (x / 1000000 == 0)n = 7;
    if (x / 1000000 == 0)n = 8;
    int j = 0, b, c;
    for (i = 1; i <= n; i++)
    {
        //从个位开始
        
         b = pow(10, i);
         c = pow(10, i - 1);
        if ((x % b) / c + (y % b) / c > 10)
        {
            a[j] = (x % b) / c - 10 + (y % b) / c;
        }
        else
        {
            a[j] = (x % b) / c + (y % b) / c;
        }
        j++;
    }
    int result = a[7] * pow(10, 7) + a[6] * pow(10, 6) + a[5] * pow(10, 5) + a[4] * pow(10, 4) + a[3] * pow(10, 3) + a[2] * pow(10, 2) + a[1] * pow(10, 1) + a[0];
    return result;
    

}
int GroupC::sub(int x, int y)
{
    int a[8] = { 0,0,0,0,0,0,0,0 };//结果的个位,十位,百位，千位，万，十万，百万；
    int i, n = 0;
    //统计该数的个数
    if (x / 10 == 0) n = 1;
    if (x / 100 == 0)n = 2;
    if (x / 1000 == 0)n = 3;
    if (x / 10000 == 0)n = 4;
    if (x / 100000 == 0)n = 5;
    if (x / 1000000 == 0)n = 6;
    if (x / 1000000 == 0)n = 7;
    if (x / 1000000 == 0)n = 8;
       int j = 0,b,c;
    for (i = 1; i <= n; i++)
    {
        //从个位开始
        
        b = pow(10, i);
        c = pow(10, i - 1);
        if ((x % b) / c - (y % b) / c < 0)
        {
            a[j] = (x % b) / c + 10 - (y % 10) / c;
        }
        else
        {
            a[j] = (x % b) / c - (y % b) / c;
        }
        j++;
    }
    int result = a[7] * pow(10, 7) + a[6] * pow(10, 6) + a[5] * pow(10, 5) + a[4] * pow(10, 4) + a[3] * pow(10, 3) + a[2] * pow(10, 2) + a[1] * pow(10, 1) + a[0];
    return result;
}
int main()
{


    int t;
    cin >> t;
    Group* p = NULL;
    GroupA* ga = new GroupA;
    GroupB* gb = new GroupB;
    GroupC* gc = new GroupC;
    int type, a, b;
    char ch;
    while (t--)
    {
        cin >> type;
        cin >> a >> ch >> b;
        if (type == 1)
        {
           
            p = ga;
            if (ch == '+')
            {
                cout << p->add(a, b) << endl;
            }
            else if (ch == '-')
            {
                cout << p->sub(a, b) << endl;
            }

        }
        else if (type == 2)
        {
            
            p = gb;
            if (ch == '+')
            {
                cout << p->add(a, b) << endl;
            }
            else if (ch == '-')
            {
                cout << p->sub(a, b) << endl;
            }

        }

        else if (type == 3)
        {

            p = gc;
            if (ch == '+')
            {
                cout << p->add(a, b) << endl;

            }
            else if (ch == '-')
            {
                cout << p->sub(a, b) << endl;
            }

        }

    }
    //delete p; 
    delete ga;
    delete gb;
    delete gc;
    return 0;

    }

