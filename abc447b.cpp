#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
string s;
map<char,ll> mp;
vector<pair<char,ll>> v;
map<char,bool> mp2;
bool cmp(pair<ll,ll> x,pair<ll,ll> y){
    return x.second>y.second;
}
void solve(){
    cin>>s;
    for(auto i:s){
        mp[i]++;
    }
    for(auto i:mp) v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        cerr<<v[i].first<<" "<<v[i].second<<el;
    }
    ll last=v[0].second;
    
    for(int i=1;i<v.size();i++){
        if(v[i].second!=last){
            break;
        }
        last=v[i].second;
        mp2[v[i].first]=1;
    }
    for(auto i:s){
        if(mp2[i]!=1){
            cout<<i;
        }
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