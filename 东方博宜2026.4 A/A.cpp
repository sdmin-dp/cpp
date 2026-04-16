#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll a;
bool f1=0,f2=0;
void solve(){
    cin>>a;
    if(a/100>=0&&a/100<=99&&a%100>=1&&a%100<=12) f1=1;
    if(a/100>=1&&a/100<=12&&a%100>=0&&a%100<=99) f2=1;
    if(f1&&!f2) cout<<"YYMM";
    if(!f1&&f2) cout<<"MMYY";
    if(f1&&f2) cout<<"YYMM";
    if(!f1&&!f2) cout<<"YYMM";
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}