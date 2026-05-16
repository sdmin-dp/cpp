#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
ll dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll cnt=0;
            for(int k=0;k<4;k++){
                ll xx=i+dx[k],yy=j+dy[k];
                if(xx>=1&&xx<=n&&yy>=1&&yy<=m) cnt++;
            }
            cout<<cnt<<" ";
        }
        cout<<el;
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