#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e5+5;
ll n,m;
int g[N][5];
ll cnt[N],cnt2[N];
ll idx;
void insert(string &s){
    ll p=0;
    for(int i=0;i<s.size();i++){
        auto x=s[i]-'0';
        if(!g[p][x]) g[p][x]=++idx;
        p=g[p][x];
        cnt2[p]++;
    }
    cnt[p]++;
    cnt2[p]--;
}
ll find(string &s){
    ll p=0;
    ll res=0;
    for(int i=0;i<s.size();i++){
        auto x=s[i]-'0';
        if(!g[p][x]) return res;
        p=g[p][x];res+=cnt[p];
    }
    return cnt2[p]+res;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll si;
        cin>>si;
        string s;
        for(int j=1;j<=si;j++){
            ll x;
            cin>>x;
            s.push_back(char(x+48));
        }
        insert(s);
    }
    for(int i=1;i<=m;i++){
        ll si;cin>>si;
        string s;
        for(int j=1;j<=si;j++){
            ll x;cin>>x;
            s.push_back(char(x+48));
        }
        cout<<find(s)<<el;
    }
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