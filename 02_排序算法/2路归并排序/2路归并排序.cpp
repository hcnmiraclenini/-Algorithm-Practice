#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int a[100010];
int mergeTemp[1100];
class Node 
{
public:
	vector<int> v;
	int l, r;
	void init(int _l = -1, int _r = -1)
	{
		l = _l;
		r = _r;
	}
};
Node tr[100010];
int tp = 0;
//自下而上 从左到右
//自顶向下进行，即递归调用 MergeSort(left, mid)、
//MergeSort(mid, right)
//本题约定数组区间为[1, n]， mid = (left + right) / 2
//递归子区间为[left, mid]、[mid + 1, right]
int  MergeSort(int left, int right, int n)
{
	tp++;
	int o = tp;
	if (left >= right)
	{
		tr[o].init();
		tr[o].v.push_back(a[left]);
		return o;
	}
	int mid = (left + right) / 2;
	tr[o].init();

	tr[o].l = MergeSort(left, mid, n);
	tr[o].r = MergeSort(mid + 1, right, n);


	int i, j, k;
	int cnt = 0;
	for (i = k = left, j = mid + 1; i <= mid && j <= right;)
	{
		if (a[i] <= a[j])
		{

			mergeTemp[k++] = a[i++];
		}
		else
		{

			mergeTemp[k++] = a[j++];
		}

	}
	while (i <= mid)
	{

		mergeTemp[k++] = a[i++];
	}
	while (j <= right)
	{
		mergeTemp[k++] = a[j++];
	}

	/*for (int i = left; i < right; i++)
	{
		a[i] = mergeTemp[i];
	}*/
	for (int p = left; p <= right; p++)
	{
		a[p] = mergeTemp[p];
		tr[o].v.push_back(a[p]);
	}
	return o;
}
queue<int> q;
vector<int> vec;
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cout << (2 * n - 1 )<< endl;
	int root = MergeSort(1, n, n);
	
	q.push(root);
	while (!q.empty())
	{
		int m = q.size();
		for (int i = m; i >= 1; i--)
		{
			int y = q.front();
			q.pop();
			vec.push_back(y);
			if (tr[y].r != -1)
				q.push(tr[y].r);
			if (tr[y].l != -1)
				q.push(tr[y].l);
		}
	}
	int size = vec.size();
	for (int i =size-1 ; i >= 0; i--)
	{
		vector<int> tmp = tr[vec[i]].v;
		cout << tmp[0];
		int si = tmp.size();
		for (int j = 1; j <si ; j++)cout << " " << tmp[j];
		cout << endl;
	}
	return 0;
}