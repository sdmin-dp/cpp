#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e3+5;
ll num(char c){return c-'a'+1;}
ll n;
string s[N];
vector<pair<string,ll>> g[35];
ll in[N],out[N];
ll idx[N];
ll start;
deque<string> ans;
void dfs(ll x){
    while(idx[x]<g[x].size()){
        string v=g[x][idx[x]].first;
        ll u=g[x][idx[x]].second;
        idx[x]++;
        dfs(u);
        ans.push_front(v);
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        g[num(s[i][0])].push_back({s[i],num(s[i][s[i].size()-1])});
        in[num(s[i][s[i].size()-1])]++;
        out[num(s[i][0])]++;
    }
    for(int i=1;i<=26;i++){
        cerr<<i+'a'-1<<":";
        for(auto j:g[i]){
            cerr<<j.second<<",";
        }
        cerr<<el;
    }
    ll cnt1=0,cnt2=0,cnt3=0,id=0,id2=1e9+7;
    for(int i=1;i<=26;i++){
        if(g[i].size()>=1&&i<id2) id2=i;
        if(in[i]-out[i]==1) cnt1++;
        else if(out[i]-in[i]==1){
            cnt2++;
            id=i;
        }
        else if(out[i]==in[i]) cnt3++;
    }
    // cerr<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<id<<" "<<id2;
    if(cnt1==1&&cnt2==1&&cnt3+cnt2+cnt1==n) start=id;
    else if(cnt1==0&&cnt2==0&&cnt3==n) start=id2;
    else{
        cout<<"***";
        return;
    }
    for(int i=1;i<=n;i++){
        sort(g[i].begin(),g[i].end());
    }
    dfs(start);
    cout<<ans[0];
    for(ll i=1;i<ans.size();i++){
        cout<<"."<<ans[i];
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