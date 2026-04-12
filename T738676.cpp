#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n;
ll a[N];
bool ishuiwen(ll x){
    ll k=x;
    ll y=0;
    do{
        y=y*10+x%10;
        x/=10;
    }while(x);
    return (k==y);
}
void solve(){
    cin>>n;
    for(ll i=0;i<=log2(n)+5;i++){
        if(a[i]>n) break;
        if(ishuiwen(n-a[i])){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    a[0]=1;
    for(ll i=1;i<=62;i++){
        a[i]=a[i-1]*2;
    }
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}