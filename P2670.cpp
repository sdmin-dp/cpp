#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
char a[N][N];
ll ans[N][N];
ll dx[]={0,1,0,-1,1,1,-1,-1}, dy[]={1,0,-1,0,-1,1,-1,1};
void solve(){
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            cin>>a[i][j];
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=n;j++)
            if(a[i][j]=='*')
                for(int i=0;i<8;i++){
                    ll xx=dx[i],yy=dy[i];
                    if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&a[xx][yy]!='*')
                        ans[xx][yy]++;     
                }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(a[i][j]=='*') cout<<'*';
            else cout<<ans[i][j];
        }
        cout<<el;
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