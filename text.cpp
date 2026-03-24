#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=2e3+5;
ll M;
ll n,a[50][50],deg[50];
map<pair<ll,ll>,set<ll>> id;
vector<ll> ans;
bool vis[N];
void dfs(ll x){
    for(int i=1;i<=n;i++){
        if(a[x][i]){
            for(auto it=id[{x,i}].begin();it!=id[{x,i}].end();){
                ll w=*it;
                if(!vis[w]){
                    vis[w]=1;
                    a[x][i]--;a[i][x]--;
                    id[{x,i}].erase(it);id[{i,x}].erase(w);
                    dfs(i);
                    ans.push_back(w);
                    it=id[{x,i}].begin();
                }else it++;
            }
        }
    }
}
void solve(){
    ll x,y,w,st=0;
    while(1){
        cin>>x>>y;
        if(M==1&&x!=0&&y!=0){
            M=0;n=0;st=0;
            id.clear();ans.clear();
            memset(a,0,sizeof(a));
            memset(deg,0,sizeof(deg));
            memset(vis,0,sizeof(vis));
        }
        if(x==0&&y==0){
            M++;if(M==2)break;
            ll cntou=0;
            for(int i=1;i<=n;i++)if(deg[i]%2)cntou++;
            if(cntou!=0){
                cout<<"Round trip does not exist.\n";
                continue;
            }
            dfs(st);
            for(int i=ans.size()-1;i>=0;i--) cout<<ans[i]<<(i==0?"":" ");
            cout<<el;
        }else{
            cin>>w;
            if(!st)st=min(x,y);
            n=max({n,x,y});
            a[x][y]++;a[y][x]++;
            deg[x]++;deg[y]++;
            id[{x,y}].insert(w);id[{y,x}].insert(w);
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
