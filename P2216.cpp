#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=100+5;
const ll mxlog=8;
ll n,m,k;
ll a[N][N];
pair<ll,ll> st[N][N][11][11];
ll lg2[N];
void init(){
    for(int i=2;i<N;i++) lg2[i]=lg2[i/2]+1;
    for(int i=1;i<=n;i++) for(ll j=1;j<=m;j++) st[i][j][0][0]={a[i][j],a[i][j]};
    for(int i=1;i<=n;i++){
        for(int k=1;k<=mxlog;k++){
            for(int j=1;j+(1<<k-1)-1<=m;j++){
                st[i][j][0][k]={max(st[i][j+(1<<k-1)][0][k-1].first,st[i][j][0][k-1].first),min(st[i][j+(1<<k-1)][0][k-1].second,st[i][j][0][k-1].second)};
            }
        }
    }
    for(int j=1;j<=m;j++){
        for(int k=1;k<=mxlog;k++){
            for(int i=1;i+(1<<k-1)-1<=n;i++){
                st[i][j][k][0]={max(st[i+(1<<k-1)][j][k-1][0].first,st[i][j][k-1][0].first),min(st[i+(1<<k-1)][j][k-1][0].second,st[i][j][k-1][0].second)};
            }
        }
    }
    for(int k=1;k<=mxlog;k++){
        for(int l=1;l<=mxlog;l++){
            for(int i=1;i+(1<<k-1)-1<=n;i++){
                for(int j=1;j+(1<<l-1)-1<=m;j++){
                    st[i][j][k][l]={max({
                        st[i][j][k-1][l-1].first,
                        st[i][j+(1<<l-1)][k-1][l-1].first,
                        st[i+(1<<k-1)][j][k-1][l-1].first,
                        st[i+(1<<k-1)][j+(1<<l-1)][k-1][l-1].first
                    }),min({
                        st[i][j][k-1][l-1].second,
                        st[i][j+(1<<l-1)][k-1][l-1].second,
                        st[i+(1<<k-1)][j][k-1][l-1].second,
                        st[i+(1<<k-1)][j+(1<<l-1)][k-1][l-1].second
                    })};
                }
            }
        }
    }
}
ll query(ll x1,ll y1,ll x2,ll y2){
    ll k1=lg2[x2-x1+1];
    ll k2=lg2[y2-y1+1];
    return max({
        st[x1][y1][k1][k2],
        st[x2-(1<<k1)+1][y1][k1][k2],
        st[x1][y2-(1<<k2)+1][k1][k2],
        st[x2-(1<<k1)+1][y2-(1<<k2)+1][k1][k2]
    });
}
void solve(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    init();
    ll ans=10000;
    for(int i=1;i+k-1<=n;i++){
        for(int j=1;j+k-1<=m;i++){
            ll x1=i,y1=j,x2=i+k-1,y2=j+k-1;
            cout<<query(x1,y1,x2,y2)<<el;
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