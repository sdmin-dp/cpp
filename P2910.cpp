#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e2+5;
const ll inf=1e18;
ll n,m;
ll dis[N][N];
ll a[10005];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>dis[i][j];
    
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(dis[i][k]+dis[k][j]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[k][j];
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<dis[i][j]<<" ";
    //     }
    //     cout<<el;
    // }
    ll sum=0;
    ll last=1;
    for(int i=1;i<=m;i++){
        sum+=dis[last][a[i]];
        last=a[i];
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