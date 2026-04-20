#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
void solve(){
    cin>>n;
    for(int i=1;a[i-1]*2<=n;i++){
        a[i]=a[i-1]*2;
    }
    cout<<n<<"=";
    bool flag=1;
    for(int i=1;i<=n;i++){
        if(n>=a[i]){
            if(flag){cout<<a[i];flag=0;}
            else cout<<'+'<<a[i];
        }
        else{
            return;
        }
    }
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