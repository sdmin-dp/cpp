#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=200+5;
const ll Q=5e4+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll t[N];
ll dis[N][N];
struct node{
    ll id,time;
    ll u,v;
};
bool cmp(node x,node y){
    return x.time<y.time;
}
node query[Q];
ll ans[Q];
void solve(){
    cin>>n>>m;
    memset(dis,0x3f,sizeof(dis));
    for(int i=0;i<n;i++){
        cin>>t[i];
        dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        dis[u][v]=w;
        dis[v][u]=w;
    }
    ll q;
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>query[i].u>>query[i].v>>query[i].time;
        query[i].id=i;
        ans[i]=-1;
    }   
    sort(query+1,query+q+1,cmp);
    ll cur=1;
    for(int k=0;k<n;k++){
        for(int i=cur;i<=q;i++){
            if(query[i].time<t[k]){
                ll ti=query[i].time;
                ll u=query[i].u;
                ll v=query[i].v;
                if(t[u]<t[k]&&t[v]<t[k]&&dis[u][v]!=inf) ans[query[i].id]=dis[u][v];
            }else{
                cur=i;
                break;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // if(t[i]<=t[k]&&t[j]<=t[k]){
                    if(dis[i][k]+dis[j][k]<dis[i][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                // }
            }
        }
    }
    
    for(ll i=cur;i<=q;i++){
        ll ti=query[i].time;
        ll u=query[i].u;
        ll v=query[i].v;
        if(dis[u][v]!=inf) ans[query[i].id]=dis[u][v];
    }
    for(int i=1;i<=q;i++) cout<<ans[i]<<el;
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