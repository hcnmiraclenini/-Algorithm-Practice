#include <iostream>
using  namespace std;
int a[10000];
void  quicksort(int left, int right)
{
	//left,right是左闭右开区间
	//low,high是闭区间
	if (left > right ) return;
	int low = left, high = right, center = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= center) high--;
		a[low] = a[high];
		while (low < high && a[low] < center) low++;
		a[high] = a[low];
	}
	a[low] = center;
	cout << a[low] << " " << low << endl;
	quicksort(left, high-1);
	quicksort(high+1, right);
	
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		quicksort(1, n);
		//快速排序 ，输出每趟拍好的数字及位置
		
		//算法的核心内容：任取一个元素为中心，所有比它小的元素一律往前放，所有比它大的元素一律往后放。
		//人对上述形成的子表再重新选择中心元素并依照同样的规则进行递归 ，直到每个子表中的元素只剩下一个
		//选一个元素为中心，设置两个指针，左指针找比中心元素大的，右指针找比中心元素小的。
		//找到后就左右指针所指的元素互换位置，左右指针就继续新一轮的查找

		cout << endl;
		//不同组的测试数据的输出以空行分开
	}
	return 0;
}


