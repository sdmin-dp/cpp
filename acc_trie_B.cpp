#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
int g[N][10],cnt[N],idx,n;
bool insert(string &s){
    ll p=0;
    for(int i=0;i<s.size();i++){
        ll x=s[i]-'0';
        if(!g[p][x]) g[p][x]=++idx;
        else{
            if(i==s.size()-1) return 0;
        }
        if(cnt[p]) return 0;
        p=g[p][x];
    }
    cnt[p]++;
    return 1;
}
void solve(){
    cin>>n;
    memset(g,0,sizeof(g));
    memset(cnt,0,sizeof(cnt));
    idx=0;
    bool flag=0;
    while(n--){
        string s;
        cin>>s;
        if(flag==0&&insert(s)==0) flag=1;
    }
    if(flag) cout<<"NO"<<el;
    else  cout<<"YES"<<el;
}

int main() {
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("xxx.in","r",stdin);
    //freopen("xxx.out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}