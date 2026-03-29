#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n,m;
vector<ll> g[N];
ll in[N],out[N];
ll idx[N];
ll s;
deque<ll> ans;
void dfs(ll x){
    while(idx[x]<g[x].size()){
        ll i=g[x][idx[x]];
        idx[x]++;
        dfs(i);
    }
    ans.push_front(x);
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].push_back(y);
        in[y]++;
        out[x]++;
    }
    ll cnt1=0,cnt2=0,cnt3=0,id=0,id2=1e9+7;
    for(int i=1;i<=n;i++){
        if(g[i].size()>=1&&i<id2) id2=i;
        if(in[i]-out[i]==1) cnt1++;
        else if(out[i]-in[i]==1){
            cnt2++;
            id=i;
        }
        else if(out[i]==in[i]) cnt3++;
    }
    if(cnt1==1&&cnt2==1&&cnt3+cnt2+cnt1==n) s=id;
    else if(cnt1==0&&cnt2==0&&cnt3==n) s=id2;
    else{
        cout<<"No";
        return;
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }
    cerr<<s;
    dfs(s);
    for(auto i:ans) cout<<i<<" ";
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