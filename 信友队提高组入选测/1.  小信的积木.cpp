#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
int k,n,s[10];
map<pair<vector<int>,int>,ll> memo;
ll dfs(vector<int> v,int cur){
    if(cur>n){
        for(int i=0;i<k;i++)if(v[i]!=s[i+1])return 0;
        return 1;
    }
    if(memo.count({v,cur}))return memo[{v,cur}];
    ll res=0;
    auto fill=[&](auto self,int r,vector<int> cv){
        if(r==k){res+=dfs(cv,cur+1);return;}
        int lim=s[r+1];
        if(r>0)lim=min(lim,v[r-1]);
        for(int x=0;x<=lim-v[r];x++){
            if(r>0&&v[r]+x>cv[r-1])break;
            vector<int> nv=cv;
            nv[r]+=x;
            self(self,r+1,nv);
        }
    };
    fill(fill,0,v);
    return memo[{v,cur}]=res;
}
void solve(){
    cin>>k;
    for(int i=1;i<=k;i++)cin>>s[i];
    cin>>n;
    vector<int> v(k,0);
    cout<<dfs(v,1)<<el;
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
