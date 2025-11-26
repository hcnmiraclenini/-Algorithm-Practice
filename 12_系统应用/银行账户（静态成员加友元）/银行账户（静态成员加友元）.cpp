#include <iostream>
#include<cstring>
using namespace std;
class Account
{
private:
    static float count; // 账户总余额
    static float interestRate;
    string accno, accname;
    float balance;
public:
    Account(string ac, string na, float ba);
    ~Account();
    void deposit(float amount); // 存款
    void withdraw(float amount); // 取款
    float getBalance(); // 获取账户余额
    void show(); // 显示账户所以基本信息
    static float getCount(); // 获取账户总余额
    static void setcount(float);
    static void setInterestRate(float rate); // 设置利率
    static float getInterestRate(); // 获取利率
    friend void update(Account& a);
};
float Account::count = 0;
float Account::interestRate = 0;

Account::Account(string ac, string na, float ba)
{
    accno = ac;
    accname = na;
    balance = ba;

}
void Account::deposit(float amount)
{
    balance = balance + amount;

}
void Account::withdraw(float amount)
{
    balance = balance - amount;

}
float Account::getBalance()
{
    return balance;
}
void Account::show()
{
    cout << accno << " " << accname << " " << balance;
}
float Account::getCount()
{
    return count;
}

void Account::setcount(float balance2)
{
    count = count + balance2;
}
void Account::setInterestRate(float rate)
{
    interestRate = rate;
}
float Account::getInterestRate()
{
    return interestRate;
}
void update(Account& a)
{
    a.balance = a.balance + a.balance * a.interestRate;
}
Account::~Account()
{

}
int main()
{

    float rate;
    cin >> rate;
    Account::setInterestRate(rate);
    string number;
    string name;

    float balance, depositmoney, withdrawmoney;
    int n;
    cin >> n;
    Account** p = new Account * [n];
    for (int i = 0; i < n; i++)
    {

        cin >> number >> name >> balance >> depositmoney >> withdrawmoney;
        p[i] = new Account(number, name, balance);
        /*存款*/
        p[i]->deposit(depositmoney);
        p[i]->show();
        update(*p[i]);
        cout << " " << p[i]->getBalance();

        /*取款*/
        p[i]->withdraw(withdrawmoney);
        cout << " " << p[i]->getBalance();
        cout << endl;

        Account::setcount(p[i]->getBalance());
    }
    cout << Account::getCount() << endl;
    delete[]p;
}