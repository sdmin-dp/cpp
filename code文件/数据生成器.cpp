#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=2e5+5;
const ll mod=1e9+1;
ll n;
map<ll,multiset<ll>> mp;
mt19937 rd(time(0));
void solve(){
    n=N;
    for(int i=1;i<=n;i++){
        ll op;
        op=rd()%3;
        if(op==0) op=3;
        cout<<op<<" ";
        if(op==1){
            ll c,p;
            c=max(1ull,rd()%mod),p=max(1ull,rd()%mod);
            mp[c].insert(p);
            cout<<c<<" "<<p<<el;
        }else if(op==2){
            ll c,p;
            c=max(1ull,rd()%mod);
            p=*mp[c].begin();
            cout<<c<<" "<<p<<el;
        }else{
            ll c;
            c=min(1ull,rd()%mod);
            cout<<c<<el;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("route.in","r",stdin);
    // freopen("route.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}