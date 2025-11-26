#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string st;
		cin >>st;
		int cnt1 = 0,cnt2=0,cnt3=0;
		if (st[0] == 'o')
				cnt1++;
		if (st[1] == 'n')
			cnt1++;
		if (st[2] == 'e')
			cnt1++;
		if (cnt1 >= 2) cout << "1" << endl;
		else
		{
			if (st[0] == 't')
				cnt2++;
			if (st[1] == 'w')
				cnt2++;
			if (st[2] == 'o')
				cnt2++;
			if (cnt2 >= 2)cout << "2" << endl;
			else
			{
				if (st[0] == 't')
					cnt3++;
				if (st[1] == 'h')
					cnt3++;
				if (st[2] == 'r')
					cnt1++;
				if (st[3] == 'e')
					cnt3++;
				if (st[4] == 'e')
					cnt3++;
				if (cnt3 >= 4)cout << "3" << endl;
			}
		}
	}
	return 0;
}

