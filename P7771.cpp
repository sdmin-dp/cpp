#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<pair<ll,ll>> g[N];
ll in[N],out[N];
ll s;
void dfs(ll x){

}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back({y,i});
        in[y]++;
        out[x]++;
    }
    ll cnt1=0,cnt2=0,cnt3=0,id=0,id2=0;
    /*
    cnt1: in-out=1
    cnt2: out-in=1
    cnt3: out=in
      id: 满足out-in=1的一个点的编号
     id2: 一个有边的点的编号
    */
    for(int i=1;i<=n;i++){
        if(g[i].size()>=1) id2=i;
        if(in[i]-out[i]==1) cnt1++;
        else if(out[i]-in[i]==1){
            cnt2++;
            id=i;
        }
        else if(out[i]==in[i]) cnt3++;
    }
    if(cnt1==1&&cnt2==1&&cnt3+cnt2+cnt1==n) s=id;
    else if(cnt1==0&&cnt2==0&&cnt3==n) s=id2;

    for(int i=1;i<=n;i++){
        
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