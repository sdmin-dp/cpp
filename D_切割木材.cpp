#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el '\n'
const ll N=1e5+5;
ll line,n;
set<ll> st;
void solve(){
    cin>>line>>n;
    st.insert(0);st.insert(line);
    for(int i=1;i<=n;i++){
        ll op,x;
        cin>>op>>x;
        if(op==1){
            st.insert(x);
        }else{
            auto t=st.upper_bound(x);
            ll r=*t;
            t--;
            ll l=*t;
            cout<<r-l<<el;
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