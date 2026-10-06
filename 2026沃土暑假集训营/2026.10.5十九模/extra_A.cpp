#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
void bigtosmall(string &s){
    for(auto &i:s)
        if('A'<=i&&i<='Z')
            i-='A',i+='a';
}
map<string,pair<ll,ll>> mp;
map<string,ll> id;
void solve(){
    cin>>n;
    cin.ignore();
    ll idx=0;
    for(int i=1;i<=n;i++){
        string s;
        getline(cin,s);
        bigtosmall(s);
        s.push_back('.');
        for(int j=0;j<s.size();j++){
            string t="";
            ll cnt2=0;
            while((s[j]>='0'&&s[j]<='9')||(s[j]>='a'&&s[j]<='z')){
                t.push_back(s[j]);
                if((s[j]>='0'&&s[j]<='9')) cnt2++;
                j++;
            }
            if(t=="") continue;
            if(cnt2==t.size()){
                reverse(t.begin(),t.end());
                while(t.size()>1&&t[t.size()-1]=='0') t.pop_back();
                reverse(t.begin(),t.end());
            }
            // cerr<<t<<el;
            mp[t].first++;
            if(id.count(t)==0){
                id[t]=++idx;
            }
            if(mp[t].second==0) mp[t].second=i;
        }
    }
    string mx;
    ll ans=0;
    for(auto i:mp){
        ans++;
        if(mp[mx].first<i.second.first) mx=i.first;
        else if(mp[mx].first==i.second.first&&id[i.first]<id[mx]) mx=i.first;
    }
    cout<<ans<<el<<mx<<el<<mp[mx].first<<" "<<mp[mx].second;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    ll T=1;
    // cin>>T;
    while(T--){
        solve();
    }
    return 0;
}