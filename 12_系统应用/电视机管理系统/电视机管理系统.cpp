#include <iostream>
using namespace std;
class TV
{
    int no;//几号电视机
    int volume;//音量
    int mode;//模式
    int channelno;//频道号
    int change;//改变的音量
    static int tvnumber;//播放电视的电视机数
    static int dvdnumber;//播放DVD的电视机数量
public:
    TV(){
        volume = 50;
        mode = 1;
        tvnumber++;
        no = tvnumber;

    };
    void print();
    static void gettvnumber();
    static void getdvdnumber();
    friend void opera(TV* s, int nu, int mo, int ch, int channo);
   
     //参数列表：电视机对象、编号、模式、变化音量、频道号

};
int TV::tvnumber = 0;
int TV::dvdnumber = 0;

void TV::gettvnumber()
{
    cout << "播放电视的电视机数量为" << TV::tvnumber<<endl;

}
void TV::getdvdnumber()
{
    cout << "播放DVD的电视机数量为" << TV::dvdnumber<<endl;
}
void TV::print()
{
    if (mode == 1)
    {
        cout << "第" << no << "号电视机--TV模式--频道" << channelno << "--音量" << volume<<endl;
    }
    else if (mode == 2)
    {
        cout << "第" << no << "号电视机--DVD模式--频道" << channelno << "--音量" << volume << endl;
    }
    
}

void opera(TV *s,int nu, int mo, int ch, int channo)
{
    s->no = nu;
    
    if (s->mode==1&&mo == 2)
    {
        s->mode = mo;
        s->channelno = 99;
        TV::tvnumber--;
        TV::dvdnumber++;
    }
    else if (s->mode==2&&mo == 1)
    {
        s->mode = mo;
        s->channelno = channo;
        TV::tvnumber++;
        TV::dvdnumber--;
    }
    /*else if (s.mode == 2 && mo == 2)
    {
        s.channelno = 99;
    }*/
    else if (s->mode == 1 && mo == 1)
    {
        s->channelno = channo;
    }

    s->volume += ch;
    if (s->volume <0)
    {
        s->volume =0;

    }
    else if(s->volume > 100)
    {
        s->volume = 100;
    }
    
    s->print();
    
}
int main()
{
   
    TV* p = NULL;
    int n;
    cin >> n;
    p = new TV[n];
    //TV::gettvnumber();
    int t,i;
    cin >> t;
    int number, mode, channelno, change;// 电视机编号、模式、频道号 变化音量
    for(i=0;i<t;i++)
    {
        cin >> number >> mode >> channelno >> change;
        
       opera(&p[number-1],number, mode, change, channelno);//电视机对象、编号、模式、变化音量、频道号
    }
    TV::gettvnumber();
    TV::getdvdnumber();
}

