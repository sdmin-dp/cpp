#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
ll n;
int g[N*32][2],cnt[N*32];
ll idx,ans;
string s[N];
bitset<32>bs;
void insert(string &s){
    int p=0;
    for(auto i:s){
        ll x=i-'0';
        if(!g[p][x]) g[p][x]=++idx;
        p=g[p][x];
    }
    cnt[p]++;
}
ll find(string &s){
    ll p=0,res=0;
    for(auto i:s){
        bool x=i-'0';
        if(g[p][!x]) res=res*2+1,p=g[p][!x];
        else res*=2,p=g[p][x]; 
    }
    return res;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;
        cin>>x;
        bs=x;
        s[i]=bs.to_string();
        insert(s[i]);
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,find(s[i]));
    }
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