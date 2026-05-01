#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll sum;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    for(int i=1;i<=sum;i++){
        if(sum%i!=0) continue;
        dfs();
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