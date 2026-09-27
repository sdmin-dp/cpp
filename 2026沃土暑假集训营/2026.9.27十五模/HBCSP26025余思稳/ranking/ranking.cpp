#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e2+5;
ll n,m;
ll d[N],ans[N];
map<string,ll> id;
vector<ll> g[N];
void solve(){
    cin>>n>>m;
    vector<int>d(m+2,0),ans(m+2,0);
    map<string,int>id;
    for(int i=1;i<=m;i++){
        string s;
        cin>>s;
        id[s]=i;
    }
    vector<vector<int>>e(m+2);
    for(int i=1;i<=n;i++){
        vector<string>s(m+2);
        ll st=0;
        for(int j=1;j<=m;j++) cin>>s[j];
        for(int j=1;j<=m;j++){
            if(j==1) continue;
            if(s[j-1]>s[j]){
                for(ll u=st+1;u<=j-1;u++){
                    for(ll v=j;v<=m;v++){
                        g[id[s[u]]].push_back(id[s[v]]);
                        d[id[s[v]]]++;
                    }
                }
                st=j-1;
            }
        }
    }
    queue<int>q;
    for(int i=1;i<=m;i++){
        if(d[i]==0){
            ans[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(auto v:g[u]){
            d[v]--;
            if(d[v]==0){
                ans[v]=ans[u]+1;
                q.push(v);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(i==j) cout<<"-";
            else{
                if(ans[i]>ans[j]) cout<<1;
                else if(ans[i]<ans[j]) cout<<0;
                else cout<<"?";
            }
        }
        cout<<'\n';
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