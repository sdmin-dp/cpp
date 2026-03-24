#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define el '\n'
const ll N=1e5+5;
set<ll> st;
void solve(){
    st.insert(5);
    st.insert(4);
    st.insert(3);
    st.insert(2);
    st.insert(1);
    for(auto i:st){
        cout<<i<<" ";
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