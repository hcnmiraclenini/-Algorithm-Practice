#include <iostream>
#include<cstring>
using namespace std;
//日期类
class CDate
{
private:
	int year, month, day;
public:
	CDate() {}
	CDate(int y, int m, int d);
	void sety(int y);
	void setm(int m);
	void setd(int d);
	int gety();
	int getm();
	int getd();
};
CDate::CDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
int CDate::gety()
{
	return year;
}
int CDate::getm()
{
	return month;
}
int CDate::getd()
{
	return day;
}
void CDate::sety(int y)
{
	year = y;
}
void CDate::setm(int m)
{
	month = m;
}
void CDate::setd(int d)
{
	day = d;
}
//15位日期
class COldId :public CDate
{
public:
	char* pId15, * pName; //15位身份证号码，姓名
	CDate birthday; //出生日期
	COldId() {}
	COldId(char* pIdVal, char* pNameVal, CDate& day);
	~COldId();
};
COldId::COldId(char* pIdVal, char* pNameVal, CDate& day)
{
	pId15 = new char[16];
	strcpy_s(pId15, 16, pIdVal);
	int length = strlen(pNameVal);
	pName = new char[length + 1];
	strcpy_s(pName, length + 1, pNameVal);
	birthday.sety(day.gety());
	birthday.setm(day.getm());
	birthday.setd(day.getd());
}
COldId::~COldId()
{
	if (pId15)
	{
		delete[]pId15;
	}
	if (pName)
	{
		delete[]pName;
	}
}
//18位身份证类
class CNewId :public COldId
{
protected:
	char* pId18;
	int validYear;//有效期，年数
	CDate cdate;
	COldId coldid;
public:
	CNewId(int year1, int month1, int day1, char* pId15_, char* pname, CDate& birthdayday, char* pId18_, int validy) : cdate(year1, month1, day1), coldid(pId15_, pname, birthdayday)
	{
		pId18 = new char[19];
		strcpy_s(pId18, 19, pId18_);
		validYear = validy;
	}
	bool check();
	void print();
	char geteighteen();
	~CNewId();
};

char CNewId::geteighteen()
{
	int sum = ((pId18[0] - '0') * 7 + (pId18[1] - '0') * 9 + (pId18[2] - '0') * 10 + (pId18[3] - '0') * 5 + (pId18[4] - '0') * 8 + (pId18[5] - '0') * 4 + (pId18[6] - '0') * 2 + (pId18[7] - '0') * 1 + (pId18[8] - '0') * 6 + (pId18[9] - '0') * 3 + (pId18[10] - '0') * 7 + (pId18[11] - '0') * 9 + (pId18[12] - '0') * 10 + (pId18[13] - '0') * 5 + (pId18[14] - '0') * 8 + (pId18[15] - '0') * 4 + (pId18[16] - '0') * 2) % 11;
	switch (sum)
	{
	case 0:pId18[17] = '1'; break;
	case 1:pId18[17] = '0'; break;
	case 2:pId18[17] = 'X'; break;
	case 3:pId18[17] = '9'; break;
	case 4:pId18[17] = '8'; break;
	case 5:pId18[17] = '7'; break;
	case 6:pId18[17] = '6'; break;
	case 7:pId18[17] = '5'; break;
	case 8:pId18[17] = '4'; break;
	case 9:pId18[17] = '3'; break;
	case 10:pId18[17] = '2'; break;
	default:  break;
	}
	return pId18[17];
}
/*1. 确认18位号码是从15位号码扩展的，且第18位校验码正确.

2. 身份证中的出生日期合法.

3. 身份证号码中不含非法字符.

4. 身份证号码的长度正确.

5. 身份证目前处于有效期内，假设当前日期为2021年11月8日。*/
bool CNewId::check()//对身份证合法性进行验证   //加个判断签证日期是否合法的判断+生日判断+确认18位号码是从15位号码变来 前面六位保持一致， 倒数第5到倒数第2一致
{
	int i, flag = 1;
	for (i = 0; i < 6; i++) //18位号码和15位号码前面六位保持一致
	{
		if (pId18[i] != coldid.pId15[i])
		{
			flag = 0;
			cout << "@" << endl;
			break;

		}

	}
	for (i = 14; i >= 10; i--)//18位号码和15位号码倒数第5位，倒数第四，倒数第三，倒数第二一致
	{
		if (pId18[i + 2] != coldid.pId15[i])
		{
			flag = 0;
			cout << "#" << endl;
			break;
		}
	}

	if (pId18[17] != geteighteen())//第18位校验码正确
	{

		flag = 0;
		cout << "&" << endl;
	}

	if (((pId18[6] - '0') * 1000 + (pId18[7] - '0') * 100 + (pId18[8] - '0') * 10 + (pId18[9] - '0')) != coldid.birthday.gety() || ((pId18[10] - '0') * 10 + (pId18[11] - '0')) != coldid.birthday.getm() || ((pId18[12] - '0') * 10 + (pId18[13] - '0')) != coldid.birthday.getd())//出生日期不合法.第6位到第9位是出生年份，第10到11是出生月份，第12到13是日期
	{
		flag = 0;
		cout << "888" << endl;

	}
	for (i = 0; i < 17; i++)//前17位含非法字符
	{
		if (pId18[i] < '0' || pId18[i]>'9')
		{
			flag = 0;
			cout << "%" << endl;
			break;
		}

	}

	if (strlen(pId18) != 18)//长度不正确
	{

		flag = 0;
		cout << "~" << endl;
	}
	if ((cdate.gety() * 365 + cdate.getm() * 30 + cdate.getd()) > ((2021 + validYear) * 365 + 11 * 30 + 8))//目前没处于有效期内
	{

		flag = 0;
		cout << "##";
	}

	if (((cdate.gety() % 400) == 0 || ((cdate.gety() % 4) == 0 && (cdate.gety() % 100) != 0)) && (cdate.getm()) == 2 && (cdate.getd()) != 29)//签证日期是闰年但二月不是29天
	{
		flag = 0;
		cout << "(" << endl;
	}
	if (cdate.getm() < 0 || cdate.getm() > 12)//出现奇怪的月份
	{
		flag = 0;
		cout << ")" << endl;
	}
	if (cdate.getd() > 31)//月份天数超过31天 不合法
	{
		flag = 0;
		cout << "@!" << endl;
	}
	if (flag == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}


CNewId::~CNewId()
{
	if (pId18)
	{
		delete[]pId18;
	}
}
void CNewId::print()
{
	if (validYear == 100)
	{

		cout << pName << endl;
		cout << pId18 << " " << cdate.gety() << "年" << cdate.getm() << "月" << cdate.getd() << "日" << " 长期" << endl;
	}
	else
	{
		cout << pName << endl;
		cout << pId18 << " " << cdate.gety() << "年" << cdate.getm() << "月" << cdate.getd() << "日" << " " << validYear << "年" << endl;
	}

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char name[21];
		int year, month, day;//出生日期
		char id15[20];
		char id18[20];
		int year1, month1, day1;//签发日期
		int validd;//有效期
		cin >> name >> year >> month >> day;
		cin >> id15 >> id18 >> year1 >> month1 >> day1 >> validd;

		CDate date(year, month, day);//生日

		CNewId cnew(year1, month1, day1, id15, name, date, id18, validd);//传签发日期（年月日），15位码，名字，生日日期类，18位码，
		if (cnew.check())
		{
			cnew.print();
		}
		else
		{
			cout << name << endl;
			cout << "illegal id" << endl;
		}


	}
	return 0;
}

