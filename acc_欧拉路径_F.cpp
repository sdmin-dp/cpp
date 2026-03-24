#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll cnt=0;
ll a[N][N];
map<pair<ll,ll>,ll> id;
void solve(){
    while(1){
        ll x,y,w;
        cin>>x>>y;
        if(cnt==1&&x!=0&&y!=0){
            //初始化
        }
        if(x==0&&y==0){
            cnt++;
            if(cnt==2) break;
            //开始计算
            
        }
        cin>>w;
        a[x][y]++;
        a[y][x]++;
        id[{x,y}]=w;
        id[{y,x}]=w;
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