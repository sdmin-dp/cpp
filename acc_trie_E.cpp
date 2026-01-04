#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
int g[N][20];
ll cnt[N];
string s;
ll idx=0;
ll t=1;
bool flag=1;
void insert(string &s){
    ll p=0;
    for(int i=0;i<s.size();i++){
        auto x=s[i]-'0';
        if(!g[p][x]) g[p][x]=++idx;
        if(cnt[p]){
            cout<<"Set "<<t<<" is not immediately decodable\n";
            flag=0;
            return;
        }
        p=g[p][x];
    }
    cnt[p]++;
}
void solve(){
    while(cin>>s){
        if(s=="9"){
            if(flag) cout<<"Set "<<t<<" is immediately decodable\n";
            t++;
            memset(g,0,sizeof(g));
            memset(cnt,0,sizeof(cnt));
            idx=0;
            flag=1;
            continue;
        }
        if(flag) insert(s);
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