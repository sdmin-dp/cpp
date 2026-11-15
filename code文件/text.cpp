#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,k,w[500005],g[505][505],x,y,a,t,ans;
vector<vector<pair<ll,ll>>> v;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
    memset(g,0x3f,sizeof g);
    v.resize(m+3);
	for(int i=1;i<=m;i++) cin>>w[m];
	for(int i=1;i<=n;i++){
		cin>>k;g[i][i]=0;
		for(int j=1;j<=k;j++)
            cin>>a>>t,v[a].push_back({i,t});
	}
	for(int i=1;i<=m;i++)
        for(auto x:v[i])
            for(auto y:v[i])
                if(x.first!=y.first)
                    g[x.first][y.first]=min(g[x.first][y.first],x.second+y.second);
	for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
	while(q--){
		cin>>x>>y;ans=LLONG_MAX;
		for(auto u:v[x]) for(auto vv:v[y]) ans=min(ans,g[u.first][vv.first]);
		cout<<w[x]+w[y]+ans<<'\n';
	}
	return 0;
}
