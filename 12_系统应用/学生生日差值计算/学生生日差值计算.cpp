#include <iostream>
#include<cstring>
using namespace std;
class Student
{
public:
    string name;
    int year;
    int month;
    int day;
public:

    void set(string na, int y, int m, int d);
    int operator-(Student& s);
    bool isleapyear(int y);
    int& daytonewyear(Student& s);//算这一天是这一年的第几天
    string getname();
};

void Student::set(string na, int y, int m, int d)
{
    name = na;
    year = y;
    month = m;
    day = d;
}

int& Student::daytonewyear(Student& s)
{
    int i, sum = s.day;
    const int m[13] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//闰年
    const int n[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//平年
    if (s.isleapyear(s.year))//闰年
    {
        for (i = 0; i < s.month - 1; i++)
        {
            sum = sum + m[i];
        }
    }
    else
    {

        for (i = 0; i < s.month - 1; i++)
        {
            sum = sum + n[i];
        }
    }
    return sum;

}
int Student::operator-(Student& s)
{
    const int m[13] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//闰年
    const int n[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//平年
    if (year == s.year)
    {
        return abs(daytonewyear(*this) - daytonewyear(s));
    }
    else if (year > s.year)
    {
        //int temp = s.year;//临时变量贮存 防止原变量值被改变
       // int sum = daytonewyear(*this);
        for (int i = s.year; i < this->year; i++)
        {
            if (isleapyear(i))
            {
                daytonewyear(*this) += 366;
            }
            else
            {
                daytonewyear(*this) += 365;
            }

        }
        return daytonewyear(*this) - daytonewyear(s);
    }
    else
    {
        int temp = year;
        //int sum = daytonewyear(s);
        for (int i = this->year; i < s.year; i++)
        {

            if (isleapyear(temp))
            {
                daytonewyear(s) += 366;
            }
            else
            {
                daytonewyear(s) += 365;
            }
            temp++;
        }
        return  daytonewyear(s) - daytonewyear(*this);
    }
}

bool Student::isleapyear(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        return 1;

    }
    else
    {
        return 0;

    }
}


string Student::getname()
{
    return name;
}
int main()
{
    int t, i, j;
    cin >> t;
    Student* p = new Student[t];

    string name;
    int year, month, day;
    for (i = 0; i < t; i++)
    {

        cin >> name >> year >> month >> day;
        p[i].set(name, year, month, day);

    }

    /*for (i = 0; i < t; i++)
    {

        cout <<p[i].getname () <<" "<< p[i].year << " " << p[i].month << " " << p[i].day << endl;

    }*/
    int min = 1000000;
    Student s1, s2;//存俩个生日差值最小的学生
    for (i = 0; i < t - 1; i++)
    {
        for (j = i + 1; j < t; j++)
        {

            if ((p[i] - p[j]) < min)
            {
                min = p[i] - p[j];

                s1 = p[i];
                s2 = p[j];
            }
            // cout << p[i].name << " and " << p[j].getname() << "相差" << p[i] - p[j] << endl;
        }
    }
    cout << s1.getname();
    cout << "和";
    cout << s2.getname();
    cout << "年龄相差最小，为";
    cout << min;
    cout << "天。" << endl;

}