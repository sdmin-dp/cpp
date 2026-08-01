#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
// const ll N=1e5+5;
ll n;
map<string,multiset<ll>> st;
multiset<pair<ll,string>> st2;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll op;
        cin>>op;
        if(op==1){
            string s;
            ll x;
            cin>>s;cin>>x;
            st2.insert({x,s});
            st[s].insert(x);
        }else if(op==2){
            string s;
            ll x;
            cin>>s;cin>>x;
            auto pos=st[s].find(x);
            auto pos2=st2.find({x,s});
            if(pos==st[s].end()||pos2==st2.end()) continue;
            st[s].erase(pos);st2.erase(pos2);
        }else if(op==3){
            string s;
            cin>>s;
            if(st[s].empty()){
                cout<<"EMPTY"<<el;
                continue;
            }
            cout<<st[s].size()<<" "<<*st[s].begin()<<" "<<*st[s].rbegin()<<el;
        }else{
            if(st2.empty()){
                cout<<"EMPTY"<<el;
                continue;
            }
            auto t=*st2.begin();
            cout<<t.second<<" "<<t.first<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("market.in","r",stdin);
    freopen("market.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}