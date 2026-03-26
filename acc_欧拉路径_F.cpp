#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll M;
bool vis[N];
vector<pair<ll,ll>> g[55];
map<pair<ll,ll>,set<ll>> id;
ll n;
deque<ll> ans;
bool vs[N];
void dfs(ll x){
    for(auto i:g[x]){
        if(!vis[i.first]){
            vis[i.first]=1;
            dfs(i.second);
        }
    }
    ans.push_front(x);
}
void solve(){
    while(1){
        ll x,y,w;
        cin>>x>>y;
        if(M==1&&x!=0&&y!=0){
            M=0;
            id.clear();
            for(int i=1;i<=50;i++) g[i].clear();
            ans.clear();
            n=0;
        }
        if(x==0&&y==0){
            M++;
            for(int i=1;i<=min(n,50ll);i++) sort(g[i].begin(),g[i].end());
            // if(M==2) break;
            // ll b=1;
            // ll cnt=0;
            // ll cntou=0;
            // for(ll i=1;i<=n;i++){
            //     cnt=g[i].size();
            //     if(cnt%2){
            //         cntou++;
            //     }
            // }
            // if(cntou!=0){
            //     cout<<"Round trip does not exist.\n";
            //     continue;
            // }
            // dfs(b);
            // // cerr<<el<<el;
            // for(int i=1;i<ans.size();i++){
            //     ll idx;
            //     pair<ll,ll> p={ans[i-1],ans[i]};
            //     for(auto i:id[p]){
            //             idx=i;
            //             break;
            //     }
            //     cout<<idx<<" ";
            // }
            // cout<<el;
        }
        else{
            n++;
            cin>>w;
            g[x].push_back({w,y});
            g[y].push_back({w,x});
            if(x>y) swap(x,y);
            id[{x,y}].insert(w);
            // id[{y,x}].insert(w);
        }
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