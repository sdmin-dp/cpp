#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=4e5+5;
ll a[N],g[N*30][2],b[N],c[N],d[N],e[N],ans,idx,n;
bitset<32> bs;
void insert(string &s){
    ll p=0;
    for(auto i:s){
        bool x=i-'0';
        if(!g[p][x]) g[p][x]=++idx;
        p=g[p][x];
    }
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
        cin>>a[i];
        b[i]=b[i-1]^a[i];
    }
    for(int i=n;i>=1;i--) c[i]=c[i+1]^c[i];
    for(int i=1;i<=n;i++){
        bs=b[i];
        string s=bs.to_string();
        insert(s);
        d[i]=find(s);
    }
    memset(g,0,sizeof(g));
    idx=0;
    for(int i=n;i>=1;i--){
        bs=c[i];
        string s=bs.to_string();
        insert(s);
        e[i]=find(s);
        e[i]=max(e[i],e[i+1]);
    }
    for(int i=1;i<n;i++){
        ans=max(ans,d[i]+e[i+1]);
    }
    cout<<ans*2;
    for(int i=1;i<=n;i++) cerr<<e[i]<<" ";
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