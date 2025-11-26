#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1100;
 //树结点有26个指针，指向单词的下一字母结点。兄弟节点按词典序排序
class Node
{
public:
	int cnt;//记录有多少次到达这个结点
	int  nex[26];//单词下一个字母
};
Node tr[maxn];
int tp;
char buf[11];
char word[11];
int n;
//将单词的每个字母逐一插进Trie树中。
//插入前先看该字母对应的结点是否已经存在，若存在共享结点，则不用创建对应的结点
//若不存在，就需要创建一个新结点。最后，我们在最后一个字母结点进行标记
void Insert(int now, char* b)
{
	tr[now].cnt++; 
	if (!*b) return;
	if (!tr[now].nex[*b - 'a'])
		tr[now].nex[*b - 'a'] = tp++;
	Insert(tr[now].nex[*b - 'a'], b + 1);
}
//统计以输入字符串为前缀的单词个数
int search(int now, char* b)
{
	int nex = tr[now].nex[*b - 'a'];
	if (!*b) return tr[now].cnt;
	if (!nex)  return 0;
	return search(nex, b + 1);
}
//定义层次遍历函数
void LevelOrder()
{

	queue <char> tq;
	tq.push(0);
	while (!tq.empty())
	{
		int n = tq.size();
		while (n--)
		{
			int temp = tq.front();
			tq.pop();
			for (int i = 0; i < 26; i++)
			{
				if (tr[temp].nex[i])
				{
					cout << char( i+'a');
					tq.push(tr[temp].nex[i]);
				}
			}
		}
	}
   }
	

int main()
{
	memset(tr, NULL, sizeof(tr));
	tp = 1;
	int t;

	while (1)
	{

		cin >> buf;
		if (buf[0] >= '0' && buf[0] <= '9')
		{
			t = buf[0] - '0';
			break;
		}
		Insert(0, buf);
	}
	
	LevelOrder();

	cout << endl;
	//cout << t << "!" << endl;
	while (t--)
	{
		cin >> word;
		//cout << word << endl;
		cout << search(0, word) << endl;
	}
	return 0;


}
       