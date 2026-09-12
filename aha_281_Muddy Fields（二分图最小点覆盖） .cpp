#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=50+5;
ll n,m;
char a[N][N];
pair<ll,ll> id[N][N];
vector<ll> g[N];
bool vis[N];
ll res[N];
ll mx=0;
ll dfs(ll x){
	for(auto i:g[x]){
		if(!vis[i]){
			vis[i]=1;
			if(!res[i]||dfs(res[i])){
				res[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    ll idx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*'){
                if(a[i][j-1]=='*') id[i][j].first=id[i][j-1].first;
                else id[i][j].first=++idx;
            }
        }
    }
    mx=idx;
    idx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*'){
                if(a[i-1][j]=='*') id[i][j].second=id[i-1][j].second;
                else id[i][j].second=++idx;
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='*'){
                g[id[i][j].first].push_back(id[i][j].second);
                mx=max(id[i][j].first,mx);
            }
        }
    }
    ll cnt=0;
    for(int i=1;i<=mx;i++){
        memset(vis,0,sizeof(vis));
        cnt+=dfs(i);
    }
    cout<<cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}