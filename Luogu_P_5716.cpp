#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
bool isrennian(ll year){
    if((year%4==0&&year%100!=0)||year%400==0) return 1;
    else return 0;
}
ll a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void solve(){
    cin>>n>>m;
    if(m==2){
        if(isrennian(n)){
            cout<<29<<el;
        }
        else{
            cout<<28<<el;
        }
    }
    else{
        cout<<a[m]<<el;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}