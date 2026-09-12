#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void solve(){
    cin>>n;
    if(n==1){
        printf("I love Luogu!");
    }
    else if(n==2){
        printf("%d %d",2+4,10-2-4);
    }
    else if(n==3){
        printf("%d\n%d\n%d",3,12,2);
    }
    else if(n==4){
        cout<<500.0/3;
    }
    else if(n==5){
        printf("%d",(260+220)/(12+20));
    }
    else if(n==6){

        double c=sqrt(6.0*6.0+9.0*9.0);
        cout<<c;
    }
    else if(n==7){
        ll a=100;
        a+=10;
        cout<<a<<el;
        a-=20;
        cout<<a<<el;
        a=0;
        cout<<a<<el;
    }
    else if(n==8){
        int r=5;
        double pi=3.141593;
        cout<<2*pi*r<<el;
        cout<<r*r*pi<<el;
        cout<<4.0/3*pi*r*r*r<<el;
    }
    else if(n==9){
        cout<<(((1+1)*2+1)*2+1)*2<<el;
    }
    else if(n==10){
        cout<<9<<el;
    }
    else if(n==11){
        cout<<100.0/(8-5)<<el;
    }
    else if(n==12){
        cout<<'M'-'A'+1<<el;
        cout<<char('A'-1+18)<<el;
    }
    else if(n==13){
        int r1=4,r2=10;
        double pi=3.141593;
        double v=4.0/3*pi*r1*r1*r1+4.0/3*pi*r2*r2*r2;
        v=pow(v,1.0/3);
        printf("%.0f",v);

    }
    else if(n==14){
        printf("%d",50);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);//cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}