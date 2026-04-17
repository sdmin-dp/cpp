#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e5+5;
const ll mod=10007;
ll n;
vector<ll> g[N];
ll w[N];
ll sum[N],mx[N];
ll ans,res;//ans->max ans ,res->sum
void dfs(ll x,ll fa){
    for(auto i:g[x]){
        if(i!=fa){
            dfs(i,x);
            sum[x]=(sum[x]+w[i])%mod;
            mx[i]=max(mx[i],w[i]);
        }
    }
}
void dfs2(ll x,ll fa){
    ll m1=0,m2=0;
    for(auto i:g[x]){
        if(w[i]>=m1){
            m2=m1;
            m1=w[i];
        }else{
            m2=max(m2,w[i]);
        }
    }
    ans=max(ans,mx[fa]*w[x]);
    res=(res+sum[fa]*w[x]%mod)%mod;
    for(auto i:g[x]){
        if(i==fa) continue;
        ll sumx=sum[x],mxx=mx[x],sumi=sum[i],mxi=mx[i];
        sum[x]-=w[i];
        sum[i]+=w[x];
        mx[x]=m1;
        if(w[i]==m1){
            mx[x]==m2;
        }
        mx[i]=max(mx[i],w[x]);
        dfs2(i,x);
        sum[x]=sumx;mx[x]=mxx;sum[i]=sumi;mxi=mx[i];
        ans=max(ans,mx[i]*w[x]);
        res=(res+sum[i]*w[x]%mod)%mod;
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++) cin>>w[i];
    dfs(1,0);dfs2(1,0);
    cout<<ans<<" "<<res;
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