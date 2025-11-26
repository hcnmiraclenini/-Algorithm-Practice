#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string s;
	char str[20];
	char c;

	cout << "------------------------用法1---------------------------------------" << endl;
	c = cin.get();//读入单个字符，也可以写成cin.get(c),类似于c = getchar();//可用于吞字符(串)
	cout << c << endl;

	getchar();
	cout << "------------------------用法2---------------------------------------" << endl;
	cin.get(str, 20);//读入超过20个时，存19个+结束符
	cout << str << endl;
	
	cin.get();
	cout << "------------------------用法3---------------------------------------" << endl;
	cin.get(str, 20, 'a');
	cout << str << endl;
	return 0;
}