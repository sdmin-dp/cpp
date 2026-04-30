#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e6+5;
const ll mxlog=20;
ll n;
ll st[N][mxlog];
void init(){
    for(int i=1;i<=mxlog;i++){
        for(int j=1;j+(1<<i)<=n;j++){
            st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st[i][0];
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