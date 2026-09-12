#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=500+5;
ll m,n;
ll a[N][N];
deque<ll> ans;
void dfs(ll x){
    for(int i=1;i<=n;i++){
        if(a[x][i]){
            a[x][i]--;
            a[i][x]--;
            dfs(i);
        }
    }
    ans.push_front(x);
}
void solve(){
    cin>>m;
    for(int i=1;i<=m;i++){
        ll x,y;
        cin>>x>>y;
        a[x][y]++;
        a[y][x]++;
        n=max({n,x,y});
    }
    ll b=1;
    ll cnt=0;
    for(int i=1;i<=n;i++){
        cnt=0;
        for(int j=1;j<=n;j++) cnt+=a[i][j];
        if(cnt%2){
            b=i;
            break;
        }
    }
    dfs(b);
    for(auto i:ans) cout<<i<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    while(T--){
        solve();
    }
    return 0;
}