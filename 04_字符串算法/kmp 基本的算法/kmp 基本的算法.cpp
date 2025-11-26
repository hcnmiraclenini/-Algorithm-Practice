#include<iostream>
#include<cstring>
using namespace std;
int nex[100];
void  buildnex(char m[])
{
	nex[0] = -1;
	int i, j;
	for (i = 0, j = -1; m[i];)
	{
		if (j == -1 || m[i] == m[j])
			nex[++i] = ++j;
		else
			j = nex[j];
	}
}
void printnex(char m[])//输出nex数组
{
	for (int i = 0; i < strlen(m); i++)
		cout << nex[i] << " ";
	cout << endl;
}
int kmp(char s[], char m[])
{
	int len = strlen(m);
	for (int i = 0, j = 0; s[i];)
	{
		if (j == -1 || s[i] == m[j])
		{
			if (j == len - 1)
				return i - len + 2;//位置从1开始计算(+1+1)
			else  i++, j++;
		}
		else j = nex[j];
	}
	return 10086;//找不到
}
int  main()
{
	int t;
	cin >> t;
	char ms[100], s[100],re[100];
	char temp[100];
	while (t--)
	{
		cin >> s >> ms>>re;//输入：主串 模式串 替换串
		cout << s<<endl;
		buildnex(ms);
		int place = kmp(s, ms);
		if (place == 10086)
		{
			cout << s << endl;
		}
		 else if(place == 1)
		{
			int m = 0;
				for (int i = place + strlen(ms)-1; i < strlen(s); i++)
					temp[m++] = s[i];
				cout << re;
				for (int i =0; i < m; i++)
					cout << temp[i];
				cout << endl;

		}
		else
		{
			int m = 0;
			for (int i = place + strlen(ms)-1; i < strlen(s); i++)
				temp[m++] = s[i];
			
			for (int i = 0; i < place-1; i++)
				cout << s[i];
			    cout << re;
				
				for (int i =0; i <m; i++)
					cout << temp[i];
			
			cout << endl;
		}

	}
	return 0;
}