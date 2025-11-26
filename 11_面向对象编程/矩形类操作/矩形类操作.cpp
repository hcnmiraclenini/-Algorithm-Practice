#include <iostream>
#include<iomanip>
using namespace std;
class travel
{
protected:
    int membership;//卡号
    float trippoint=0;//旅程积分
public:
    travel(int m);
};
travel::travel(int m)
{

    membership = m;
  
}
class Creditcard
{
protected:
    int cardnumber;//信用卡号
    string name;
    int limit; //额度
    float billamount=0;//  账单金额
    float credit=0;//信用卡积分
public:
    Creditcard(int ca, string n, int l);
    void consume(float a);// 消费
    void refund(float b);
};
Creditcard::Creditcard(int ca, string n, int l)
{
    cardnumber = ca;
    name = n;
    limit = l;
    
}
void Creditcard::consume(float a)
{
    if (a <= limit)//不超额度
    {
        billamount +=  a;//单金额+a
        limit -= a;//额度-a
        credit += a;//信用卡积分按消费金额累加
    }
    
}
void Creditcard::refund(float b)
{
    billamount -= b; //账单金额 - b
    credit -= b;//信用卡积分减去退款金额
}
class D :public travel, public Creditcard//旅程信用卡
{
public:
    D(int m,int ca, string n, int l) :travel(m), Creditcard(ca, n,l)
    {
       
    }
    void newone(float b);//在旅程网下单
    void exchange(float m);//信用卡积分兑换为旅程积分
    void print();
};

void D::newone(float b)
{
    trippoint += b;//旅程积分同时增加
    credit += b;   // 信用卡积分增加
    billamount += b;//账单金额增加
}
void D::exchange(float m)//m是要兑换的信用卡积分
{
    trippoint = trippoint + m / 2.0;//小细节2.0
    credit -= m;
}
void D::print()
{
    cout << membership << " ";
    cout << fixed<<setprecision(0)<<trippoint << endl;
    cout << cardnumber << " " << name << " " << fixed << setprecision(1)<<billamount << " " << fixed << setprecision(0)<<credit << endl;
}
int main()
{
    int membershipn, cardnumber;//旅程会员卡号 信用卡号
    string name;
    int limit;//额度
    cin >> membershipn >> cardnumber >> name >> limit;
    int t;
    cin >> t;
    char ch;//啥操作
    float m;//几钱
    D d(membershipn, cardnumber, name, limit);
    while (t--)
    {
        
        cin >> ch;
        if (ch == 'o')//旅程网下订单
        {
            cin >> m;
            
            d.newone(m);

        }
        if (ch == 'c')//信用卡消费
        {
            cin >> m;
            d.consume(m);
        }
        if (ch == 'q')//信用卡退款
        {
            cin >> m;
            d.refund(m);
        }
        if (ch == 't')//积分兑换
        {
            cin >> m;//行用卡积分
            d.exchange(m);


        }
    }
    d.print();
    return 0;
}
