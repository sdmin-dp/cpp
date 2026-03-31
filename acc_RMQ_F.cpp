#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=250+5;
const ll mxlog=8;
ll n,m,q;
ll a[N][N];
ll st[N][N][10][10];
void init(){
    for(int i=1;i<=n;i++) for(ll j=1;j<=m;j++) st[i][j][0][0]=a[i][j];
    
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j]; 
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