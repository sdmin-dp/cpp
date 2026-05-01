#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
ll a[N];
ll sum;
bool vis[N];
void dfs(ll le,ll len,ll tar,ll cur){
    if(le==0){
        cout<<tar;
        exit(0);
    }
    if(len==tar){
        dfs(le-1,0,tar,1);
        return;
    }
    ll last=0;
    for(int i=cur;i<=n;i++){
        if(a[i]==last) continue;
        if(vis[i]) continue;
        if(len+a[i]>tar) continue;
        vis[i]=1;
        dfs(le,len+a[i],tar,i+1);
        vis[i]=0;
        if(len==0||len+a[i]==tar) return; 
        last=a[i];
        // while(a[i]==last) i++;
        // i--;
    }
}
void solve(){
    cin>>n;
    ll mx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        mx=max(a[i],mx);
    }
    sort(a+1,a+n+1,greater<ll>());
    for(int i=mx;i<=sum;i++){
        if(sum%i!=0) continue;
        dfs(sum/i,0,i,1);
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