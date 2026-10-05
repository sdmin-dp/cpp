#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll n,m;
multiset<ll> st;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        ll x;cin>>x;
        st.insert(x);
    }
    for(int i=1;i<=m;i++){
        ll x;cin>>x;
        auto it=st.lower_bound(x);
        if(it==st.end()) cout<<-1<<" ";
        else{
            cout<<*it<<" ";
            st.erase(it);
        }
    }
    cout<<el<<st.size();
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("keys.in","r",stdin);
    freopen("keys.out","w",stdout);
    ll T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}