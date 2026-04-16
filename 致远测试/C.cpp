#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,k;
ll a[N];
bool win[N];
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }    
    sort(a+1,a+n+1,greater<ll>());
    ll ans=1;win[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i-1]-a[i]<=k&&win[i-1]){
            win[i]=1;
            ans++;
        }
    }
    cout<<ans;
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
