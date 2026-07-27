#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n;
map<string,ll> mp;
pair<string,ll> mx;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        ll x;
        cin>>s>>s>>x;
        mp[s]+=x;
        if(i==1) mx={s,x};
        else{
            if(s==mx.first&&x<0){
                mx.second+=x;
                for(auto j:mp){
                    if(j.second>mx.second){
                        mx.first=j.first;
                        mx.second=j.second;
                    }else if(j.second==mx.second&&j.first<mx.first){
                        mx.first=j.first;
                        mx.second=j.second;
                    }
                }
            }
            else if(mp[s]>mx.second){
                mx.first=s;
                mx.second=mp[s];
            }else if(mp[s]==mx.second&&s<mx.first){
                mx.first=s;
                mx.second=mp[s];
            }
        }
        cout<<mx.first<<" "<<mx.second<<el;
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