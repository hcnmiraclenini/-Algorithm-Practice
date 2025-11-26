#include <iostream>
using namespace std;
class tree
{
public:
	int i, j, k;
	int  a;
	
};
//a=0表示值为k的这个结点不是值为i的结点和值为j的结点的最近公共祖先
//a=1表示值为k的这个结点是值为i的结点和值为j的结点的最近公共祖先
tree tr[100000];
int len=0;
int t1[100];
int t2[100];
int n;
void fn()
{
	for (int g = 0; g < len; g++)
	{
		if (tr[g].a == 1)
		{
			t1[tr[g].k]++;
			t2[tr[g].k] = tr[g].j;
		}
	}
	int temp = 0;
	int temp2=1;
	for (int p = 1; p <= n; p++)
	{
		temp = (t1[p] > t1[temp] ?p : temp);
	}
	for (int q = 1; q <= n; q++)
	{
		if (temp == t2[q])temp2 = 0;
	}
	if (temp2)cout << temp <<endl;
}
int main()
{
	
	cin >> n;
	len = n * (n - 1) * (n - 2);
	for (int p = 0; p < len; p++)
	{
		int i_, j_, k_;
		int a_;
		cin >> i_ >> j_ >> k_ >> a_;
		tr[p].i = i_; tr[p].j = j_;
		tr[p].k = k_; tr[p].a = a_;
	}
	fn();
	return 0;
}
