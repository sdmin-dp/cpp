#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll x,y,q;
multiset<ll> st;
void solve(){
    cin>>x>>q;
    st.insert(x);
    auto it=st.begin();
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        st.insert(x);st.insert(y);
        // auto it=st.begin();
        if(x<*it&&y<*it) advance(it,-1);
        else if(x>*it&&y>*it) advance(it,1);
        cout<<*it<<el;
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