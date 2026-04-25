#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define el '\n'
const ll N=1e5+5;
ll n;
map<ll,string> mp;
bool isnum(char c){
    return (c>='0'&&c<='9');
}
vector<pair<ll,ll>> v;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll x;string s;
        cin>>x;
        cin>>s;
        mp[x]=s;
    }
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(!isnum(s[i])) continue;
        ll x=0;
        ll len=0;
        while(i<s.size()&&isnum(s[i])){
            x=x*10+int(s[i]-48);
            i++;
            len++;
        }
        v.push_back({x,len});
    }
    ll cnt=0;
    for(int i=0;i<s.size();i++){
        if(i=='#'){
            cout<<v[cnt++].first;
            i+=v[cnt].second;
        }else{
            cout<<s[i];
        }
    }
    cout<<s;
    cout<<v.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}