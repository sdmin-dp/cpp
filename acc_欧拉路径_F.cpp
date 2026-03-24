#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll M;
map<pair<ll,ll>,bool> vis;
vector<pair<ll,ll>> g[N];
map<pair<ll,ll>,set<ll>> id;
ll n;
deque<ll> ans;
bool vs[N];
void dfs(ll x){
    for(auto i:g[x]){
            vis[{x,i.second}]=1;
            vis[{i.second,x}]=1;
            dfs(i.second);
    }
    ans.push_front(x);
}
void solve(){
    while(1){
        ll x,y,w;
        cin>>x>>y;
        if(M==1&&x!=0&&y!=0){
            //初始化
            M=0;
            n=0;
            id.clear();
            for(int i=1;i<=N;i++) g[i].clear();
            ans.clear();
        }
        if(x==0&&y==0){
            M++;
            for(int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
            if(M==2) break;
            //开始计算
            ll b=1;
            ll cnt=0;
            ll cntou=0;
            for(ll i=1;i<=n;i++){
                cnt=g[i].size();
                if(cnt%2){
                    b=i;
                    cntou++;
                }
            }
            if(cntou!=0){
                cout<<"Round trip does not exist.\n";
                continue;
            }
            dfs(b);
            for(auto i:ans) cerr<<i<<" ";
            cerr<<el<<el;
            for(int i=1;i<ans.size();i++){
                ll idx;
                pair<ll,ll> p={ans[i-1],ans[i]};
                for(auto i:id[p]){
                    // cerr<<i<<" ";
                    if(!vs[i]){
                        idx=i;
                        vs[i]=1;
                        break;
                    }
                }
                cout<<idx<<" ";
                // cerr<<el;
            }
            cout<<el;
        }
        else{
            n++;
            cin>>w;
            g[x].push_back({y,w});
            g[y].push_back({x,w});
            id[{x,y}].insert(w);
            id[{y,x}].insert(w);
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