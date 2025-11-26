#include <iostream>
#include<list>
using namespace std;
list<int>myl;
void swap(int pa, int pb)
{
	list<int>::iterator ita;
	ita = myl.begin();
	for (int i = 0; i < (pa - 1); i++, ita++);

	list<int>::iterator itb;
	itb = myl.begin();
	for (int i = 0; i < (pb - 1); i++, itb++);
	int temp = *ita;
	*ita = *itb;
	*itb = temp;
}


void print()
{
	list<int>::iterator it;

	for (it = myl.begin(); it != myl.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	int n, number;
	cin >> n;

	int pos1, pos2;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		myl.push_back(number);
	}
	print();
	//交换
	for (int i = 0; i < 2; i++)
	{
		cin >> pos1 >> pos2;
		int  len = myl.size();
		if (pos1<0 || pos1>len || pos2<0 || pos2>len)
		{
			cout << "error" << endl;

		}
		else
		{
			swap(pos1, pos2);
			print();
		}

	}
	myl.clear();
	return 0;
}

