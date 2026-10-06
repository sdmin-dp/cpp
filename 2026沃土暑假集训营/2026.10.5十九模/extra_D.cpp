#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=3000+5;
ll n,m,q,b;
ll d[N][N];
void solve(){
    cin>>n>>m>>q>>b;
    for(int i=1;i<=q;i++){
        ll x,y,r,w;
        cin>>x>>y>>r>>w;
        ll u=x+y,v=x-y+m;
        ll u1=max(1ll,u-r),u2=min(u+r,N-5);
        ll v1=max(1ll,v-r),v2=min(v+r,N-5);
        d[u1][v1]+=w;
        d[u2+1][v1]-=w;
        d[u1][v2+1]-=w;
        d[u2+1][v2+1]+=w;
    }
    for(ll i=1;i<=N-5;i++){
        for(ll j=1;j<=N-5;j++){
            d[i][j]=d[i-1][j]+d[i][j-1]-d[i-1][j-1]+d[i][j];
        }
    }
    vector<ll> srt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll x=i,y=j;
            ll u=x+y,v=x-y+m;
            srt.push_back(d[u][v]);
        }
    }
    sort(srt.begin(),srt.end(),greater<ll>());
    ll k=srt[b-1];
    ll ans=0;
    ll ansx=-1,ansy=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll x=i,y=j;
            ll u=x+y,v=x-y+m;
            if(d[u][v]>=k){
                ans++;
                if(ansx==-1){
                    ansx=i;
                    ansy=j;
                }
            }
        }
    }
    cout<<k<<" "<<ans<<" "<<ansx<<" "<<ansy<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}