#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=1e5+5;
ll n,a[N],b[N];
set<ll> st;
unordered_map<ll,ll> mp;
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
    ll k=1;
    for(auto i:st){
        mp[i]=k++;
    }
    for(int i=1;i<=n;i++){
        b[i]=mp[a[i]];
        cout<<b[i]<<" ";
    }
    
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("xxx.in","r",stdin);
    // freopen("xxx.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}