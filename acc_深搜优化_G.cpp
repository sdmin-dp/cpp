#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=50+5;
ll n;
ll a[N],sum,ans=1e12;
ll sz[N];
bool vis[N];
bool dfs(ll num,ll len,ll x){
    if(x==n+1){
        // for(int j=1;j<=num;j++) cerr<<sz[j]<<" "; 
        // cerr<<el;
        for(int i=1;i<=num;i++){
            if(sz[i]!=len){
                return 0;
            }
        }
        ans=min(ans,len);
        return 1;
    }
    for(int i=1;i<=num;i++){
        if(!vis[i]&&sz[i]+a[x]<=len){
            vis[x]=1;
            sz[i]+=a[x];
            bool f=dfs(num,len,x+1);
            if(f) return 1;
            // if(sz[i]==a[x]&&!f) return 0;
            sz[i]-=a[x];
            vis[x]=0;
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+n+1,greater<ll>());
    for(int i=n;i>=1;i--){
        memset(sz,0,sizeof(sz));
        if(sum%i!=0) continue;
        ll len=sum/i;
        // cerr<<len<<el;
        if(dfs(i,len,1)) break;        
        // cerr<<el;
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