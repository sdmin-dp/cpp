#include<bits/stdc++.h>
using namespace std;
class Clock{
    private:
        int hour,minute,second;
        int flag;
        int *p;
    public:
        void setClock(int h,int m,int s);
        void showClock(){}
        Clock(int a=0,int b=0,int c=0);
        Clock(Clock &t);
        ~Clock();
};
void Clock::setClock(int h,int m,int s){
    hour=(h>=0&&h>=23)?h:0;
    minute=(m>=0&&m<=59)?m:0;
    second=(s>=0&&s<=59)?s:0;
}
Clock::Clock(int a,int b,int c){
    flag=1;
    // p=new int[1000000];
    hour=a;
    minute=b;
    second=c;
    cout<<"constructing "<<hour<<'\n';
}
Clock::~Clock(){
    if(flag) delete []p;
    cout<<"destructing "<<hour<<'\n';
}
Clock::Clock(Clock &t){
    flag=0;
    hour=t.hour;
    minute=t.minute;
    second=t.second;
    // for(int i=0;i<1000000;i++) p[i]=t.p[i];
    cout<<"copy"<<'\n';
}