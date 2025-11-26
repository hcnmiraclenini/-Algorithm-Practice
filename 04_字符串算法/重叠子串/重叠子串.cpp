#include <iostream>
using namespace std;
int nex[100];
int cnt = 0;
void buildnex(string m)
{
	nex[0] = -1;
	for (int i = 0, j = -1; m[i];)
	{
		if (j == -1 || m[i] == m[j])
			nex[++i] = ++j;
		else j = nex[j];	
	}
}

int  kmp(string s, string m)
{
	cnt = 0;
	int len = m.size();
	int i, j;
	for (i = 0, j = 0; s[i]; )
	{
		if (j == -1 || s[i] == m[j])
		{
			if (j == len - 1)
			{
				cnt++;
				j = 0;
				i--;
			}
			else i++, j++;
		}
		else j = nex[j];
	}
	return cnt;
}
int main()
{
	int t;
	string st,m;
	cin >> t;
	while(t--)
	{
		cin >> st;
		int len = st.size();
		string m;
		int flag = 0;
		for (int j = 0; j < len-2; j++)
		{
			for (int i = len - 1; i >= 1; i--)
			{
				m = st.substr(j, i);
				buildnex(m);
				kmp(st, m);
				if (cnt >= 2)
				{
					cout << m.size() << endl;
					flag = 1;
					break; 
				}
				if (m.size() == 1 && j==len-1&&i==len-2&&cnt < 2)
				{
					cout << "-1" << endl; flag = 1;
				}
				else continue;

			}
			if (flag == 1)break;
		}

	}
	return 0;
}

