锘 ? include <iostream>
#include<cstring>
using namespace std;
//鏃ユ湡绫?
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
//15浣嶆棩鏈?
class COldId :public CDate
{
public:
	char* pId15, * pName; //15浣嶈韩浠借瘉鍙风爜锛屽鍚?
	CDate birthday; //鍑虹敓鏃ユ湡
	COldId() {}
	COldId(char* pIdVal, char* pNameVal, CDate& day);
	~COldId();
};
COldId::COldId(char* pIdVal, char* pNameVal, CDate& day)
{
	pId15 = new char[16];
	//strcpy(pId15, pIdVal);
	strcpy_s(pId15, 16, pIdVal);
	int length = strlen(pNameVal);
	pName = new char[length + 1];
	//strcpy(pName, pNameVal);
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
//18浣嶈韩浠借瘉绫?
class CNewId :public COldId
{
protected:
	char* pId18;
	int validYear;//鏈夋晥鏈燂紝骞存暟
	CDate cdate;
	COldId coldid;
public:
	CNewId(int year1, int month1, int day1, char* pId15_, char* pname, CDate& birthdayday, char* pId18_, int validy) : cdate(year1, month1, day1), coldid(pId15_, pname, birthdayday)
	{
		pId18 = new char[19];
		//strcpy(pId18, pId18_);
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
	case 1:pId18[17] = '1'; break;
	case 2:pId18[17] = '0'; break;
	case 3:pId18[17] = 'X'; break;
	case 4:pId18[17] = '9'; break;
	case 5:pId18[17] = '8'; break;
	case 6:pId18[17] = '7'; break;
	case 7:pId18[17] = '6'; break;
	case 8:pId18[17] = '5'; break;
	case 9:pId18[17] = '4'; break;
	case 10:pId18[17] = '3'; break;
	case 11:pId18[17] = '2'; break;
	default:  break;
	}
	return pId18[17];
}
/*1. 纭18浣嶅彿鐮佹槸浠?5浣嶅彿鐮佹墿灞曠殑锛屼笖绗?8浣嶆牎楠岀爜姝ｇ‘.

2. 韬唤璇佷腑鐨勫嚭鐢熸棩鏈熷悎娉?

3. 韬唤璇佸彿鐮佷腑涓嶅惈闈炴硶瀛楃.

4. 韬唤璇佸彿鐮佺殑闀垮害姝ｇ‘.

5. 韬唤璇佺洰鍓嶅浜庢湁鏁堟湡鍐咃紝鍋囪褰撳墠鏃ユ湡涓?021骞?1鏈?鏃ャ€?*/
bool CNewId::check()//瀵硅韩浠借瘉鍚堟硶鎬ц繘琛岄獙璇?  //鍔犱釜鍒ゆ柇绛捐瘉鏃ユ湡鏄惁鍚堟硶鐨勫垽鏂?鐢熸棩鍒ゆ柇+纭18浣嶅彿鐮佹槸浠?5浣嶅彿鐮佸彉鏉?鍓嶉潰鍏綅淇濇寔涓€鑷达紝 鍊掓暟绗?鍒板€掓暟绗?涓€鑷?
{
	int i, flag = 1;
	for (i = 0; i < 6; i++) //18浣嶅彿鐮佸拰15浣嶅彿鐮佸墠闈㈠叚浣嶄繚鎸佷竴鑷?
	{
		if (pId18[i] != coldid.pId15[i])
		{
			flag = 0;
			break;
		}

	}
	for (i = 13; i >= 10; i--)//18浣嶅彿鐮佸拰15浣嶅彿鐮佸€掓暟绗?浣嶏紝鍊掓暟绗洓锛屽€掓暟绗笁锛屽€掓暟绗簩涓€鑷?
	{
		if (pId18[i] != coldid.pId15[i])
		{
			flag = 0;
			break;
		}
	}

	if (pId18[17] != geteighteen())//绗?8浣嶆牎楠岀爜姝ｇ‘
	{
		flag = 0;

	}

	if (((pId18[6] - '0') * 1000 + (pId18[7] - '0') * 100 + (pId18[8] - '0') * 10 + (pId18[9] - '0') != coldid.birthday.gety()) || ((pId18[10] - '0') * 10 + (pId18[11] - '0') == coldid.birthday.getm()) || ((pId18[12] - '0') * 10 + (pId18[13] - '0') == coldid.birthday.getd()))//鍑虹敓鏃ユ湡涓嶅悎娉?绗?浣嶅埌绗?浣嶆槸鍑虹敓骞翠唤锛岀10鍒?1鏄嚭鐢熸湀浠斤紝绗?2鍒?3鏄棩鏈?
	{
		flag = 0;

	}
	for (i = 0; i < 17; i++)//鍓?7浣嶅惈闈炴硶瀛楃
	{
		if (pId18[i] < '0' || pId18[i]>'9')
		{
			flag = 0;
			break;
		}

	}

	if (strlen(pId18) != 18)//闀垮害涓嶆纭?
	{
		flag = 0;
	}
	if (((pId18[5] - '0') * 1000 + (pId18[6] - '0') * 100 + (pId18[7] - '0') * 10 + (pId18[8] - '0')) > 2021 + validYear)//鐩墠娌″浜庢湁鏁堟湡鍐?
	{
		flag = 0;
	}
	if (((cdate.gety() % 400 == 0) || (cdate.gety() % 4 == 0 && cdate.gety() % 100 != 0)) && (cdate.getm() == 2) && (cdate.getd() != 29))//绛捐瘉鏃ユ湡鏄棸骞翠絾浜屾湀涓嶆槸29澶?
	{
		flag = 0;
	}
	if (cdate.getm() < 0 || cdate.getm() > 12)//鍑虹幇濂囨€殑鏈堜唤
	{
		flag = 0;
	}
	if (cdate.getd() > 31)//鏈堜唤澶╂暟瓒呰繃31澶?涓嶅悎娉?
	{
		flag = 0;
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
	cout << pName << endl;
	cout << pId18 << " " << cdate.gety() << "骞? << cdate.getm() << "鏈? << cdate.getd() << "鏃? << " " << validYear << "骞? << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char name[21];
		int year, month, day;//鍑虹敓鏃ユ湡
		char id15[16];
		char id18[19];
		int year1, month1, day1;//绛惧彂鏃ユ湡
		int validd;//鏈夋晥鏈?
		cin >> name >> year >> month >> day;
		cin >> id15 >> id18 >> year1 >> month1 >> day1 >> validd;

		CDate date(year, month, day);//鐢熸棩

		CNewId cnew(year1, month1, day1, id15, name, date, id18, validd);//浼犵鍙戞棩鏈燂紙骞存湀鏃ワ級锛?5浣嶇爜锛屽悕瀛楋紝鐢熸棩鏃ユ湡绫伙紝18浣嶇爜锛?
		if (cnew.check() == 1)
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