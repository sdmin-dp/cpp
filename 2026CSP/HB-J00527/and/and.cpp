#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
ll n,m;
ll a[N];
ll ans=0;
bool checkA(){
    for(int i=1;i<=n;i++){
        if(a[i]>4){
            return 0;
        }
    }
    return 1;
}
void dfs(ll x,ll cnt,ll sum){
    if(cnt==m){
        ans=max(ans,sum);
        return;
    }
    if(x==n+1) return;
    dfs(x+1,cnt,sum);
    if(cnt==0){
        dfs(x+1,cnt+1,a[x]);
    }else{
        dfs(x+1,cnt+1,sum&a[x]);
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(1,0,0);
        cout<<ans;
    }else if(m==1){
        sort(a+1,a+n+1,greater<ll>());
        cout<<a[1];
    }else if(m==2&&n<=2000){
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(a[i]&a[j]));
            }
        }
        cout<<ans;
    }else if(m==n){
        ll ans=a[1];
        for(int i=2;i<=n;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }else if(checkA()){
        sort(a+1,a+n+1,greater<ll>());
        ll ans=a[1];
        for(int i=2;i<=m;i++){
            ans=(ans&a[i]);
        }
    }else{
        sort(a+1,a+n+1,greater<ll>());
        ll ans=a[1];
        for(int i=2;i<=m;i++){
            ans=(ans&a[i]);
        }
        cout<<ans;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}