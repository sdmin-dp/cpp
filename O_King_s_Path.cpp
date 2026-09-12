#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll dx[]={1,1,1,0,0,-1,-1,-1},dy[]={1,0,-1,1,-1,1,0,-1};
ll x0,y0,x1,y1;
ll n;
map<pair<ll,ll>,ll> mp;
void solve(){
    cin>>x0>>y0>>x1>>y1;
    cin>>n;
    for(int i=1;i<=n;i++){
        ll r,a,b;cin>>r>>a>>b;
        for(ll j=a;j<=b;j++){
            mp[{r,j}]=-1;
        }
    }
    queue<pair<ll,ll>> q;
    q.push({x0,y0});
    mp[{x0,y0}]=0;
    while(!q.empty()){
        ll x=q.front().first,y=q.front().second;
        q.pop();
        if(x==x1&&y==y1) break;
        for(int i=0;i<8;i++){
            ll xx=x+dx[i],yy=y+dy[i];
            if(mp.count({xx,yy})&&mp[{xx,yy}]==-1){
                mp[{xx,yy}]=mp[{x,y}]+1;
                q.push({xx,yy});
            }
        }
    }
    if(mp.count({x1,y1})&&mp[{x1,y1}]!=-1) cout<<mp[{x1,y1}]<<el;
    else cout<<-1<<el;
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
