#include <iostream>
#include<list>
using namespace std;

list<int> mylist;
void print()
{
    list<int>::iterator ite;
    for (ite = mylist.begin(); ite != mylist.end(); ite++) cout << *ite << " ";
    cout << endl;
}
int main()
{
    int n,number;
  
    int pos=0;
    auto it = mylist.begin();
    //list<int>::iterator it;
    cin >> n;
    int len = n;
    while (n--)
    {
        cin >> number;
        mylist.push_back(number);
    }
    print();

    //插入
  for(int i=0;i<2;i++)
  { 
    cin >> pos >> number;
    it = mylist.begin();
    if (pos<=0 || pos>len+1)
        cout << "error" << endl;
    else
    { 
      pos -= 1;
      while(pos--)
     { 
       ++it;
     }
     mylist.insert(it,number);
     len++;
     print();
    }
   }
   //删除
  for (int i = 0; i < 2; i++)
  {
      it = mylist.begin();
      cin >> pos;
      if (pos<=0 || pos>len)
          cout << "error" << endl;
      else
      {
          pos -= 1;
          while (pos--)
          {
              ++it;
          }
          mylist.erase(it);
          len--;
          print();
      }
  }
   //查找
  for (int i = 0; i < 2; i++)
  {
      it = mylist.begin();
      cin >> pos;
      if (pos<=0 || pos>len)
          cout << "error" << endl;
      else
      {

          pos -= 1;
          while (pos--)
          {
              ++it;
          }
          cout << *it << endl;
      }
  }
  //mylist.~list();
    return 0;
}
