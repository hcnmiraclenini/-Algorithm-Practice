#include <iostream>
#include<stack>
using namespace std;
int a[100], b[100];
void  mergeq(int a[], int b[], int m, int n)//m是a数组长度  n是b数组长度
{
	int t[100];
	int q = 0;
	for (int i = 0, j = 0; i != m || j!= n;)
	{
		if ( b[j] <a[i])
			t[q++] = b[j];
		else
			t[q++] = a[i];
		if (i != m)
			t[q++] = a[i];
		
	}
	for (int i = 0; i < q; i++)
		cout << t[i] << " ";
	cout << endl;
}
int main()
{
	int m, n;
	cin >> m;;
	for (int i = 0; i < m; i++)
		cin >> a[i];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	mergeq(a, b, m, n);
}

