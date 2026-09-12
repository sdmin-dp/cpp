#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e3+5;
ll n,m;
bool g[N][N];
bool vis[N];
ll a[N];
ll v;
ll res[N];
ll in[N];
ll ans=0;
void topsort(){
    queue<ll> q;
    for(int i=1;i<v;i++) if(!in[i]) q.push(i);
    while(!q.empty()){
        ll t=q.front();
        q.pop();
        for(int i=1;i<v;i++){
            if(g[t][i]){
                if(i>n) res[i]=max(res[i],res[t]);
                else res[i]=max(res[i],res[t]+1);
                if(--in[i]==0){
                    q.push(i);          
                }
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    v=n+1;
    for(int i=1;i<=m;i++){
        memset(vis,0,sizeof(vis));
        ll sum;
        cin>>sum;
        for(int i=1;i<=sum;i++){
            cin>>a[i];
            vis[a[i]]=1;
        }
        // for(int i=a[1];i<=a[sum];i++){
        //     if(vis[i]){
        //         if(!g[v][i]){
        //             g[v][i]=1,in[i]++;
        //         }
        //     }
        //     else{
        //         if(!g[i][v]){
        //             g[i][v]=1,in[v]++;
        //         }
        //     }
        // }
        // v++;
        for(int i=a[1];i<=a[sum];i++){
            if(vis[i]){
                for(int j=a[1];j<=a[sum];j++){
                    if(!vis[j]&&g[j][i]==0){
                        g[j][i]=1;
                        in[i]++;
                    }
                }
            }
        }
    }
    topsort();
    for(int i=1;i<=n;i++) ans=max(ans,res[i]+1);
    cout<<ans;
}
int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}