#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=5e5+5;
ll n,m,q;
//地铁线路数、地铁站数、以及出行计划数
ll a[N][25],t[N][25],w[N];
//其中aij表示第i条线路经过的第j个地铁站,tij表示从该地铁站的站厅走到第i条线路的站台需要的时间
void solve(){
    cin>>n>>n>>m>>q>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
        ll k;cin>>k;
        for(int j=1;j<=k;j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    
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