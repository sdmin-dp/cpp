#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll a[N];
ll dis[N][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>dis[i][j];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=k;i++){
            if(dis[i][k]==0x3f3f3f3f3f3f3f3f) continue;
            for(int j=k;j<=n;j++){
                if(dis[i][k]+dis[k][j])
            }
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