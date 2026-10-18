#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=20+5;
ll n,m;
map<string,ll> mp;
map<ll,string> remp;
vector<ll> g[N];
ll idx;
void solve(){
    idx=0;
    mp.clear();
    remp.clear();
    n=0,m=0;
    for(int i=1;i<=20;i++) g[i].clear();
    cin>>m;
    for(int i=1;i<=m;i++){
        string s,t;
        cin>>s>>t;
        if(mp[s]==0){
            mp[s]=++idx;
            remp[idx]=s;
        }
        if(mp[t]==0){
            mp[t]=++idx;
            remp[idx]=t;
        }
        g[mp[s]].push_back(mp[t]);
    }
    n=idx;
    for(int i=1;i<=n;i++){
        if(g[i].size()==1){
            for(auto j:remp[i]){
                if(!(('a'<=j&&j<='z')||('A'<=j&&j<='Z'))){
                    cout<<"no"<<el;
                    return;
                }
            }
            string tmp=remp[g[i][0]].substr(0,remp[g[i][0]].size()-4);
            string s=remp[g[i][0]];
            if(!(tmp==remp[i]&&s[s.size()-1]=='p'&&s[s.size()-2]=='p'&&s[s.size()-3]=='c'&&s[s.size()-4]=='.')){
                cout<<"no"<<el;
                return;
            }
        }else if(g[i].size()==4){
            ll fj=-1;
            for(ll j=0;j<remp[i].size();j++){
                if('0'<=remp[i][j]&&remp[i][j]<='9'){
                    fj=j;
                    break;
                }
            }
            if(fj==-1||fj==0){
                cout<<"no"<<el;
                return;
            }
            for(int j=0;j<fj;j++){
                if(!(('a'<=remp[i][j]&&remp[i][j]<='z')||('A'<=remp[i][j]&&remp[i][j]<='Z'))){
                    cout<<"no"<<el;
                    return;
                }
            }
            for(int j=fj;j<remp[i].size();j++){
                if(!('0'<=remp[i][j]&&remp[i][j]<='9')){
                    cout<<"no"<<el;
                    return;
                }
            }
        }
        else if(g[i].size()!=0){
            // cerr<<remp[i]<<" "<<g[i].size()<<el;
            cout<<"no"<<el;
            return;
        }
    }
    cout<<"yes"<<el;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}