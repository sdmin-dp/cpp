#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll b[N];
bool check(){
    for(int i=1;i<=n;i++){
        if(b[i]!=1){
            return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    if(check()){
        ll ans=min(k,n);
        if(ans%2==1) ans=(ans-1)/2;
        else ans/=2;
        cout<<ans;
    }else{
        sort(b+1,b+n+1);
        cout<<b[2];
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("badge.in","r",stdin);
    freopen("badge.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}