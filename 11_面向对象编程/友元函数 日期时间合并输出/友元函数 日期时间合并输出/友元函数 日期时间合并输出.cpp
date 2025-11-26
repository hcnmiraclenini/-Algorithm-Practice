#include <iostream>
#include <iomanip>
using namespace std;
class Time;
class Date
{
private:
	int year;
	int month;
	int day;
public:
	friend void display(const Date& d, const Time& t);
	Date() {}
	Date(int y_, int m_, int d_)
	{
		year = y_;
		month = m_;
		day = d_;
	}



};
class Time
{
private:
	int hour;
	int min;
	int second;
	Date date;
public:
	friend void display(const Date& d, const Time& t);
	Time() {}
	Time(int h_, int m, int  s_)
	{
		hour = h_;
		min = m;
		second = s_;
	}
};
void display(const Date& d, const Time& t)
{
	cout << d.year << "-" << setfill('0') << setw(2) << right << d.month;
	cout << "-" << setfill('0') << setw(2) << right << d.day;
	cout << " " << setfill('0') << setw(2) << right << t.hour << ":" << setfill('0') << setw(2) << right << t.min << ":" << setfill('0') << setw(2) << right << t.second << endl;
}
int main()
{
	int t;
	int year, month, day, h, m, s;
	cin >> t;
	while (t--)
	{
		cin >> year >> month >> day >> h >> m >> s;
		Date date(year, month, day);
		Time time(h, m, s);
		display(date, time);
	}
}