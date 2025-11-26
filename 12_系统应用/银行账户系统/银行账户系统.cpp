#include <iostream>
using namespace std;
class Account
{
	int number;
	char type;
	int leftmoney;
	float interest;
	 float rate;//定

public:
	Account(int nu, char ty, int le);
	void jisuanrate();//计息
	void find();//查询
	Account(Account &a);


};

Account::Account(int nu, char ty, int le)
{
	number = nu;
	type = ty;
	leftmoney = le;
	rate = 0.005;
	interest = 0;
}
void Account::jisuanrate()
{
	
	interest = leftmoney * rate;
	leftmoney += interest;
	cout << "Account=" << number << "--sum=" << leftmoney<<endl;
}
Account::Account(Account& a)
{
	number = a.number + 50000000;
	rate = 0.015;
	type = a.type;
	leftmoney = a.leftmoney;
	interest = a.interest;
}
void Account::find()
{
	if (type == 'P')
	{
		cout << "Account=" << number << "--Person--";
		cout << "sum=" << leftmoney << "--rate=" << rate << endl;
	}
	else if (type == 'E')
	{
		cout << "Account=" << number << "--Enterprise--";
		cout << "sum=" << leftmoney << "--rate=" << rate << endl;
	}
}

int main()
{
	int t;
	int number;
	char type;
	char p1, p2;
	int leftmoney;
	
	cin>> t;
	while (t--)
	{
		cin >> number >> type >> leftmoney;
		Account account(number, type, leftmoney);
		Account account2(account);
		cin >> p1;
		if (p1 == 'C')
		{
			account.jisuanrate();

		}
		else if (p1 == 'P')
		{
			account.find();
		}

		cin >> p2;
		if (p2 == 'C')
		{
			account2.jisuanrate();

		}
		else if (p2 == 'P')
		{
			account2.find();
		}
	}
	     return 0;
}


