
#include <iostream>
using namespace std;
#define ok 0
#define error -1;
class SeqList
{
private:
	int* list;//元素数组
	int maxsize;//最大长度
	int size;//实际长度
public:
	SeqList();
	SeqList(int a[],int n);
	~SeqList();
	int list_size();
	int list_insert(int i, int item);
	int list_del(int i);
	int list_get(int i);
	void list_display();
};
SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}
SeqList::SeqList(int a[],int n)
{
	maxsize = 1000;
	size = n;
	list = new int[maxsize];
	for (int i = 0; i < n; i++)
	{
		list[i] = a[i];
	}
}
SeqList::~SeqList()
{
	delete[]list;
}
int SeqList::list_size()
{
	return size;
}
int SeqList::list_get(int i)
{
	
	if (i<=0 || i>size)
	{
		cout << "error" << endl;
		return 0;
	}
	else
	{ 
	 cout<<list[i-1]<<endl;
	 return 1;
	}
}
int SeqList::list_del(int i)
{
	if (i > size || i <= 0)
	{
		cout << "error" << endl;
		return 0;
	}
	else
	{ 
		for (int j =i-1; j <size; j++)
		{
			list[j] = list[j+1];

		}
		size--;
		return 1;
	}
}
void SeqList::list_display()
{
	cout << size<<" ";
	int i;
	for (i = 0; i < size ; i++)
	{
		cout << list[i] << " ";
	}
	cout << endl;
}
int  SeqList::list_insert(int i, int item)
{
	if (i <= 0 || i > size)
	{
		cout << "error" << endl;
		return 0;
	}
	else
	{
	  for (int j = size; j > i-1; j--)
	  {
		list[j] = list[j - 1];
	 }
	  list[i-1] = item;
    	size+=1;

	return 1;	
	}
}

int main()
{
	int n;
	cin >> n;
	int* p = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	SeqList list(p,n);
	list.list_display();
	//插入1
	int insert_i, insert_item;
	cin >> insert_i >> insert_item;//
	
	if (list.list_insert(insert_i, insert_item))
	{
		list.list_display();
	}
	//插入2
	 cin >> insert_i >> insert_item;//
	
	if (list.list_insert(insert_i, insert_item))
	{
		list.list_display();
	}
	//删除1
	int de_i;
	cin >> de_i ;
	
	if (list.list_del(de_i))
	{
      list.list_display();
	}
	
	//删除2
	cin >> de_i;
	
	if (list.list_del(de_i))
	{
		list.list_display();
	}
	//查找1
	int find;
	cin >> find;
	list.list_get(find);
	//查找2
	cin >> find;
	list.list_get(find);









}
