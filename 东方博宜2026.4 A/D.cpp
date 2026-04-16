#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
const ll mod=11;
string s;
bool f1=0,f2=0;
bool isrunnian(ll a){
    return ((a%4==0&&a%100!=0)||(a%400==0));
}
void solve(){
    cin>>s;
    f1=0,f2=0;
    ll sum=0;
    for(ll i=0;i<=s.size()-1;i++){
        ll x=0;
        if(s[i]=='X') x=10;
        else x=s[i]-48;
        sum+=(x*(1<<(18-i-1)))%mod;
        // cout<<x;
    }
    if(sum%mod==1) f1=1;
    // cout<<el;
    // cout<<sum%mod<<" ";
    ll y=0,m=0,d=0;
    for(int i=6;i<=9;i++) y=y*10+(s[i]-48);
    for(int i=10;i<=11;i++) m=m*10+(s[i]-48);
    for(int i=12;i<=13;i++) d=d*10+(s[i]-48);
    // cout<<y<<" "<<m<<" "<<d<<el;
    if(y==2025){
        if(m==5){
            if(d>=1&&d<=10){
                f2=1;
            }
        }else if(m<5){
            if(m==1||m==3){
                if(d>=1&&d<=31){
                    f2=1;
                }
            }else if(m==2){
                if(isrunnian(y)){
                    if(d>=1&&d<=29) f2=1;
                }else if(!isrunnian(y)){
                    if(d>=1&&d<=28) f2=1;
                }
            }else if(m==4){
                if(d>=1&&d<=30) f2=1;
            }
        }
    }else if(y>=1900&&y<2025){
        if(m>=1&&m<=12){
            if(m==1||m==3||m==5||m==7||m==8||m==10||m==12){
                if(d>=1&&d<=31){
                    f2=1;
                }
            }else if(m==2){
                if(isrunnian(y)){
                    if(d>=1&&d<=29) f2=1;
                }else if(!isrunnian(y)){
                    if(d>=1&&d<=28) f2=1;
                }
            }else if(m==4){
                if(d>=1&&d<=30) f2=1;
            }
        }
    }
    if(f1&&f2) cout<<"PASS\n";
    else cout<<"FAIL\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}