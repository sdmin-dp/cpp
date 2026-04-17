#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll a[N];
ll dis[N][N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll x;cin>>x;
            if(x!=0) dis[i][j]=x;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(dis[i][k]==0x3f3f3f3f3f3f3f3f) continue;
            for(int j=1;j<=n;j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]) dis[i][j]=dis[i][k]+dis[k][j];
            }
        }
    }=
    ll sum=0;
    for(int i=2;i<=m;i++){
        sum+=dis[a[i-1]][a[i]];
    }
    cout<<sum;
    
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