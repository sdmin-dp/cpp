#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=5e4+5;
ll n;
vector<ll> g[N];
char last=' ';
map<char,ll> mp1;
map<ll,char> mp2;
ll in[N];
ll id[N];
ll idx;
void topsort(){
    queue<ll> q;
    for(int i=1;i<=26;i++) if(!in[i]) q.push(i);
    while(!q.empty()){
        ll t=q.front();
        q.pop();
        id[t]=++idx;
        for(auto i:g[t]) if(--in[i]==0) q.push(i);
    }
}
void solve(){
    for(int i=0;i<26;i++){
        mp1[char(i+'a')]=i+1;
        mp2[i+1]=char(i+'a');
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        if(last==s[0]) continue;
        if(last!=' ') g[mp1[last]].push_back(mp1[s[0]]);
        last=s[0];
        in[mp1[s[0]]]++;
    }
    topsort();
    string s;
    cin>>s;
    for(auto i:s){
        //先找到这个点的大小
        //然后，1对应a,2对应b...
        ll j=id[mp1[i]];
        //j+'a'-1,
        cout<<j<<" ";
    }
    for(int i=1;i<=26;i++) cerr<<id[i]<<" ";
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