#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e2+5;
ll n;
bool dis[N][N];
ll f[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++){
        while(1){
            ll x;
            cin>>x;
            if(x==0) break;
            dis[i][x]=1;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=dis[i][j]||(dis[i][k]&&dis[k][j]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]){
                f[j]=f[i];
            }
        }
    }
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(f[i]==i){
            cnt++;
        }
    }
    cout<<cnt;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}