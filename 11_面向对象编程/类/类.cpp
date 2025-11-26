#include <iostream>
#include<iomanip>
using namespace std;
class Date
{
protected:
    int year;
    int month;
    int day;
public:
    Date(){}
    Date(int y, int m, int d);
};
Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
class Time
{
protected:
    int  hour;
    int minute;
    int second;
public:
    Time(int h, int mi, int s);
};
Time::Time(int h, int mi, int s)
{
    hour = h;
    minute = mi;
    second = s;
}
class Work :public Date, public Time
{
protected:
    int id;

public:
    Work(int y, int m, int d, int h, int mi, int s, int i) :Date(y, m, d), Time(h, mi, s)
    {
        id = i;
    }
    friend bool before(const Work& w1, const Work& w2);
    void display();
};
bool before(const Work& w1, const Work& w2)
{
    double a,b;

    a=w1.year * 10000000 + w1.month * 1000000 + w1.day * 10000 + w1.hour * 1000 + w1.minute * 100 + w1.second;
    b = w2.year * 10000000 + w2.month * 1000000 + w2.day * 10000 + w2.hour * 1000 + w2.minute * 100 + w2.second;
    if (a>b)
    {
        return true;
}
    else
    {
        return false;
    }
}
void Work::display()
{

    cout << "The urgent Work is No." << id << ": " << year << "/" << setfill('0') << setw(2) << right << month << "/" << setfill('0') << setw(2) << right << day << " ";
    cout << setfill('0')<<setw(2)<<right<< hour << ":" << setfill('0') << setw(2) << right << minute << ":" << setfill('0') << setw(2) << right << second << endl;
}
int main()
{
    int id, year, month, day, hour, minute, second;
    cin >>id>> year >> month >> day >> hour >> minute >> second;
    Work w1(year, month, day, hour, minute, second, id);
    
    while (1)
    {


        cin >> id;
        if (id == 0)
        {
            break;
        }
        cin>> year >> month >> day >> hour >> minute >> second;
        Work w2(year, month, day, hour, minute, second, id);


        if (before(w1, w2))
        {
            w1 = w2;
        }
        
    }
    w1.display();
    return 0;
   
    
}